#include "main.h"
#include "main2.h"
#include "main3.h"


/**
 * create_alias_list - Initialize an alias list.
 *
 * Return: A pointer to the newly created alias list.
 */
struct AliasList *create_alias_list(void)
{
	struct AliasList *list = (struct AliasList *)malloc(sizeof(struct AliasList));

	if (list == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	list->head = NULL;
	return (list);
}

/**
 * add_alias - Add an alias to the list.
 *
 * Parameters:
 * @list: The alias list to which the alias will be added.
 * @name: The name of the alias to be added.
 * @value: The value of the alias to be added.
 */
void add_alias(struct AliasList *list, const char *name, const char *value)
{
	struct Alias *new_alias = (struct Alias *)malloc(sizeof(struct Alias));

	if (new_alias == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	new_alias->name = strdup(name);
	new_alias->value = strdup(value);
	new_alias->next = NULL;

	if (list->head == NULL)
	{
		list->head = new_alias;
	} else
	{
		struct Alias *current = list->head;

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_alias;
	}
}

/**
 * print_aliases - Print all aliases in the list.
 *
 * Parameters:
 * @list: The alias list to be printed.
 */
void print_aliases(const struct AliasList *list)
{
	struct Alias *current = list->head;

	while (current != NULL)
	{
		_write_str("Setting alias: ");
		_write_str(current->name);
		_write_str("='");
		_write_str(current->value);
		_write_str("'\n");
		current = current->next;
	}
}

/**
 * find_alias - Find an alias in the list.
 *
 * Parameters:
 * @list: The alias list to search in.
 * @name: The name of the alias to find.
 *
 * Return: The value of the alias if found, or NULL if not found.
 */
const char *find_alias(const struct AliasList *list, const char *name)
{
	struct Alias *current = list->head;

	while (current != NULL)
	{
		if (strcmp(current->name, name) == 0)
		{
			return (current->value);
		}
		current = current->next;
	}
	return (NULL);
}
