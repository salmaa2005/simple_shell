#include "shell.h"

int main(int argc, char **argv)


{
    char *line = NULL;
    char **command = NULL;
    int status = 0;
    int i;
    (void) argc;
    (void) argv;


    while(1)
    {
        line = read_line();
        if (line == NULL)  /* EOF or CTRL D */
        {
            if (isatty(STDIN_FILENO) == 1)
            {
                write(STDOUT_FILENO, "\n", 1);
            }
            free(command), command = NULL;
            return(status);
        }

        command = token_maker(line);
        if(!command)
        {
            continue;  /* If the user pressed enter -> continue */
        }

        for(i = 0; command[i]; i++)
        {
            printf("%s\n", command[i]);
            free(command[i]), command[i] = NULL;
        }
        
        
        status = _execute(command, argv);

    }
    
    
    
    free (command), command = NULL;
}


