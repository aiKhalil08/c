#include <stdio.h>
#include <time.h>

int binsearch(int, int[], int);
int binsearch_kr(int, int[], int);
int modified_binsearch(int, int[], int);

int main() {
                        //0,1,2,3,4,5,6,7,8   
    int sorted_array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int x = 6;

    clock_t start, end;
    double time_kr, time_mod;

    // time kr version
    start = clock();
    binsearch_kr(x, sorted_array, 9);
    end = clock();

    time_kr = (double)(end - start) / CLOCKS_PER_SEC;

    printf("KR version took: %.9f\nModified version took: %.9f\n", time_kr, time_mod);

    // time modified version
    start = clock();
    modified_binsearch(x, sorted_array, 9);
    end = clock();

    time_mod = (double)(end - start) / CLOCKS_PER_SEC;

}

int binsearch_kr(int x, int v[], int n) {
    int low, mid, high;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high)/2;

        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

int modified_binsearch(int x, int v[], int n) {
    int low, mid, high;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (x != v[mid]) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;

        mid = (low + high) / 2;
    }

    if (x == v[mid])
        return mid;
    else
        return -1;
}

int binsearch(int x, int v[], int n) {
    int low, mid, high;
    int pos;

    low = 0;
    high = n - 1;

    while (x != v[mid = (low + high )/ 2] && low <= high) {
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