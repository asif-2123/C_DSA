#include <stdio.h>

void merge(int a[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[100];

    // Compare elements of both halves
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            temp[k] = a[i];
            i++;
        } else {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        temp[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements from right half
    while (j <= high) {
        temp[k] = a[j];
        j++;
        k++;
    }

    // Copy back to original array
    for (i = low, k = 0; i <= high; i++, k++) {
        a[i] = temp[k];
    }
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        // Divide
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        // Merge
        merge(a, low, mid, high);
    }
}

int main() {
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
