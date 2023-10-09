#include <stdio.h>

int main() {
    FILE *source_file, *destination_file;
    char buffer[4096];
    size_t bytes_read;

    source_file = fopen("source.txt", "rb");
    destination_file = fopen("destination.txt", "wb");

    if (source_file == NULL || destination_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes_read, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);
    return 0;
}