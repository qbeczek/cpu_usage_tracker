#include <pthread.h>
#include <stdio.h>

#include "threads/reader.h"

int test_1() {
    int value = 10;

    // Create a thread
    pthread_t thread;
    int result = pthread_create(&thread, NULL, thread_reader_function, &value);

    if (result != 0) {
        printf("Error creating thread.\n");
        return 1;  // Test failed
    }

    // Wait for the thread to complete
    pthread_join(thread, NULL);

    return 0;
}

int main() {
    // Run test 1
    int result_1 = test_1();

    return result_1;
}
