#include "main.h"
#include "main2.h"
#include "main3.h"

/**
 * _getenv_len - Calculates the length of an environment variable.
 *
 * @var: The environment variable to measure.
 *
 * Return: The length of the environment variable or 0 if it doesn't exist.
 */
size_t _getenv_len(const char *var)
{
	size_t var_len = _strlen(var);
	char **env_ptr;

	if (!var)
		return (0);


	for (env_ptr = environ; *env_ptr; env_ptr++)
	{
		if (_strncmp(*env_ptr, var, var_len) == 0 && (*env_ptr)[var_len] == '=')
			return (_strlen(*env_ptr));
	}

	return (0);
}

/**
 * _add_env_var - Adds a new environment variable to the environment.
 *
 * @new_var: The new environment variable string.
 */
void _add_env_var(const char *new_var)
{
	int env_count = 0;
	char **new_environ;
	int i;

	while (environ[env_count])
		env_count++;

	new_environ = (char **)malloc((env_count + 2) * sizeof(char *));

	if (!new_environ)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < env_count; i++)
		new_environ[i] = environ[i];

	new_environ[env_count] = _strdup(new_var);
	new_environ[env_count + 1] = NULL;

	environ = new_environ;
}

/**
 * _setenv - Sets the value of an environment variable or creates a new one.
 *
 * @var: The name of the environment variable.
 * @value: The value to assign to the environment variable.
 * @overwrite: Flag to determine whether to overwrite an existing variable.
 *
 * Return: 0 on success, or -1 on failure.
 */
int _setenv(const char *var, const char *value, int overwrite)
{
	size_t var_len = _strlen(var);
	size_t value_len = _strlen(value);
	size_t new_var_len = var_len + value_len + 2;
	char *ptr;
	char *new_var;

	if (!var || !value)
		return (-1);

	new_var = (char *)malloc(new_var_len * sizeof(char));

	if (!new_var)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	/* Construct the new_var string using your write functions */
	ptr = new_var;

	_strcpy(ptr, var);
	ptr += _strlen(var);

	_write_char('=');
	_write_str(ptr);
	ptr++;

	_strcpy(ptr, value);

	/* Output the value of ptr using your custom _write function */
	_write_str(ptr);

	if (_getenv_len(var) > 0 && !overwrite)
	{
		free(new_var);
		return (0); /* Variable exists, and overwrite is disabled. */
	}
	_add_env_var(new_var);
	free(new_var); /* Free dynamically allocated memory */
	return (0);
}

