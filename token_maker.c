#include "shell.h"

char **token_maker(char *line)

{
    char *token = NULL;
    char *tmp = NULL;
    char **command = NULL;
    int counter = 0;
    int i = 0;

    if (!line)
    {
        return(NULL);
    }
    tmp = _strdup(line);

    token = strtok(tmp, " \t\n");
    if (token == NULL)
    {
        free(tmp),tmp = NULL;
        free(line),line = NULL;
        return(NULL);  /* In case of nothing inputed by the user*/
    }

    while (token)
    {
        counter++;
        token = strtok(NULL, " \t\n");
    }
    free(tmp), tmp = NULL;

    command = malloc(sizeof(char *) * (counter + 1));  /* +1 for the NULL terminaotr */
    if (!command)
    {
        free(line), line = NULL;
        return(NULL);
    }

    token = strtok(line, " \t\n");

    while (token)
    {
        command[i] = _strdup(token);
        token = strtok(NULL, " \t\n");
        i++;
    }
command[i] = NULL; /* adding the NULL in the end of the token */
free(line);
line = NULL;
return(command);
}
