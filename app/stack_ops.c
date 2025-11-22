#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "stack_ops.h"

#define MAX_PATH_LEN 512
#define MAX_CMD_LEN 1024
#define STACK_BASE_DIR "../misc"

static int change_to_stack_dir(const char *stack_name, char *path_out) {
    if (strcmp(stack_name, "eventstream") == 0) {
        snprintf(path_out, MAX_PATH_LEN, "../eventstream");
    } else if (strcmp(stack_name, "databases") == 0) {
        snprintf(path_out, MAX_PATH_LEN, "../databases");
    } else {
        snprintf(path_out, MAX_PATH_LEN, "%s/%s", STACK_BASE_DIR, stack_name);
    }

    if (chdir(path_out) != 0) {
        perror("Failed to change directory");
        fprintf(stderr, "Could not access stack directory: %s\n", path_out);
        return -1;
    }

    return 0;
}

static int execute_docker_compose(const char *compose_args) {
    char command[MAX_CMD_LEN];
    snprintf(command, sizeof(command), "docker compose %s", compose_args);

    int result = system(command);
    if (result != 0) {
        fprintf(stderr, "Docker compose command failed\n");
        return -1;
    }

    return 0;
}

int stack_start(const char *stack_name) {
    char path[MAX_PATH_LEN];

    if (change_to_stack_dir(stack_name, path) != 0) {
        return -1;
    }

    printf("Starting stack '%s' in %s...\n", stack_name, path);

    if (execute_docker_compose("up -d") != 0) {
        fprintf(stderr, "Failed to start stack\n");
        return -1;
    }

    printf("Stack '%s' started successfully\n", stack_name);
    return 0;
}

int stack_stop(const char *stack_name) {
    char path[MAX_PATH_LEN];

    if (change_to_stack_dir(stack_name, path) != 0) {
        return -1;
    }

    printf("Stopping stack '%s' in %s...\n", stack_name, path);

    if (execute_docker_compose("down --remove-orphans") != 0) {
        fprintf(stderr, "Failed to stop stack\n");
        return -1;
    }

    printf("Stack '%s' stopped successfully\n", stack_name);
    return 0;
}
