#include "main.h"
#include "main2.h"
#include "main3.h"
/**
 * exec_builtin_cmd - Executes built-in cmds.
 *
 * @alias_list: A pointer to the alias list.
 * @args: An array of strings representing the cmd arguments.
 * @arg_c: The number of arguments in the array.
 * @lastexit_status: Pointer to an integer containing the last exit status.
 *
 * Return: The exit status of the executed built-in cmd.
 *
 * Description: This function processes and executes various built-in cmds,
 * such as "exit," "cd," "alias," "setenv," "unsetenv," and "env."
 */
int exec_builtin_cmd(struct AliasList *alias_list, char **args, int arg_c, int __attribute__((unused)) *lastexit_status)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		execute_exit(args, arg_c);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		execute_cd(args, arg_c);
	}
	else if (_strcmp(args[0], "alias") == 0)
	{
		execute_alias(alias_list, args, arg_c);
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		execute_setenv(args, arg_c);
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		execute_unsetenv(args, arg_c);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		execute_env();
	}
	else
	{
		return (0);
	}

	return (1); 
}
