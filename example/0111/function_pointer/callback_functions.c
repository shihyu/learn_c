/* This code catches the alarm signal generated from the kernel
   Asynchronously 
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
 
struct sigaction act;
 
/* signal handler definition goes here */
void sig_handler(int signo, siginfo_t *si, void *ucontext)
{
   printf("Got alarm signal %d\n",signo);
   /* do the required stuff here */
}
 
int main(void)
{
    act.sa_sigaction = sig_handler;
    act.sa_flags = SA_SIGINFO;
 
    /* register signal handler */
    sigaction(SIGALRM, &act, NULL);  
    /* set the alarm for 10 sec */       
    alarm(10);   
    /* wait for any signal from kernel */                                        
    pause();  
    /* after signal handler execution */                                             
    printf("back to main\n");                     
    return 0;
}
