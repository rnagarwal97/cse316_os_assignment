/* 

Ques.
 Consider a scenario of demand paged memory. Page table is held in registers. It takes 8 milliseconds
 to service a page fault if an empty page is available or the replaced page is not modified and 20 milliseconds
 if the replaced page is modified. Memory access time is 100 nanoseconds. Assume that the page to be replaced is
 modified 70 percent of the time. Generate a solution to find maximum acceptable page-fault rate for access time
 that is not more than 200 nanoseconds.
 
*/


#include<stdio.h>
#include<stdlib.h>

int main(){
	
	// informations given in problem statement
	double pfst_nonmodified = 8000000; // page fault service time for modified page in ns
	double pfst_modified = 20000000; // // page fault service time for non modified page in ns
	double mem_acc_time = 100; // memory access time in ns
	double eff_acc_time = 200; // effective access time in ns
	
	double modified_pg = 0.7; // percentage of page replaced is modified
	
	// Formula
	// Effective Access Time = [Page Fault Rate * (Page Fault Service Time)] + [(1-Page Fault Rate) * Memory Access Time]
	
	// Page Fault Rate = ( Effective Access Time - Memory Access Time ) / ( Page Fault Service Time - Memory Access Time )
	
	double total_pfst = (modified_pg * pfst_modified) + ((1 - modified_pg) * pfst_nonmodified);
	double eat_minus_mat =  eff_acc_time - mem_acc_time;
	double tpsft_minus_mat = total_pfst - mem_acc_time;
	double page_fault_rate = eat_minus_mat/tpsft_minus_mat;
	
	// printing results
	printf("Page fault service time for non modified page: %.2lf\n", pfst_nonmodified);
	printf("Page fault service time for modified page: %.2lf\n", pfst_modified);
	printf("Memory Access Time: %.2lf\n", mem_acc_time);
	printf("Effective Access Time %.2lf\n", eff_acc_time);
	printf("Modified Page Percentage: %.2lf\n", modified_pg);
	printf("----------------------------------------------\n");
	
	printf("Maximum page fault rate = %lf\n",page_fault_rate);
		
}
