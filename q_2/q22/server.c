#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>

// The server`s job is to count the number of signals that received by the client.
// The SIGINT handler counts the number of SIGINT signals that received to the server.
// The SIGURS1 handler prints the number of SIGINT signals that have reached to the server.

static int counter = 0; 

void _handler(int signal) {

    if(signal==2)
	 	counter++; // Counting the number of SIGINT signals that received to the server 
		 
    else if(signal==10)  
	    // Print the number of SIGINT signals that have reached the server
		printf("\n A total of %d SIGINT signals reached to the server \n",counter);	
}

int main() {
	printf("Server`s PID : %d\n", getpid()); // print server`s pid to the terminal	
	while(1) {  // getting signals that sending by the client 
		signal(SIGUSR1,_handler);
		signal(SIGINT,_handler);
	}
	return 0;					
}
