//
// Created by hered on 18.10.2021.
// Hit or miss, i guess they never miss, huh...
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int id;
    uint bits;
} page;

int main(int argc, char **argv) {
    int N;
    printf("Number of pages: ");
    scanf("%d", &N);
    FILE *input = fopen("../week9/input.txt", "r");
    page *table = (page*) calloc(N, sizeof(page));
    for(int i = 0; i < N; ++i)
        table[i].id = -1;
    uint requested = 0, hit = 0, miss = 0;
    while(fscanf(input, "%d", &requested) == 1) {
        char in = 0;
        // checking if in the table
        for(int i = 0; i < N; ++i)
            if(table[i].id == requested) {
                ++hit; in = 1;
                break;
            }
        if(!in) {
            char slot = 0;
            // looking for unused slot
            for(int i = 0; i < N; ++i)
                if(table[i].id == -1) {
                    table[i].id = requested; table[i].bits = 0;
                    slot = 1;
                    break;
                }
            if(!slot) {
                // getting the least recently used
                uint min_bits = INT_MAX, min_idx = INT_MAX;
                for(int i = 0; i < N; ++i)
                    if(min_bits > table[i].bits) {
                        min_bits = table[i].bits;
                        min_idx = i;
                    }
                table[min_idx].bits = min_bits;
                table[min_idx].id = requested;
            }
            ++miss;
        }
        for(int i = 0; i < N; ++i) {
            table[i].bits >>= 1;
            // we have 32-bit unsigned integer for counter, so we need to put a bit into 31st position (0-indexing)
            if(in && table[i].id == requested) {
                table[i].bits |= (1 << 31);
            }
        }
    }
    printf("Hits: %u\n", hit);
    printf("Misses: %u\n", miss);
    printf("Hit/miss ratio: %f\n", (float)hit / (float)miss);
    fclose(input);
    free(table);
    return 0;
}