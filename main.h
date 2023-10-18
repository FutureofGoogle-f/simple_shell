#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024

/* Declare environ */
extern char **environ;

/* Structures */
struct Alias {
    char *name;
    char *value;
    struct Alias *next;
};

struct AliasList {
    struct Alias *head;
};

/* Global variables */
extern struct AliasList *alias_list;
extern struct Alias *alias_head;

/* Function declarations */
pid_t fork_child_process(void);
void execute_command(char **args, int arg_c);

#endif /* MAIN_H */
