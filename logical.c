#include "main.h"
#include "main2.h"
#include "main3.h"

/**
 * var_replace - Handles variable replacement in cmd
 * arguments.
 *
 * @args:             An array of strings representing the cmd arguments.
 * @arg_c:        The number of arguments in the array.
 * @lastexit_status: Pointer to an integer containing the last exit status.
 * @shell_pid:        The process ID of the shell.
 *
 * Description: This function takes an array of cmd arguments and searches
 * for special variables (e.g., "$?", "$$") to replace with their corresponding
 * values. It also updates the last exit status. The modified arguments are
 * stored back in the 'args' array.
 */
void var_replace(char **args, int arg_c, int *lastexit_status, pid_t shell_pid)
{
	int j;

	for (j = 0; j < arg_c; j++)
	{
		char exit_status_str[10];
		char shell_pid_str[10];
		char *new_arg;

		if (_strcmp(args[j], "$?") == 0)
		{
			/* Replace $? with the last exit status */
			_write_int(*lastexit_status);
			new_arg = _strdup(exit_status_str);

			if (new_arg == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			args[j] = new_arg;
		}
		else if (_strcmp(args[j], "$$") == 0)
		{
			/* Replace $$ with the shell's PID */
			_write_int(shell_pid);
			new_arg = _strdup(shell_pid_str);

			if (new_arg == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			args[j] = new_arg;
		}
	}
}
