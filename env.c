#include "main.h"
#include "main2.h"
#include "main3.h"

/**
 * _getenv - Gets the value of an environment variable.
 *
 * @name: The name of the environment variable to retrieve.
 *
 * Return: A pointer to the value of the environment variable if found, or NULL
 * if the variable is not found.
 *
 * Description: This function retrieves the value of an environment variable
 * given its name. If the variable is not found, it returns NULL.
 */
char *_getenv(char *name)
{
	char **environ_ptr = environ;

	while (*environ_ptr)
	{
		if (_startswith(*environ_ptr, name))
		{
			return (*environ_ptr);
		}
		environ_ptr++;
	}

	return (NULL); 
}


/**
 * _unsetenv - Unsets (removes) an environment variable.
 *
 * @var: The name of the environment variable to unset.
 *
 * Return: 0 on success, or -1 on failure.
 *
 * Description: This function removes an environment variable
 *  given its name.
 *  Ifthe variable does not exist, it returns -1.
 */
int _unsetenv(char *var)
{
	char **environ_ptr = environ;
	int index;

	if (!environ_ptr || !var)
	{
		return (0);
	}

	index = 0;

	while (environ_ptr[index] != NULL)
	{
		int i;

		if (_startswith(environ_ptr[index], var) &&
			environ_ptr[index][_strlen(var)] == '=')
		{
			for (i = index; environ_ptr[i] != NULL; i++)
			{
				environ_ptr[i] = environ_ptr[i + 1];
			}
			return (1);
		}
		index++;
	}

	return (0); 
}
