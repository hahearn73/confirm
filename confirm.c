#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char response;
    printf("Are you sure? (y/N): ");
    response = getchar();
    if (!(response == 'y' || response == 'Y' || response == '\n'))
    {
        printf("Exiting");
        exit(0);
    }

    int total_length = 0;
    for (int i = 1; i < argc; ++i) {
        total_length += snprintf(NULL, 0, "%s ", argv[i]);
    }

    char *command = (char *)malloc(total_length + 1);
    if (command == NULL) {
        perror("malloc");
        exit(0);
    }

    command[0] = '\0';
    for (int i = 1; i < argc; ++i) {
        strcat(command, argv[i]);
        strcat(command, " ");
    }

    int result = system(command);
    if (result == -1) {
        perror("system");
        exit(1);
    }

    free(command);
    exit(0);
}
