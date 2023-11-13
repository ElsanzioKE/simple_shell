#ifndef MAIN_H
#define MAIN_H
#define MAX_BUFFER_SIZE 1024

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <errno.h>
#include<sys/stat.h>

extern char **environ;

void display_prompt(void);
char *get_input();
char *non_interactive();
bool is_empty(const char *str);
char **parser(char *input, const char *delim);
int is_whitespace(char ch);
void free_tokens(char **tokens);
int execute(char **tokens);
char *find_path(char *command);
void print_command_not_found_error(char *command, int exit_status);
int find_builtin(char **argv);

int _strlen(char *s);
char *_strdup(const char *str);
char *str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);

typedef struct {
	char *name;
	int (*execute_builtins)(char **argv);
} builtin_command;

int my_exit(char **args);

#endif
