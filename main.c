    #include "shell.h"


    int main(int argc , char *argv[])


    {
        char *line = NULL;
        int status = 0;
        char **command = NULL;

        (void) argc;
        
        while(1)
        {
            
            line = read_line();
            if (line == NULL)                       /* EOF or CTRL D */
            {
                if (isatty(STDIN_FILENO))           /* for non-interactive handling */
                    write(STDOUT_FILENO, "\n", 1);
                return(status);
            }

            /* printf("%s", line);*/

            command = tokenizer(line);
            free(line);

            if(!command)
                continue;

            status = _execute(command, argv);       /* To execute commands (calling execute.c) */

            

        }


    }