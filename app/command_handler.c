#include <stdio.h>
#include <string.h>
#include "command_handler.h"
#include "stack_ops.h"

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <command> [arguments]\n", program_name);
    fprintf(stderr, "\nCommands:\n");
    fprintf(stderr, "  stack <stack_name>  Start a Docker Compose stack\n");
    fprintf(stderr, "  stop <stack_name>   Stop a Docker Compose stack\n");
    fprintf(stderr, "\nAvailable stacks:\n");
    fprintf(stderr, "  appwrite, eventstream, databases, monitoring, or any stack in ../misc/\n");
}

static int handle_stack_command(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s stack <stack_name>\n", argv[0]);
        return 1;
    }

    return stack_start(argv[2]) == 0 ? 0 : 1;
}

static int handle_stop_command(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s stop <stack_name>\n", argv[0]);
        return 1;
    }

    return stack_stop(argv[2]) == 0 ? 0 : 1;
}

int handle_command(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    const char *command = argv[1];

    if (strcmp(command, "stack") == 0) {
        return handle_stack_command(argc, argv);
    }

    if (strcmp(command, "stop") == 0) {
        return handle_stop_command(argc, argv);
    }

    fprintf(stderr, "Unknown command: %s\n", command);
    print_usage(argv[0]);
    return 1;
}
