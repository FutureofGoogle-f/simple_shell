#include "main.h"
#include "main2.h"
#include "main3.h"

/**
 * _strlen - Computes the length of a string.
 *
 * @s: The string whose length is to be determined.
 *
 * Return: The number of characters in the string (excluding the null
 * terminator).
 */
int _strlen(const char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
 * _strdup - Duplicates (copies) a string.
 *
 * @s: The string to be duplicated.
 *
 * Return: A pointer to the newly allocated memory containing the duplicated
 *  string. Returns NULL if memory allocation fails or if @s is NULL.
 */
char *_strdup(const char *s)
{
	size_t len = _strlen(s) + 1; /*+1 for the null terminator*/
	char *dup = (char *)malloc(len);

	if (dup == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	_strcpy(dup, s);
	return (dup);
}

/**
 * _atoi - Converts a string to an integer.
 *
 * @str: The string to be converted.
 *
 * Return: The integer value of the string.
 */
int _atoi(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (sign * result);
}

/**
 * _startswith - Checks if a string starts with a specified prefix.
 *
 * @str: The string to be checked.
 * @prefix: The prefix to check for at the beginning of @str.
 *
 * Return: 1 if @str starts with @prefix, 0 otherwise.
 */
int _startswith(const char *str, const char *prefix)
{
	while (*prefix)
	{
		if (*prefix != *str)
		{
			return (0); /* Does not start with the prefix */
		}
		prefix++;
		str++;
	}
	return (1); /* Starts with the prefix */
}

/**
 * _strncmp - Compare the first 'n' characters of two strings.
 *
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The maximum number of characters to compare.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}

		if (*s1 == '\0')
		{
			return (0);
		}

		s1++;
		s2++;
		n--;
	}

	return (0);
}
