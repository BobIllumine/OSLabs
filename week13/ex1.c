//
// Created by hered on 16.11.2021.
//
#include <stdio.h>
#define N 5
#define M 3
typedef struct {
    int C[M];
    int R[M];
    int pid;
    int status;
} process;

process p[N];
int E[M];
int A[M];

int check() {
    for(int i = 0; i < N; ++i) {
        if(p[i].status == 1)
            continue;
        int ok = 1;
        for(int j = 0; j < M; ++j)
            if(p[i].R[j] > A[j]) {
                ok = 0;
                break;
            }
        if(ok)
            return i;
    }
    return -1;
}

void clear(int id) {
    for(int i = 0; i < M; ++i) {
        A[i] += p[id].C[i];
        p[id].C[i] = p[id].R[i] = 0;
        p[id].status = 1;
    }
}

void print(int status) {
    printf(status ? "\nResult:\n\n" : "\nState:\n\n");
    printf("E: {");
    for (int j = 0; j < M; ++j) {
        printf("%d", E[j]);
        printf(j == M -1 ? ")\n" : ", ");
    }
    printf("A: (");
    for (int j = 0; j < M; ++j) {
        printf("%d", A[j]);
        printf(j == M - 1 ? "}\n" : ", ");
    }

    for (int i = 0; i < N; ++i) {
        printf("Process #%d ", p[i].pid);
        if (status) {
            if (p[i].status == 0) {
                printf("is in dead lock\n");
            } else {
                printf("is terminated\n");
            }
        } else {
            if (p[i].status == 0) {
                printf("is in progress. Requires: (");
                for (int j = 0; j < M; ++j) {
                    printf("%d", p[i].R[j]);
                    printf(j == M - 1 ? ")\n" : ", ");
                }
            } else {
                printf("is terminated\n");
            }
        }
    }
}

int main(int argc, char **argv) {
    FILE *in = fopen("input_dl.txt", "r");
    for(int i = 0; i < M; ++i)
        fscanf(in, "%d", &E[i]);
    for(int i = 0; i < M; ++i)
        fscanf(in, "%d", &A[i]);
    for(int i = 0; i < N; ++i) {
        p[i].pid = i;
        p[i].status = 0;
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            fscanf(in, "%d", &p[i].C[j]);
        }
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            fscanf(in, "%d", &p[i].R[j]);
        }
    }
    while(1) {
        print(0);
        int proc = check();
        if(proc == -1)
            break;
        clear(proc);
    }
    print(1);
    return 0;
}
