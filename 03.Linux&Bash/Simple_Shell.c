#include <stdio.h>
#include <unistd.h>
#include "signal.h"

//#define MAX_LENGTH 50
void signal_handler(int signum)
{
    printf("Signal %d received\n", signum);
}

void sighand()
{
    for(int i = 0; i < NSIG; i++)
        signal(i, signal_handler);
}

int main() 
{

    signal(SIGINT, sighand);
    printf("process id: %d pressed ctlr + c tp trigger \n", getpid());

    while(1)
    {
        printf("Waiting for signal...\n");
        sleep(1);
    }

    /*char Input[MAX_LENGTH];
    while(1)
    {
        printf("super shell$  ");
        fgets(Input, sizeof(Input), stdin);
       

        if(Input[0] == '\n')
        {
            continue;
        }

        Input[strcspn(Input,"\n")] = '\0';

        if(strcmp(Input, "exit") == 0 || strcmp(Input, "q") == 0)
        {
            printf("Goodbye! Thank you for using the shell.\n");
            break;
        }

        char *cmd = strtok(Input, " ");
        char *args[MAX_LENGTH];
        int i = 0;
        while(cmd != NULL)
        {
            args[i++] = cmd;
            cmd = strtok(NULL, " ");
        }
        args[i] = NULL;

        pid_t child_pid = fork();
        if(child_pid == -1)
        {
            perror("fork failed");
            exit(EXIT_FAILURE);

        }
        else if (child_pid == 0) 
        {
            execvp(args[0], args);
            perror("Execution failed");
            exit(EXIT_FAILURE);
        }
        else
        {
            int status;
            waitpid(child_pid,&status,0);

        }
    }*/



    return 0;
}