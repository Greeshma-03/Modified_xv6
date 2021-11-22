Quick guide for people trying to set stuff up:

1. The version of the kernel we need to work on is designed for rv64 systems. Our systems are x86 (stuff we learnt in CSO), The standard gcc compiler and build tools compile programs for x86 machines. So we need to first install the rv64 version of the tools to compile xv6. The install commands are given in the doc. Do NOT sudo make everything from scratch. It's available as packages for your distro. DO NOT SCROLL BELOW Installing on Arch

2. The Makefile contains a lot of useful commands. Just make will compile the files. make qemu will compile and launch the xv6 kernel on the qemu hypervisor layer. To quit, press Ctrl + A then press X after that.

3. make qemu-gdb is useful for debugging. It will launch the kernel and pause execution on the first instruction in the kernel machine code. It then sets up a port for gdb to connect to. Open another terminal window, navigate to the same directory and run gdb. By gdb I mean the rv64 version. So riscv64-linux-gnu-gdb It will try to import some config data from the .gdbinit file. Usually it'll throw an error. But it'll tell you exactly what to do to fix it. Just follow the steps it tells you to do and run gdb again, it'll attach onto the instance of the kernel. Then run b exec, c a couple times and you'll be able to step through the code. You won't be able to do next on the first instruction btw, breakpoint and continue to some known function first. 

Important v 
4. gdb probably won't be able to print stuff due to a bug in gcc10/11 and gdb. Downgrade the rv64 version of gcc to 8 or something. Then it'll work like you expect it to. @Abhijnan found this link for arch, https://archive.archlinux.org/packages/r/riscv64-linux-gnu-gcc/




https://cheddar-expansion-bea.notion.site/CS3-301-Operating-Systems-and-Networks-Autumn-2021-Doubts-Document-9def31e57c9b41779f574bfc7052886e



But a few places to start ig.
1. If you don't understand the codebase you won't be able to do this assign. I (think) the coding part is pretty small, understanding the codebase will take longer. Just reading and understanding what different parts do will help a lot. 
2. Remzi discussion videos are great and walk you through what different parts of the kernel code do. 
https://www.youtube.com/watch?v=vR6z2QGcoo8
https://www.youtube.com/watch?v=eYfeOT1QYmg
3. Check the hints given, they pretty much tell you (almost) everything you need to do. Especially for part 1. 
4. grep is very useful in navigating the codebase, if you don't know where some definition is and your IDE isn't cool enough to locate it, grep will find it for you thumbsup




https://github.com/Groverkss/IIIT-Courses-Resources/tree/main/Operating-Systems-and-Networks#xv6-resources


https://programmer.ink/think/mit6.s081-lab2-system-calls.html


Add mit warehouse Add remote git remote add mit git://g.csail.mit.edu/xv6-labs-2020 Pull branch from mit git fetch mit git checkout syscall chapter 2 System call tracing Write a program to track the system call called by another program, print the syscall num and syscall num of the tracked syscUTF-8...

https://www.geeksforgeeks.org/xv6-operating-system-adding-a-new-system-call/

