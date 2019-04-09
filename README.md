# cse316_os_assignment
Solution to simulation based assignment for course code CSE316.

# About me
Name - Aryan Agarwal

Section - K17SM

Reg no. - 11707334

Roll no. - 48

Assigned question - 14,21 

# Program 1 -
Ques. Write a program to implement priority scheduling algorithm with context switching time. Prompt to user to enter the number of processes and then enter their priority, burst time and arrival time also. Now whenever operating system preempts a process and shifts cpu’s control to some another process of higher priority assume that it takes 2 seconds for context switching (dispatcher latency). Form a scenario, where we can give the processes which are assigned with priority where the lower integer number is higher priority and then context switch .. as the process waits the priority of the process increase at rate of one per 2 time units of wait.
Calculate waiting time and turnaround time for each process.

Solution - 
> priority_scheduling.c

# Program 2 - 
Ques. Consider a scenario of demand paged memory. Page table is held in registers. It takes 8 milliseconds to service a page fault if an empty page is available or the replaced page is not modified and 20 milliseconds if the replaced page is modified. Memory access time is 100 nanoseconds. Assume that the page to be replaced is modified 70 percent of the time. Generate a solution to find maximum acceptable page-fault rate for access time that is not more than 200 nanoseconds.

Solution - 
> demandpagemem.c
