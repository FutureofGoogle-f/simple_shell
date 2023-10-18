#ifndef MAIN_H
#define MAIN_H

char **build_command_arguments(char **args, int arg_c);
void handle_command_not_found(char *cmd);
void wait_for_child_process(pid_t pid, int *lastexit_status);

void execute_commands(char *command, struct AliasList *alias_list);
void execute_one_command(char *command, int *lastexit_status, pid_t shell_pid, struct AliasList *alias_list);
struct AliasList* create_alias_list(void);
void add_alias(struct AliasList *list, const char *name, const char *value);
void print_aliases(const struct AliasList *list);
const char *find_alias(const struct AliasList *list, const char *name);
void update_alias(struct AliasList *list, const char *name, const char *newval);
void execute_alias(struct AliasList *list, char **args, int arg_c);
void *_memcpy(void *dest, const void *src, size_t n);
int resize_buffer(char **lineptr, size_t *n);
ssize_t _getline(char **lineptr, size_t *n, int fd);

void _write_str(const char *str);
void _write_int(int num);
void _write_char(char c);
void _write_newline(void);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, const char *delim);
const char *_strchr(const char *s, char c);
int _strlen(const char *s);
char *_strdup(const char *s);
int _atoi(char *str);
int _startswith(const char *str, const char *prefix);
int _strncmp(const char *s1, const char *s2, size_t n);
int batch_mode(char *filename, struct AliasList *alias_list);
int interactive_mode(struct AliasList *alias_list);
int main(int argc, char *argv[]);

#endif /* MAIN_H */
