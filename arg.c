#include "main.h"
#include "main2.h"
#include "main3.h"

/**
 * execute_commands - Execute a command or a series of commands separated
 * by semicolons.
 *
 * @command: The command string to execute.
 * @alias_list: A pointer to the alias list.
 */
void execute_commands(char *command, struct AliasList *alias_list)
{
	int lastexit_status = 0; 
	pid_t shell_pid = getpid(); 
	char *commands[MAX_INPUT_SIZE];
	char *token;
	int i;
	int command_count;

	token = _strtok(command, ";");

	command_count = 0;

	while (token != NULL)
	{
		commands[command_count++] = token;
		token = _strtok(NULL, ";");
	}

	for (i = 0; i < command_count; i++)
	{
		execute_one_command(commands[i], &lastexit_status, shell_pid, alias_list);
	}
}

/**
 * execute_one_command - Execute a single command.
 *
 * @command: The command string to execute.
 * @lastexit_status: A pointer to the last exit status.
 * @shell_pid: The PID of the shell.
 * @alias_list: A pointer to the alias list.
 */
void execute_one_command(char *command, int *lastexit_status, pid_t shell_pid, struct AliasList *alias_list)
{
	int arg_c = 0;
	char *args[MAX_INPUT_SIZE];

	char *token = _strtok(command, " ");

	while (token != NULL)
	{
		args[arg_c++] = token;
		token = _strtok(NULL, " ");
	}
	args[arg_c] = NULL;

	var_replace(args, arg_c, lastexit_status, shell_pid);

	if (!exec_builtin_cmd(alias_list, args, arg_c, lastexit_status))
	{
		execute_external_command(args, arg_c, lastexit_status);
	}
}
