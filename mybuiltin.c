#include "shell.h"

int isbuiltin(char *command)

{
    char *builts[] = 
    {
        "exit", "env", NULL
    };
    int counter;

    for (counter = 0; builts[counter]; counter ++)
    {
        if (_strcmp(command, builts[counter]) == 0)
            return(1);
    }
    return(0);
}

void handling_builtin(char **command, char **argv, int *status, int idx)
{
    (void) argv;
    (void) idx;

    if (_strcmp(command[0], "exit") == 0)
    {
        if (command[1] != NULL)
        {
            *status = atoi(command[1]);
            exiting_shell(command, status);
        }
        else
        {
            *status = 0;
            exiting_shell(command, status);
        }
    }
    else if (_strcmp(command[0], "env") == 0)
    {
        printenv(command, status);
    }
}


void exiting_shell(char **command, int *status)
{
    freearray(command);
    exit(*status);
}

void printenv(char **command, int *status)
{
    int counter;

    for (counter =0; environ[counter]; counter ++)
    {
        write(STDOUT_FILENO, environ[counter], _strlen(environ[counter]));
        write(STDOUT_FILENO, "\n", 1);
    }
    freearray(command);
    (*status )= 0;
}