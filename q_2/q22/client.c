#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

// The client's job is to send signals to the server.
// He can only send 2 types of signals: SIGINT or SIGURS1.
// If he send a signal that is not one of these, then- exit (0) will be performed.

int main(int argc, char *argv[]){

	int pidServer = atoi(argv[1]);
	int signal_num = atoi(argv[2]); // there is tow options of signals: SIGINT=2, SIGURS1=10
	int sgnls_toSend = atoi(argv[3]); // Total number of signals that the client send to the server

	if(signal_num!=2 && signal_num!=10) 
		exit(0); // caz the client can send just signal number 2 or 10

	else // client send to the server signal number 2 or 10
		while (sgnls_toSend > 0) {
			sgnls_toSend--;
			kill(pidServer,signal_num);	// send signal to the server by using kill  
	}	
}

