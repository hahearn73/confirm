#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(0);
    }

    char response;
    printf("Are you sure? (Y/n): ");
    response = getchar();
    if (!(response == 'y' || response == 'Y'))
    {
        printf("Exiting\n");
        exit(0);
    }

    size_t total_length = 0;
    for (int i = 1; i < argc; ++i)
        total_length += strlen(argv[i]) + 1;

    char *command = (char *)malloc(total_length + 1);
    if (command == NULL) {
        perror("malloc");
        exit(1);
    }

    command[0] = '\0';
    for (int i = 1; i < argc; ++i) {
        strncat(command, argv[i], strlen(argv[i]));
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