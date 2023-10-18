#include "main.h"
#include "main2.h"
#include "main3.h"

/**
 * _strcpy - a function that copies a string from src to dest
 * @dest: pointer to the destination buffer
 * @src: pointer to the source string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}


/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string to be appended.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = 0;
	int i;

	/*Find the length of the destination string*/
	while (dest[dest_len] != '\0')
		dest_len++;

	/*Append the source string to the destination string*/
	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len++] = src[i];

	/*Add a terminating null byte at the end*/
	dest[dest_len] = '\0';

	return (dest);
}

/**
 * _strcmp - Compares two strings.
 *
 * @s1: First string to compare.
 * @s2: Second string to compare.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}


/**
 * _strtok - Breaks a string into a sequence of zero or more non-empty tokens.
 *
 * @str: The string to be tokenized.
 * @delim: A set of delimiter characters used to separate tokens.
 *
 * Return: A pointer to the next token, or NULL if no more tokens are found.
 */
char *_strtok(char *str, const char *delim)
{
	static char *last_str;
	char *start;
	char *end;

	if (str != NULL)
	{
		last_str = str;
	}
	if (last_str == NULL || *last_str == '\0')
	{
		return (NULL); /* No more tokens to extract */
	}
	start = last_str;
	/* Find the start of the token */
	while (*start != '\0' && _strchr(delim, *start) != NULL)
	{
		start++;
	}
	if (*start == '\0')
	{
		last_str = NULL;
		return (NULL); /* No more tokens to extract */
	}
	end = start + 1;
	/* Find the end of the token */
	while (*end != '\0' && _strchr(delim, *end) == NULL)
	{
		end++;
	}
	/* Set the last_str pointer for the next call */
	if (*end == '\0')
	{
		last_str = NULL;
	}
	else
	{
		*end = '\0';
		last_str = end + 1;
	}
	return (start);
}

/**
 * _strchr - Locates the first occurrence of a character in a string.
 *
 * @s: The string to search within.
 * @c: The character to search for.
 *
 * Return: A pointer to the first occurrence of @c in @s, or NULL if not found.
 */
const char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}

	if (*s == c)
	{
		return (s);
	}

	return (NULL); /* Character not found */
}
