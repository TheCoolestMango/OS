#include <stdio.h>

int main() {
    FILE *fileIn, *fileOut;
    fileIn = fopen("input.txt", "r");
    fileOut = fopen("output.txt", "w");

    int p, r; // p - processes, r - resources
    fscanf(fileIn, "%d", &r);
    fscanf(fileIn, "%d", &p);

    int E[r]; //vector E
    int A[r]; //vector A
    int C[p][r]; // matrix C
    int R[p][r]; // matrix R

    for (size_t i = 0; i < r; i++) {
        fscanf(fileIn, "%d", &E[i]);
    }
    for (size_t i = 0; i < r; i++) {
        fscanf(fileIn, "%d", &A[i]);
    }

    for (size_t i = 0; i < p; i++) {
        for (size_t j = 0; j < r; j++) {
            fscanf(fileIn, "%d", &C[i][j]);
        }
    }
    for (size_t i = 0; i < p; i++) {
        for (size_t j = 0; j < r; j++) {
            fscanf(fileIn, "%d", &R[i][j]);
        }
    }
    
    printf("Vector A: ");
    for (size_t i = 0; i < r; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("Vector E: ");
    for (size_t i = 0; i < r; i++) {
        printf("%d ", E[i]);
    }
    printf("\n");

    printf("R and C:\n");
    for (size_t i = 0; i < p; i++) {
        for (size_t j = 0; j < r; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\t");
        for (size_t j = 0; j < r; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    int check[p];
    for (size_t i = 0; i < p; i++) {
        check[i] = 0;
    }
    //0 for white, 1 for black (checked)
    while (1) {
        printf("\nSearch for unchecked nodes\n");
        int pass = 0;
        for (size_t i = 0; i < p; i++) {
            if (check[i] == 0) {
                printf("Checking process %lu\t R: ", i + 1);
                for (size_t j = 0; j < r; j++) {
                    printf("%d ", R[i][j]);
                }
                printf("\n");

                int node = 1;
                for (size_t j = 0; j < r; j++) {
                    if (R[i][j] > A[j]) {
                        node = 0;
                        break;
                    }
                }
                if (node == 1) {
                    printf("Adding resources of process %lu to A: ", i + 1);
                    for (size_t j = 0; j < r; j++) {
                        printf("%d ", A[j]);
                    }
                    for (size_t j = 0; j < r; j++) {
                        A[j] += C[i][j];
                    }
                    for (size_t j = 0; j < r; j++) {
                        printf("%d ", A[j]);
                    }
                    printf("\n");
                    check[i] = 1;
                    pass = 1;
                }
            }
        }
        if (pass == 0)
            break;
    }
    int deadlocks = 0;
    for (size_t i = 0; i < p; i++) {
        if (check[i] == 0) {
            fprintf(fileOut, "%zu ", i + 1);
            deadlocks++;
        }
    }
    if (deadlocks == 0)
        fprintf(fileOut, "No deadlock is detected");

    fclose(fileOut);
    return 0;
}
