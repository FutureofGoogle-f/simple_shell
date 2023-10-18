#include "main.h"
#include "main2.h"
#include "main3.h"

/**
 * build_command_arguments - Builds the command arguments dynamically
 * based on the number of arguments.
 *
 * @args: An array of strings representing the command arguments.
 * @arg_c: The number of arguments in the array.
 *
 * Return: An array of strings representing the command and its arguments.
 */
char **build_command_arguments(char **args, int arg_c)
{
	/* Create an array of strings to store the command and its arguments. */
	char **cmd_argv = (char **)malloc((arg_c + 1) * sizeof(char *));
	int i;

	if (cmd_argv == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < arg_c; i++)
	{
		cmd_argv[i] = args[i];
	}
	cmd_argv[arg_c] = NULL; /* NULL-terminate the array */

	return (cmd_argv);
}

/**
 * handle_command_not_found - Handles the case when the command is not found.
 *
 * @cmd: The command that was not found.
 */
void handle_command_not_found(char *cmd)
{
	char msg[MAX_INPUT_SIZE]; /* Command not found in PATH */

	_write_str("Command not found: ");
	_write_str(cmd);
	_write_newline();
	write(STDERR_FILENO, msg, _strlen(msg));
	exit(EXIT_FAILURE);
}

/**
 * wait_for_child_process - Waits for the child process to complete and
 * updates the last exit status.
 *
 * @pid: The process ID of the child process.
 * @lastexit_status: Pointer to an integer containing the last exit status.
 */
void wait_for_child_process(pid_t pid, int *lastexit_status)
{
	int status;

	if (waitpid(pid, &status, 0) == -1)
	{
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
	if (WIFEXITED(status))
	{
		*lastexit_status = WEXITSTATUS(status);
	}
}
