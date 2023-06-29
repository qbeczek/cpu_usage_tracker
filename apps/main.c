#include <pthread.h>
#include <stdio.h>

#include "threads/reader.h"

int main() {
    pthread_t thread_reader;

    pthread_create(&thread_reader, NULL, thread_reader_function, NULL);
    pthread_join(thread_reader, NULL);

    printf("Hello from main!\n");

    return 0;
}
