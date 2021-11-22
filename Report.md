# REPORT

## IMPLEMENTATION OF syscall tracing

* A system call trace was implemented that intercepts and records the system calls which are called by a process during its execution till that specific command exits.

* A system call SYS_trace was define with number 23 in the syscall.h and it was added as a prototype and included in list of systemcalls in syscall.c


* The following code has been added to the files indicated.

```
- Makefie - UPROGS
$U/_strace

- kernel/sysproc.c
uint64 
sys_trace(void) {
    int mask = 0;
    if (argint(0, &mask) < 0)
      return -1;
    myproc()->mask = mask;
    return 0;
}

- kernel/syscall.c

void syscall(void) //any system called will come here
{
  int num;
  struct proc *p = myproc();

  num = p->trapframe->a7;
  // int store=p->trapframe->a0; //storing it before hand

  if (num > 0 && num < NELEM(syscalls) && syscalls[num])
  {
    p->trapframe->a0 = syscalls[num]();
    int mask = p->mask;
    
    if (mask != 0)
    {
      if ((mask >> num) & 1)
      {
        printf("%d: syscall %s %d\n", p->pid, system_call_name[num], p->trapframe->a0,p->trapframe->a1);
      }
    }
  }
  else
  {
    printf("%d %s: no such system call %d\n", p->pid, p->name, num);
    p->trapframe->a0 = -1;
  }
}


-kernel/proc.c
 In fork() the following line was added np->mask = p->mask

- user/user.h
int trace(int);   // add

- user/strace.c --- make new file

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include <stddef.h>


int main(int argc, char *argv[])
{
    int pid = fork();
    if(pid<0)
    {
     printf("Fork failed!\n");
    }
    else if(pid==0)
    {
     trace(atoi(argv[1]));
     if(exec(argv[2],argv+2)<0)
     printf("my error in exec\n");
   }
   else
   {
       int status;
       wait(&status);
   }
   exit(0);
}

- syscall.h
#define SYS_trace  22
```

### IMPLEMENTATION OF PROC-DUMP

* The following is the code for procdump:

```
void procdump(void)
{
  static char *states[] = {
      [UNUSED] "unused",
      [SLEEPING] "sleeping",
      [RUNNABLE] "runnable",
      [RUNNING] "runing",
      [ZOMBIE] "zombie"};
  struct proc *p;
  char *state;

  printf("\n\tPID\tPriority\tstate\trtime\twtime\tnrun\n\n");

  for (p = proc; p < &proc[NPROC]; p++)
  {
    if (p->state == UNUSED)
      continue;
    if (p->state >= 0 && p->state < NELEM(states) && states[p->state])
      state = states[p->state];
    else
      state = "???";

    #if SCHEDULER==RR | SCHEDULER == FCFS
    printf("%d %s %s", p->pid, state, p->name);
    printf("\n");
    #elif SCHEDULER==PBS
    int wait=p->etime-p->rtime-p->ctime;
    printf("\t%d\t%d\t%s\t%d\t%d\t%d\n",p->pid,dp(p),p->state,p->rtime,wait,p->num);

    #elif SCHEUDLER==MLFQ
    printf("");
    #endif
    
  }
  
}
```

### MY Benchmark values:

RR - Average rtime 18, wtime 133
FCFS - Average rtime 42, wtime 87
PBS - Average rtime 22, wtime 118


## MLFQ Question

* If a process leaves the CPU control on it's own for some I/O or something else,then the number of timer ticks it was executed by CPU is noted down in the struct proc and while adding back the process when it's state changes to runnable the timer ticks is checked if the value is less than the assigned timer ticks and it came back to priority que again this means that either it exited or gave CPU on it's own.If the process didn't exit that means it gave control on it's own so with the exit flag we can find that and add again at the end of que using the push function in the code.


## NOTE:

* For some reason my code behaves too wierd and it acts abnormally,like adding even a little space to proc.c or proc.h would give errors and traps while compiling.I was not able to find the reason though I tried it a lot.I tried to implement MLFQ but due this problem the code was uncommented and my work for implementing MLFQ can be seen in functions push,pop,pop_off,update_time,yiled() where all lines of code are uncommented.
