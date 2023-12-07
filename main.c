#include "shell.h"


int main(int argc , char *argv[])


{
    (void) argc;
    (void) argv;
    
    while(1)
    {
        char *line = NULL;
        int status = 0;
        
        line = read_line();
        if (line == NULL) /* EOF */
        {
            if (isatty(STDIN_FILENO)) /* for non-interactive handling */
                write(STDOUT_FILENO, "\n", 1);
            return(status);
        }
        printf("%s", line);
        free(line);
    }

}