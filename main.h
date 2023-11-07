#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

void display_prompt(void);
char *get_input();
bool is_empty(const char *str);
char **parser(char *input, const char *delim);
int is_whitespace(char ch);
void free_tokens(char **tokens);
int execute(char **tokens);

int _strlen(char *s);
char *_strdup(const char *str);

#endif
