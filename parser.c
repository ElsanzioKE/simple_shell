#include "main.h"
/**
 * parser - function that tokenizes the input
 * command using the strtok function
 * @input: the string input through the
 * shell interface
 * @delim: delimeter
 * Return: pointer to tokenized output
 */

char **parser(char *input, const char *delim)
{
	char **tokens, *token;
	int token_count;

	tokens = NULL;
	token_count = 0;
	
	if(delim == NULL)

	delim = " \n\t";
	
	token  = strtok(input, delim);
	while (token != NULL)
	{
		tokens = realloc(tokens, (token_count + 1) * sizeof(char*));
		if (tokens == NULL)
		{
			perror("realloc failed");
			exit(EXIT_FAILURE);
		}
		tokens[token_count] = _strdup(token);
		token_count++;

		token = strtok(NULL, delim);
	}
	tokens = realloc(tokens, (token_count + 1) * sizeof(char*));
	if (tokens == NULL)
	{
		perror("realloc failed");
		exit(EXIT_FAILURE);
	}
	tokens[token_count] = NULL;
	return (tokens);
}

#include "main.h"
/**
 * free_tokens - frees tokens that are no longer needed
 * @tokens: the actual tokens
 * Return: NULL
 */

void free_tokens(char **tokens)
{
	int i;
	if (tokens != NULL)
	{

		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
	}
}

