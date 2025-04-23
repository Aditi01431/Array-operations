
#include <stdio.h>

#define MAX_SIZE 100  // Define the maximum size of the array

// Simplified insert
void insert_element(int arr[], int *size, int value, int position) {
    if (*size >= MAX_SIZE) {
        printf("Array is full! Cannot insert.\n");
        return;
    }

    if (position < 0 || position > *size) {
        printf("Invalid position! Please enter a position between 0 and %d.\n", *size);
        return;
    }

    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    (*size)++;
    printf("Value inserted at position %d.\n", position);
}

// Simplified update
void update_element(int arr[], int size, int position, int new_value) {
    if (position < 0 || position >= size) {
        printf("Invalid position! Please enter a position between 0 and %d.\n", size - 1);
        return;
    }

    arr[position] = new_value;
    printf("Updated position %d to value %d.\n", position, new_value);
}

// Simplified delete
void delete_element(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position! Please enter a position between 0 and %d.\n", *size - 1);
        return;
    }

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("Element at position %d deleted.\n", position);
}

// Function to sort the array using Selection Sort
void sort_array(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
    printf("Array sorted in ascending order!\n");
}

// Function to search for an element in the array
void search_element(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("Element found at index %d.\n", i);
            return;
        }
    }
    printf("Element not found.\n");
}

// Function to display the current elements of the array
void display_array(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Current array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    while (1) {
        printf("\nArray Operations Menu:\n");
        printf("1. Insert value\n");
        printf("2. Update value\n");
        printf("3. Delete value\n");
        printf("4. Sort array\n");
        printf("5. Search value\n");
        printf("6. Display array\n");
        printf("7. Exit\n");

        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int value, position;
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert (0 to %d): ", size);
                scanf("%d", &position);
                insert_element(arr, &size, value, position);
                break;
            }

            case 2: {
                int position, new_value;
                printf("Enter position to update (0 to %d): ", size - 1);
                scanf("%d", &position);
                printf("Enter new value: ");
                scanf("%d", &new_value);
                update_element(arr, size, position, new_value);
                break;
            }

            case 3: {
                int position;
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                delete_element(arr, &size, position);
                break;
            }

            case 4:
                sort_array(arr, size);
                break;

            case 5: {
                int value;
                printf("Enter value to search: ");
                scanf("%d", &value);
                search_element(arr, size, value);
                break;
            }

            case 6:
                display_array(arr, size);
                break;

            case 7:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
