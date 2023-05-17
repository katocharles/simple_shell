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

#endif

