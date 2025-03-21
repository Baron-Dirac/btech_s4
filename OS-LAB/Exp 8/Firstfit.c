#include <stdio.h>

#define MAX 25

void firstFit(int b[], int f[], int nb, int nf);
void bestFit(int b[], int f[], int nb, int nf);
void worstFit(int b[], int f[], int nb, int nf);

int main() {
    int b[MAX], f[MAX], nb, nf, choice;

    // Input number of blocks and files
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    // Input block sizes
    printf("Enter the size of each block:\n");
    for (int i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    // Input file sizes
    printf("Enter the size of each file:\n");
    for (int i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    // Menu for allocation methods
    do {
        printf("\nMemory Allocation Methods:\n");
        printf("1. First Fit\n");
        printf("2. Best Fit\n");
        printf("3. Worst Fit\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                firstFit(b, f, nb, nf);
                break;
            case 2:
                bestFit(b, f, nb, nf);
                break;
            case 3:
                worstFit(b, f, nb, nf);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function for First Fit allocation
void firstFit(int b[], int f[], int nb, int nf) {
    int frag[MAX], bf[MAX], ff[MAX];

    // Initialize block flags and file allocations
    for (int i = 0; i < nb; i++) bf[i] = 0;
    for (int i = 0; i < nf; i++) ff[i] = -1;

    // First Fit allocation
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nb; j++) {
            if (bf[j] == 0 && b[j] >= f[i]) {
                ff[i] = j;
                frag[i] = b[j] - f[i];
                bf[j] = 1;
                break;
            }
        }
    }

    // Print allocation results
    printf("\nFirst Fit Allocation:\n");
    printf("File No.\tFile Size\tBlock No.\tBlock Size\tFragment\n");
    for (int i = 0; i < nf; i++) {
        if (ff[i] != -1)
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, f[i]);
    }
}

// Function for Best Fit allocation
void bestFit(int b[], int f[], int nb, int nf) {
    int frag[MAX], bf[MAX], ff[MAX];

    // Initialize block flags and file allocations
    for (int i = 0; i < nb; i++) bf[i] = 0;
    for (int i = 0; i < nf; i++) ff[i] = -1;

    // Best Fit allocation
    for (int i = 0; i < nf; i++) {
        int bestIdx = -1;
        for (int j = 0; j < nb; j++) {
            if (bf[j] == 0 && b[j] >= f[i]) {
                if (bestIdx == -1 || b[j] < b[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            ff[i] = bestIdx;
            frag[i] = b[bestIdx] - f[i];
            bf[bestIdx] = 1;
        }
    }

    // Print allocation results
    printf("\nBest Fit Allocation:\n");
    printf("File No.\tFile Size\tBlock No.\tBlock Size\tFragment\n");
    for (int i = 0; i < nf; i++) {
        if (ff[i] != -1)
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, f[i]);
    }
}

// Function for Worst Fit allocation
void worstFit(int b[], int f[], int nb, int nf) {
    int frag[MAX], bf[MAX], ff[MAX];

    // Initialize block flags and file allocations
    for (int i = 0; i < nb; i++) bf[i] = 0;
    for (int i = 0; i < nf; i++) ff[i] = -1;

    // Worst Fit allocation
    for (int i = 0; i < nf; i++) {
        int worstIdx = -1;
        for (int j = 0; j < nb; j++) {
            if (bf[j] == 0 && b[j] >= f[i]) {
                if (worstIdx == -1 || b[j] > b[worstIdx]) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            ff[i] = worstIdx;
            frag[i] = b[worstIdx] - f[i];
            bf[worstIdx] = 1;
        }
    }

    // Print allocation results
    printf("\nWorst Fit Allocation:\n");
    printf("File No.\tFile Size\tBlock No.\tBlock Size\tFragment\n");
    for (int i = 0; i < nf; i++) {
        if (ff[i] != -1)
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, f[i]);
    }
}
