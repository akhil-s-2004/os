#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 25

void WorstFit(int num_blocks, int num_proc, int block_sizes[], int process_sizes[]) {
    int i, j;
    int fragment[MAX_BLOCKS], block_allocated[MAX_BLOCKS], block_index[MAX_BLOCKS];
    for (i = 0; i < num_blocks; i++) {
        block_allocated[i] = 0;
    }

    int temp;
    for (i = 0; i < num_proc; i++) {
        int highest = -1;
        for (j = 0; j < num_blocks; j++) {
            if (block_allocated[j] != 1) {
                temp = block_sizes[j] - process_sizes[i];
                if (temp >= 0 && temp > highest) {
                    block_index[i] = j;
                    highest = temp;
                }
            }
        }
        fragment[i] = highest;
        if (highest != -1) {
            block_allocated[block_index[i]] = 1;
        } else {
            block_index[i] = -1;
        }
    }
    printf("\nWorst Fit\n");
    printf("Process_no:\tProcess_size:\tBlock_no:\tBlock_size:\tFragment\n");
    for (i = 0; i < num_proc; i++) {
        if (block_index[i] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, process_sizes[i], block_index[i] + 1, block_sizes[block_index[i]], fragment[i]);
        } else {
            printf("%d\t\t%d\t\t-1\t\t-1\t\t-1 (No suitable block)\n", i + 1, process_sizes[i]);
        }
    }
}

void BestFit(int num_blocks, int num_proc, int block_sizes[], int process_sizes[]) {
    int i, j;
    int fragment[MAX_BLOCKS], block_allocated[MAX_BLOCKS], block_index[MAX_BLOCKS];
    for (i = 0; i < num_blocks; i++) {
        block_allocated[i] = 0;
    }

    int temp;
    for (i = 0; i < num_proc; i++) {
        int best_fit_index = -1;
        int min_fragment = 10000;
        for (j = 0; j < num_blocks; j++) {
            if (block_allocated[j] != 1) {
                temp = block_sizes[j] - process_sizes[i];
                if (temp >= 0 && temp < min_fragment) {
                    best_fit_index = j;
                    min_fragment = temp;
                }
            }
        }
        if (best_fit_index != -1) {
            block_index[i] = best_fit_index;
            fragment[i] = min_fragment;
            block_allocated[best_fit_index] = 1;
        } else {
            block_index[i] = -1;
        }
    }
    printf("\nBest Fit\n");
    printf("Process No\tProcess Size\tBlock No\tBlock Size\tFragment\n");
    for (i = 0; i < num_proc; i++) {
        if (block_index[i] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, process_sizes[i], block_index[i] + 1, block_sizes[block_index[i]], fragment[i]);
        } else {
            printf("%d\t\t%d\t\t-1\t\t-1\t\t-1 (No suitable block)\n", i + 1, process_sizes[i]);
        }
    }
}

void FirstFit(int num_blocks, int num_proc, int block_sizes[], int process_sizes[]) {
    int i, j;
    int fragment[MAX_BLOCKS], block_allocated[MAX_BLOCKS], block_index[MAX_BLOCKS];
    for (i = 0; i < num_blocks; i++) {
        block_allocated[i] = 0;
    }

    int temp;
    for (i = 0; i < num_proc; i++) {
        temp = -1;
        for (j = 0; j < num_blocks; j++) {
            if (block_allocated[j] != 1) {
                temp = block_sizes[j] - process_sizes[i];
                if (temp >= 0) {
                    block_index[i] = j;
                    block_allocated[j] = 1;
                    break;
                }
            }
        }
        if (temp >= 0) {
            fragment[i] = temp;
        } else {
            block_index[i] = -1;
        }
    }
    printf("\nFirst Fit\n");
    printf("Process No\tProcess Size\tBlock No\tBlock Size\tFragment\n");
    for (i = 0; i < num_proc; i++) {
          if (block_index[i] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, process_sizes[i], block_index[i] + 1, block_sizes[block_index[i]], fragment[i]);
        } else {
            printf("%d\t\t%d\t\t-1\t\t-1\t\t-1 (No suitable block)\n", i + 1, process_sizes[i]);
        }
    }
}

int main() {
    int num_blocks, num_proc;
    printf("Enter the number of blocks:\n");
    scanf("%d", &num_blocks);
    printf("Enter the number of processes:\n");
    scanf("%d", &num_proc);
    int i, j;
    int block_sizes[MAX_BLOCKS], process_sizes[MAX_BLOCKS];
    printf("Enter the size of the blocks:\n");
    for (i = 0; i < num_blocks; i++) {
        printf("Block %d:", i + 1);
        scanf("%d", &block_sizes[i]);
    }
    printf("Enter the size of the processes:\n");
    for (i = 0; i < num_proc; i++) {
        printf("Process %d:", i + 1);
        scanf("%d", &process_sizes[i]);
    }

    WorstFit(num_blocks, num_proc, block_sizes, process_sizes);
    BestFit(num_blocks, num_proc, block_sizes, process_sizes);
    FirstFit(num_blocks, num_proc, block_sizes, process_sizes);

    return 0;
}
