#include "main.h"
#include "main2.h"
#include "main3.h"

/**
 * main - The main entry point of the program.
 *
 * @argc: The number of cmd-line arguments.
 * @argv: An array of strings containing the cmd-line arguments.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	/* Create a local AliasList for managing aliases */
	struct AliasList *alias_list = create_alias_list();

	if (argc > 1)
	{
		/* Batch mode: Pass alias_list to batch_mode */
		return (batch_mode(argv[1], alias_list));
	}
	/* Interactive mode: Pass alias_list to interactive_mode */
	return (interactive_mode(alias_list));
}

/**
 * batch_mode - Handles batch mode execution by reading and executing cmds
 *              from a specified file.
 *
 * @filename: The name of the batch file to read and execute cmds from.
 * @alias_list: A pointer to the AliasList for managing aliases.
 *
 * Return: 0 on success, or an error code on failure.
 */
int batch_mode(char *filename, struct AliasList *alias_list)
{
	/* Open the batch file for reading */
	int file_fd = open(filename, O_RDONLY);
	/* Allocate memory for input */
	char *input = (char *)malloc(MAX_INPUT_SIZE);
	size_t input_size = MAX_INPUT_SIZE;
	ssize_t line_length;

	if (file_fd == -1)
	{
		perror("open");
		return (EXIT_FAILURE);
	}

	if (input == NULL)
	{
		perror("malloc");
		close(file_fd);
		return (EXIT_FAILURE);
	}

	/* Read and execute cmds from the batch file */
	while ((line_length = _getline(&input, &input_size, file_fd)) != -1)
	{
		input[line_length - 1] = '\0'; /* Remove newline character */
		execute_commands(input, alias_list);
;
	}

	/* Clean up and close the file */
	free(input);
	close(file_fd);
	return (0);
}

/**
 * interactive_mode - Handles interactive mode execution by reading and
 * executing cmds entered by the user.
 *
 * @alias_list: A pointer to the AliasList for managing aliases.
 *
 * Return: 0 on success, or an error code on failure.
 */
int interactive_mode(struct AliasList *alias_list)
{
	/* Allocate memory for input */
	char *input = (char *)malloc(MAX_INPUT_SIZE);
	size_t input_size = MAX_INPUT_SIZE;
	ssize_t line_length;

	if (input == NULL)
	{
		perror("malloc");
		return (EXIT_FAILURE);
	}

	while (1)
	{
		/* Print the shell prompt */
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);

		line_length = _getline(&input, &input_size, STDIN_FILENO);

		if (line_length == -1)
		{
			/* Handle end of file (Ctrl+D) */
			write(STDOUT_FILENO, "\n", 1);
			free(input);
			break;
		}

		input[line_length - 1] = '\0'; /* Remove newline character */
		execute_commands(input, alias_list);
;
	}

	/* Clean up memory */
	free(input);
	return (0);
}
