#ifndef SHELL_H
#define SHELL_H

extern char **environ;

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* STRINGS */

size_t _strlen(char *s);
void _puts(char *str);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);
char *_strdup(const char *str);
char *_strncpy(char *destination, char *source, int n);

/* TOOLS */

char *read_line(void);
char **tokenizer(char *line);
void freearray(char **arr);
int _execute(char **command, char **argv);

/* myStrtok */

int check_delimiter(char c, char *delimiter);
int count_tokens(char *string, char *delimiter);
char **_strtok(char *string, char *delimiter);

#endif
