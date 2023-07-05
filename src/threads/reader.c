#include "threads/reader.h"

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_LENGTH 2048

static int open_file(FILE** file) {
    *file = fopen("/proc/stat", "r");

    if (*file == NULL) {
        perror("Error opening file");
        return 1;
    }

    return 0;
}

void* thread_reader_function(void* arg) {
    printf("Thread_reader working\n");

    FILE* file = NULL;
    int open_file_result = open_file(&file);

    if (open_file_result) {
        printf("Exit thread reader after error in opening file \n");
        return NULL;
    }

    char read_buffer[MAX_BUFFER_LENGTH] = {'\0'};
    char storage_buffer[MAX_BUFFER_LENGTH] = {'\0'};

    /* TODO: make more safety read */
    while (fgets(read_buffer, sizeof(read_buffer), file) != NULL) {
        strcat(storage_buffer, read_buffer);
    }
    printf("\n%s \n", storage_buffer);

    fclose(file);

    return NULL;
}