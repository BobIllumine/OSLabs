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

void shortest_work_first(int n, int max_time, process_info *process, exec_info **info, float *atm, float *awt) {
	int now = -1;
	exec_status *stats = (exec_status*)calloc(n, sizeof *stats);
	*info = (exec_info*)calloc(n, sizeof(exec_info));
	for(int tick = 0; tick <= max_time; ++tick) {
		if(now != -1) // process running
			stats[now].remaining--;
		if(!stats[now].remaining) // on completion
			(*info)[now].ct = tick, stats[now].status = 2, now = -1;
		if(now == -1) { // CPU is free
			int tmp = -1;
			for(int i = 0; i < n; ++i) // looking for a process with the least burst time
				if(process[i].arrival_time <= tick && stats[i].status != 2)
					tmp = (tmp == -1 || (tmp != -1 && process[i].burst_time < process[tmp].burst_time) ? i : tmp);
			now = tmp;
			if(now < n && now >= 0) // checking boundaries
				stats[now].status = 0, stats[now].remaining = process[now].burst_time;
		}
		for(int i = 0; i < n; ++i) // calculating waiting time
			if(process[i].arrival_time <= tick && now != i && stats[i].status != 2)
				stats[i].status = 1, ++(*info)[i].wt;
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
	printf("Enter the number of processes: ");
	int n; float atm = 0, awt = 0;
	scanf("%d", &n);
	process_info *pinfo = (process_info*)calloc(n, sizeof(process_info));
	exec_info *results = NULL;
	for(int i = 0; i < n; ++i) {
		printf("Arrival time of #%d process: ", i + 1);
		scanf("%d", &pinfo[i].arrival_time);
		printf("Burst time of #%d process: ", i + 1);
		scanf("%d", &pinfo[i].burst_time);
	}
	shortest_work_first(n, 30, pinfo, &results, &atm, &awt);
	printf("P#\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i = 0; i < n; ++i)
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, pinfo[i].arrival_time, pinfo[i].burst_time, results[i].ct, results[i].tat, results[i].wt);
	printf("Average Turnaround Time: %f\n", atm);
	printf("Average Waiting Time: %f\n", awt);
	return 0
}
