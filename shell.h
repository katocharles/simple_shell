#ifndef SHELL_HEADER
#define SHELL_HEADER

/*Included header files*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*prototypes*/
int main(int argc, char *argv[], char **env);
void prompt(void);
char *get_command(void);

/* string prototypes */
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);

#endif
