# Functions Added to XV6 
- waitx
- time
- set_priority
- setpriority
- strace
- Scheduling Algorithms
    - FCFS
    - PBS
- procdump

# description of the functions added 
1. waitx()
    - This is implemented by modifing the pre-existing wait().
    - It clauclates rtime, wtime, ctime.
    - rtime is caluclated by incrementing it each time ticks is incremented and wtime is caluclated by *wtime = np->etime - np->ctime - np->rtime;
    
2. time
    - User defined function.
    - To check waitx system call

3. set_priority
    - System Call
    - To change the static priority of process in PBS scheduling
    - Returns Old Static Priority of a process.

4. setpriority
    - User defined function
    - Uses above system call to change the priority .
    - Takes system call arguments as command line arguments.

5. strace
    A system call trace was implemented that intercepts and records the system calls which are called by a process during its execution till that specific command exits.

    * A system call SYS_trace was define with number 23 in the syscall.h and it was added as a prototype and included in list of systemcalls in syscall.c

6. Scheduling Algorithms
    - FCFS
        - Selects the proccess that is runnable and which contains minimum creation time.
    - PBS 
        - Selects the proccess that is runnable and which contains high priority(low value).

7. procdump()
    - Prints a list of processes to the console when user types Ctrl-p on the console.
    - prints pid, priority, state, rtime, wtime, nrun info of the active process.
