#define _GNU_SOURCE
#include <sched.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <pthread.h>
#include <errno.h>
#include <sys/types.h>
#include <linux/types.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <linux/unistd.h>
#include <time.h>
#include <linux/sched.h>


// To answer this question I used this site-
// https://www.kernel.org/doc/Documentation/scheduler/sched-deadline.txt

#ifdef __x86_64__
#define __NR_sched_setattr 314
#endif
#ifdef __i386__
#define __NR_sched_setattr 351
#endif
#ifdef __arm__
#define __NR_sched_setattr 380
#endif

// this struct is for SCHED_DEADLINE
struct sched_attr {
  __u32 size;
  __u32 sched_policy;
  __u64 sched_flags;
  __u32 sched_priority;
  __u32 sched_nice;

  __u64 sched_runtime;
  __u64 sched_deadline;
  __u64 sched_period;
};

// this function used for SCHED_DEADLINE
int sched_set(pid_t _pid, const struct sched_attr *_attr, unsigned int _flags) {
        return syscall( __NR_sched_setattr, _pid, _attr, _flags);
}

void main(int argc , char* argv[]) {
  
  pid_t _pid  = getpid(); 
  printf("PID of the process : %d\n", _pid); // print to the terminal process`s PID
  int _policy = atoi(argv[1]);
  printf("Policy : %d\n", _policy); // print to the terminal the new policy
  int _priority = atoi(argv[2]);
  printf("Priority : %d\n",_priority); // print to the terminal the new priority

  struct sched_param sp; // sp take care of the policies - 0,1,2,5

   //  SCHED_OTHER = 0,  SCHED_FIFO = 1,  SCHED_RR = 2,  SCHED_IDLE = 5
  if( _policy == 0 || _policy == 1 || _policy == 2 || _policy == 5 ) {
        sp.sched_priority = _priority; 
             if(sched_setscheduler(0, _policy, &sp) == -1) { printf("failed\n"); }
  }

  else if ( _policy == 6 ) { // SCHED_DEADLINE = 6
    struct sched_attr s_attr; // create new struct for SCHED_DEADLINE
    // Putting the values ​​in the fields of the struct
    s_attr.sched_priority = _priority;
    s_attr.sched_policy = SCHED_DEADLINE;
    s_attr.sched_flags = 0; 
    s_attr.size = sizeof(s_attr); 
    s_attr.sched_nice = 0;
    
    s_attr.sched_deadline = 30 * 1000 * 1000;
    s_attr.sched_period = 30 * 1000 * 1000;
    s_attr.sched_runtime = 10 * 1000 * 1000;
    
    sched_set(getpid(), &s_attr, 0); // calling sched_setattr function 
    
  }

  while(1){};

}
