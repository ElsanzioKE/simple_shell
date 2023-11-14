#include "main.h"

/**
 * find_builtin - finds a builtin command
 * @argv: argument passed
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int find_builtin(char **argv)
{
	int i, builtin_result = -1;
	builtin_command builtins[] = {
		{"exit", my_exit},
		{"env", my_env},
		{NULL, NULL}
	};
	if (argv == NULL || argv[0] == NULL)
		return (-1);

	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (strcmp(argv[0], builtins[i].name) == 0)
		{
			builtin_result = builtins[i].execute_builtins(argv);
			break;
		}
	}

	return (builtin_result);
}
