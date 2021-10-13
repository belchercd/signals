/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int trigger = 0;
int count = 0;
time_t start, stop;

void handler(int signum)
{ 
  sleep(1);
  
  trigger = 1;
  
  count++;
  
}
void handler_2(int signum){ 
  int total;
  
  stop = time(NULL); //track iterations
  
  total = stop - start;
  
  printf("\nNumber of alarm: %d\n in seconds %d\n", count, total);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT,handler_2); //register handler to handle SIGINT
  
  start = time(NULL);
  
  while(1){//while true 
    trigger = 0;
    alarm(1); //Schedule a SIGALRM for 1 second
     
    while(!trigger); //wait for signal to be delivered
      printf("Turing was right!\n");
  }
 
  return 0; 
}
