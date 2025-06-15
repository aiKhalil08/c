#include <stdio.h>
#include <time.h>

#define SIZE 1000000
#define TRIALS 1000000000

int binsearch_original_k(int x, int v[], int n);
int binsearch_original_kr(int x, int v[], int n);
int binsearch_optimized(int x, int v[], int n);

int two_checks();
int five_checks();

int main() {
    int sorted_array[SIZE];
    for (int i = 0; i < SIZE; i++) {
        sorted_array[i] = i;
    }

    int target = SIZE - 1;
    clock_t start, end;
    double time_original = 0, time_optimized = 0;

    // Test original version
    start = clock();
    for (int i = 0; i < TRIALS; i++) {
        // binsearch_original_k(target, sorted_array, SIZE);
        // binsearch_original_kr(target, sorted_array, SIZE);
        two_checks();
    }
    end = clock();
    time_original = (double)(end - start) / CLOCKS_PER_SEC;

    // Test optimized version
    start = clock();
    for (int i = 0; i < TRIALS; i++) {
        // binsearch_original_k(target, sorted_array, SIZE);
        // binsearch_optimized(target, sorted_array, SIZE);
        five_checks();
    }
    end = clock();
    time_optimized = (double)(end - start) / CLOCKS_PER_SEC;

    // printf("Time (original version): %.6f seconds\n", time_original);
    // printf("Time (optimized version): %.6f seconds\n", time_optimized);

    printf("Time (two checks): %.6f seconds\n", time_original);
    printf("Time (five checks): %.6f seconds\n", time_optimized);

    return 0;
}

// Original version(k): two tests in the loop
int binsearch_original_k(int x, int v[], int n) {
    int low, mid, high;
    int pos;

    low = 0;
    high = n - 1;

    while (x != v[mid = (low + high) / 2] && low <= high) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (x == v[mid])
        pos = mid;
    else
        pos = -1;

    return pos;
}

// Original version(kr): two tests in the loop
int binsearch_original_kr(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            /* found match */
            return mid;
    }
    return -1; /* no match */
}

// Optimized version: one test in the loop
int binsearch_optimized(int x, int v[], int n) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

int two_checks() {
    int a = 2;

    if (a == 1)
        ;
    else if (a == 2)
        ;
    else
        ;

    return 0;
}

int five_checks() {
    int a = 5;

    if (a == 1)
        ;
    else if (a == 2)
        ;
    else if (a == 3)
        ;
    else if (a == 4)
        ;
    else if (a == 5)
        ;
    else
        ;

    return 0;
}
