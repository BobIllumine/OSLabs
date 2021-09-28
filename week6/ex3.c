#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	int arrival_time;
	int burst_time;
} process_info;

typedef struct {
	int remaining;
	char status; // 0 - on run, 1 - waiting, 2 - finished
} exec_status;

typedef struct {
	int ct;
	int tat;
	int wt;
} exec_info;

void round_robin(int n, int quantum, int max_time, process_info *process, exec_info **info, float *atm, float *awt) {
	exec_status *stats = (exec_status*)calloc(n, sizeof *stats);
	*info = (exec_info*)calloc(n, sizeof(exec_info));
	for(int i = 0; i < n; ++i) // initiating remaining time
		stats[i].remaining = process[i].burst_time;
	int now = 0, next = quantum - 1;
	for(int tick = 0; tick <= max_time; ++tick) {
		if(tick > 0)
			stats[now].remaining--;
		if(tick == next || stats[now].remaining == 0) {
			if(stats[now].remaining == 0)
				stats[now].status = 2, (*info)[now].ct = tick;
			else
				stats[now].status = 1;
			int tmp = 0;
			do {
				++tmp;
				now = (now + 1) % n;
			} while(stats[now].status == 2 && tmp <= n);
			next = tick  + quantum;
		}
		for(int i = 0; i < n; ++i)
			if(process[i].arrival_time <= tick && now != i && stats[i].status == 2)
				++(*info)[i].wt;
	}
	for(int i = 0; i < n; ++i) { // calculating total values
		(*info)[i].tat = process[i].burst_time + (*info)[i].wt;
		*atm += (*info)[i].tat;
		*awt += (*info)[i].wt;
	}

	*atm /= (float)n;
	*awt /= (float)n;
	free(stats);
}

int main(int argc, char **argv) {
	int n, q; float atm = 0, awt = 0;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	printf("Enter the quantum: ");
	scanf("%d", &q); 
	process_info *pinfo = (process_info*)calloc(n, sizeof(process_info));
	exec_info *results = NULL;
	for(int i = 0; i < n; ++i) {
		printf("Arrival time of #%d process: ", i + 1);
		scanf("%d", &pinfo[i].arrival_time);
		printf("Burst time of #%d process: ", i + 1);
		scanf("%d", &pinfo[i].burst_time);
	}
	round_robin(n, q, 30, pinfo, &results, &atm, &awt);
	printf("P#\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i = 0; i < n; ++i)
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, pinfo[i].arrival_time, pinfo[i].burst_time, results[i].ct, results[i].tat, results[i].wt);
	printf("Average Turnaround Time: %f\n", atm);
	printf("Average Waiting Time: %f\n", awt);
	return 0;
}
