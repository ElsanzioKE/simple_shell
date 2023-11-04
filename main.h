#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_prompt(void);
char *get_input();
char **parser(char *input, const char *delim);
void free_tokens(char **tokens);

int _strlen(char *s);

#endif
