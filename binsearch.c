#include <stdio.h>

int binsearch(int, int[], int);

int main() {
    int sorted_array[] = {1,2,3,4,5,6,7,8,9};
    int x = 9;

    int pos_of_x = binsearch(x, sorted_array, 9);

    printf("The position of %d in the array is %d\n", x, pos_of_x);

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