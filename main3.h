#ifndef MAIN_H
#define MAIN_H

ssize_t _getline(char **lineptr, size_t *n, int fd);
void var_replace(char **args, int arg_c, int *lastexit_status, pid_t shell_pid);
char *find_cmd_path(char *cmd);
void execute_external_command(char **args, int arg_c, int *lastexit_status);
int execute_exit(char **args, int arg_c);
int execute_cd(char **args, int arg_c);
int execute_setenv(char **args, int arg_c);
int execute_unsetenv(char **args, int arg_c);
int execute_env(void);
int exec_builtin_cmd(struct AliasList *alias_list, char **args, int arg_c, int *lastexit_status);
char *_getenv(char *name);
int _unsetenv(char *var);
size_t _getenv_len(const char *var);
void _add_env_var(const char *new_var);
int _setenv(const char *var, const char *value, int overwrite);

#endif /* MAIN_H */
