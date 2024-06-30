#include <stdio.h>

int main() {
    int N, K, count = 0,i;
    
    // User input for the size of the array frequency
    printf("Enter the size of the array frequency: ");
    scanf("%d", &N);

    int frequency[N]; // Declare the frequency array

    // User input for elements of the array frequency
    printf("Enter elements of the array frequency: ");
    for (i = 0; i < N; i++) {
        scanf("%d", &frequency[i]);
    }

    // User input for the size of the array Key_size
    printf("Enter the size of the array Key_size: ");
    scanf("%d", &K);

    int key_size[K], num_keys = 0; // Declare the key_size array

    // User input for elements of the array Key_size
    printf("Enter elements of the array Key_size: ");
    for (i = 0; i < K; i++) {
        scanf("%d", &key_size[i]);
        num_keys += key_size[i]; // Calculate total keys
    }

    if (num_keys < N) {
        printf("-1\n"); // Not enough keys for the frequency array
    } else {
        // Sort the frequency array in descending order
        for (i = 1; i < N; i++) {
            int current = frequency[i];
            int j = i - 1;
            while (j >= 0 && frequency[j] < current) {
                frequency[j + 1] = frequency[j];
                j--;
            }
            frequency[j + 1] = current;
        }

        printf("The array in descending order is:\n");
        for (i = 0; i < N; i++) {
            printf("%d ", frequency[i]);
        }

        int loop_count = 0;
        int j = 1;

        while (loop_count < N) {
            int i = 0;
            int available_keys = 0;

            // Count how many keys are available in the current loop
            for (i = 0; i < K && loop_count < N; i++) {
                if (key_size[i] > 0) {
                    available_keys++;
                    loop_count++;
                }
            }

            // Distribute available keys and calculate the cost
            for (i = 0; i < available_keys; i++) {
                key_size[i]--;
                count += (frequency[loop_count - available_keys + i] * j);
            }

            j++; // Increment j for the next iteration
        }

        printf("\nThe minimum cost is %d\n", count);
    }

    return 0;
}
