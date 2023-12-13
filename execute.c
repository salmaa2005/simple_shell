#include "shell.h"

int _execute(char **command, char **argv, int idx)
{
    char *full_command;
    pid_t child;
    int status;

    full_command = _getpath(command[0]);
    if(!full_command)
    {
        printerror(argv[0], command[0], idx);
        freearray(command);
        return(127);
    }

    child = fork();
    if(child == 0)
    {
        if(execve(full_command, command, environ) == -1)
        {
            free(full_command);
            freearray(command);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        freearray(command);
        free(full_command);
    }
    return(WEXITSTATUS(status));

}