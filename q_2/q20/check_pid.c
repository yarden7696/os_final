#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

int pid = atoi(argv[1]); // here we getting the process number

if(kill(pid,0)==0) printf(" Process %d exists \n", pid);//if process Pid==0 its mean that the process exist
else {
    if(errno==ESRCH) printf(" Process %d does not exist \n" , pid); //ESRCH say that the process not exist
    if(errno==EPERM) printf(" Process %d exists but we have no permission \n", pid); //EPERM the process exist but we cant send him signal
    }
}