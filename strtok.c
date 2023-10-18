#include "main.h"
#include "main2.h"
#include "main3.h"

/**
 * execute_exit - Executes the "exit" built-in cmd.
 *
 * @args: An array of strings representing the cmd arguments.
 * @arg_c: The number of arguments in the array.
 *
 * Return: The exit status to be used for terminating the shell.
 *
 * Description: This function processes the "exit" built-in cmd, which
 * terminates the shell. If no arguments are provided, it exits with a status
 * of 0. If an argument is provided, it exits with the specified status.
 */
int execute_exit(char **args, int arg_c)
{
	if (arg_c > 1)
	{
		int exit_status = _atoi(args[1]);

		exit(exit_status);
	}
	else
	{
		exit(0);
	}

	/* Control should not reach here, but return a value to satisfy the*/
    /* compiler. */
	return (0);
}

/**
 * execute_cd - Executes the "cd" built-in cmd.
 *
 * @args: An array of strings representing the cmd arguments.
 * @arg_c: The number of arguments in the array.
 *
 * Return: 0 on success, -1 on failure.
 *
 * Description: This function processes the "cd" built-in cmd,
 * which changes the current working directory. If no arguments
 * are provided, it changes to the user's home directory. If an
 * argument is provided, it attempts to change to the specified directory.
 */
int execute_cd(char **args, int arg_c)
{
	if (arg_c > 1)
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
			return (-1); /* Return an error code */
		}
	}
	else
	{
		if (chdir(_getenv("HOME")) != 0)
		{
			perror("cd");
			return (-1); 
		}
	}

	return (0);
}

/**
 * execute_setenv - Executes the "setenv" built-in cmd.
 *
 * @args: An array of strings representing the cmd arguments.
 * @arg_c: The number of arguments in the array.
 *
 * Return: 0 on success, -1 on failure.
 *
 * Description: This function processes the "setenv" built-in cmd,
 * which sets or updates an environment variable. If the variable
 * doesn't exist, it creates a new one.
 */
int execute_setenv(char **args, int arg_c)
{
	if (arg_c != 3)
	{
		char msg[] = "Usage: setenv VARIABLE VALUE\n";

		write(STDOUT_FILENO, msg, _strlen(msg));
		return (-1); /* Return an error code */
	}
	else
	{
		char *variable = args[1];
		char *value = args[2];

		/* Set the environment variable (custom implementation or use _setenv) */
		if (_setenv(variable, value, 1) != 0)
		{
			perror("setenv");
			return (-1); 
		}
	}

	return (0);
}

/**
 * execute_unsetenv - Executes the "unsetenv" built-in cmd.
 *
 * @args: An array of strings representing the cmd arguments.
 * @arg_c: The number of arguments in the array.
 *
 * Return: 0 on success, -1 on failure.
 *
 * Description: This function processes the "unsetenv" built-in
 * cmd, which removes an environment variable.
 */
int execute_unsetenv(char **args, int arg_c)
{
	if (arg_c != 2)
	{
		char msg[] = "Usage: unsetenv VARIABLE\n";

		write(STDOUT_FILENO, msg, _strlen(msg));
		return (-1);
	}
	else
	{
		char *variable = args[1];

		/* Unset the environment variable (custom implementation or use _unsetenv) */
		if (_unsetenv(variable) != 0)
		{
			perror("unsetenv");
			return (-1);
		}
	}

	return (0); 
}

/**
 * execute_env - Executes the "env" built-in cmd.
 *
 * Description: This function processes the "env" built-in cmd,
 * which prints the current environment.
 *
 * Return: Always returns 0.
 */
int execute_env(void)
{
	char **env = environ;

	while (*env)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}

	return (0);
}
