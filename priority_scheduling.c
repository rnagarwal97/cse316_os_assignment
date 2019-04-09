#include<stdio.h>
#include<stdlib.h>

struct process{
	int id;
	int priority;
	int arrival_time;
	int burst_time;
	int timer;
	int wait;
	int tat;
};

int n; // number of process

typedef struct process process;

// search highest priority process
int h_p(process pr[], int n){
    int i;
    int hpv = 99999; // fix this
    int hp = -1;
    
    for(i=0; i<n; i++){
    	if(pr[i].burst_time == 0)
    		continue;
    	
    	if(pr[i].priority < hpv){
    		hpv = pr[i].priority;
    		hp = i;
		}
		else if(pr[i].priority == hpv){
			if(i < hp){
				hp = i;
			}
		} 
	}
    
    return hp;
}

// for every time unit we are updating process state
void update_process(process a[],int n,int rp){
    int i;
    for(i=0; i<n; i++){
        if(a[i].burst_time == 0){
        	continue;
        }
        
        if(i!=rp){
            a[i].wait++;
            if(a[i].timer>0){
                a[i].timer--;
            }
            else{
                a[i].timer = 1;
                a[i].priority -= 1;
                if(a[i].priority < 0)
                    a[i].priority = 0;
            }
        }
        else if(i == rp){
            a[i].burst_time--;
        }
        
    }
}

// counting number of process finished execuing
int count_done_process(process a[],int n){
    int i;
    int c=0;
    for(i=0; i<n; i++){
        if(a[i].burst_time == 0){
            c++;
        }
    }
    return c;
}


int main(){


	// asking user to enter number of process
	printf("Enter number of process: ");
	scanf("%d",&n);

	struct process p[n];
	int i;

	// getting priority, arrival time and burst time of processes from user
	for(i=1; i<=n; i++){
		p[i-1].id = i;
		p[i-1].timer = 2;
		p[i-1].wait = 0;
		p[i-1].tat = 0;
		printf("Enter arrival time of the process %d: ",i);
		scanf("%d",&p[i-1].arrival_time);
		printf("Enter priority of process %d: ",i);
		scanf("%d",&p[i-1].priority);
		printf("Enter burst time of process %d: ",i);
		scanf("%d",&p[i-1].burst_time);
		p[i-1].tat = p[i-1].burst_time;
	}

	// sorting processes according to arrival time
	int j;
	struct process temp;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(p[j].arrival_time > p[j+1].arrival_time){
				temp = p[j];
				p[j]= p[j+1];
				p[j+1] = temp;
			}
		}
	}


	struct process curr[n];
	int clock = 0;
    int p_cur = 0;
    int c_cur = 0;
    int rp = -1;
    int dp = 0;
    int pp;
    
    // while every process has not arrived and every process have not finished execution
	while(p_cur < n || dp!=n){

            // adding process from p to curr when clock <= arrival_time
            while(p_cur < n && p[p_cur].arrival_time <= clock){
                curr[c_cur] = p[p_cur];
                p_cur++;
                c_cur++;
            }


            pp = h_p(curr, c_cur); // pp holds process with highest priority
			
			
			// adding dispatcher latency of 2 time unit when there is context switching
            if(rp == -1 || rp == pp){
                rp = pp;
                clock++;
                update_process(curr,c_cur,rp);
            }
            else{
                clock +=2;
                rp = pp;
                update_process(curr,c_cur,-1);
                update_process(curr,c_cur,-1);
                update_process(curr,c_cur,rp);
            }

            dp = count_done_process(curr, c_cur); // updating done counter


	}

	// displaying final results
    for(i=0; i<n; i++){
                curr[i].tat += curr[i].wait;
                printf("process id=%d, wait time=%d, tat time=%d\n",curr[i].id,curr[i].wait,curr[i].tat);
            }

}

