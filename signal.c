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
{ //signal handler
  printf("Hello World!\n");
  sleep(1);
  
  trigger = 1;
  
  count++;
  
  //exit(1); //exit after printing
}

void handler_2(int signum){ 
  int total;
  
  stop = time(NULL); //keep track of iterations
  
  total = stop - start;
  
  printf("\nNumber of alarm: %d\n in seconds %d\n", count, total);
}
int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT,handler_2); //register handler to handle SIGINT
  
  start = time(NULL);
  
  while(1){//for true 
    trigger = 0;
    alarm(1); //Schedule a SIGALRM for 1 second
     
    while(!trigger);//busy wait for signal to be delivered
      printf("Turing was right!\n");
  }
 
  return 0; //never reached
}
/*int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  //handler is invoked
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1): //busy wait for signal to be delivered
    printf("Turing was right!\n")
  return 0; //never reached
}*/