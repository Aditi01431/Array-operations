#include <stdio.h>

#define MAX_SIZE 100  // Define the maximum size of the array

// Function to insert an element at a given position
void insert_element(int arr[], int *size, int value, int position) {
    // Check if the position is valid
    if (position < 0 || position > *size) {
        printf("Invalid position! Please enter a valid position.\n");
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[position] = value;
    (*size)++;  // Increase the size of the array
    printf("Value inserted successfully!\n");
}

// Function to update the value at a given index
void update_element(int arr[], int size, int position, int new_value) {
    // Check if the position is valid
    if (position < 0 || position >= size) {
        printf("Invalid position! Please enter a valid position.\n");
        return;
    }

    // Update the value at the given index
    arr[position] = new_value;
    printf("Value updated successfully!\n");
}

// Function to delete an element at a given index
void delete_element(int arr[], int *size, int position) {
    // Check if the position is valid
    if (position < 0 || position >= *size) {
        printf("Invalid position! Please enter a valid position.\n");
        return;
    }

    // Shift elements to the left to fill the gap created by the deleted element
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrease the size of the array
    (*size)--;
    printf("Element deleted successfully!\n");
}

// Function to sort the array using Selection Sort
void sort_array(int arr[], int size) {
    // Selection Sort: Find the minimum element in unsorted part of the array and swap
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the element at the current position
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
    printf("Array sorted in ascending order!\n");
}

// Function to search for an element in the array
void search_element(int arr[], int size, int value) {
    // Iterate through the array to find the element
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
    // If the array is empty, notify the user
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    // Display the array elements
    printf("Current array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];  // Array initialization
    int size = 0;       // Initial size of the array
    int choice;

    // Main loop for the menu system
    while (1) {
        // Display the menu
        printf("\nArray Operations Menu:\n");
        printf("1. Insert value\n");
        printf("2. Update value\n");
        printf("3. Delete value\n");
        printf("4. Sort array\n");
        printf("5. Search value\n");
        printf("6. Display array\n");
        printf("7. Exit\n");

        // Get user input for the operation choice
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Insert operation
                int value, position;
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert (0 to %d): ", size);
                scanf("%d", &position);
                insert_element(arr, &size, value, position);
                break;
            }

            case 2: {
                // Update operation
                int position, new_value;
                printf("Enter position to update (0 to %d): ", size - 1);
                scanf("%d", &position);
                printf("Enter new value: ");
                scanf("%d", &new_value);
                update_element(arr, size, position, new_value);
                break;
            }

            case 3: {
                // Delete operation
                int position;
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                delete_element(arr, &size, position);
                break;
            }

            case 4:
                // Sort operation
                sort_array(arr, size);  // Sort the array using Selection Sort
                break;

            case 5: {
                // Search operation
                int value;
                printf("Enter value to search: ");
                scanf("%d", &value);
                search_element(arr, size, value);
                break;
            }

            case 6:
                // Display operation
                display_array(arr, size);  // Display current array
                break;

            case 7:
                // Exit the program
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                // Invalid input
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
