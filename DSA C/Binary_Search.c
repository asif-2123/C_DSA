#include <stdio.h>

int main() {
    int n, key;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int low = 0;
    int high = n - 1;
    int found = 0;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            printf("Element found at position %d\n", mid);
            found = 1;
            break;
        }
        else if (key > arr[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (found == 0) {
        printf("Element not found\n");
    }

    return 0;
}