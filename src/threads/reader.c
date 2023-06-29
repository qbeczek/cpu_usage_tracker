#include "threads/reader.h"

#include <stdio.h>

void* thread_reader_function(void* arg) {
    printf("Hello from thread_reader!\n");

    int* value_ptr = (int*)arg;
    *value_ptr = *value_ptr * 2;

    return NULL;
}