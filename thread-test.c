#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "splice.h"
void *calconnewthread(void *) {
  srand(time(NULL));
  while(1) {
    double d = sqrt(rand());
  }
  return NULL;
}

void main(int argc, char *argv[]) {
  int threadnum;
  int SLEEPTIME = 10;
  if (argc == 1) {
    threadnum = 8;
    printf("info: using 8 cores by default as no argument was provided...\n");
  } else {
    int opt;

    while ((opt = getopt(argc, argv, "hc:s:")) != -1) {
      switch (opt) {
        case 'h':
          printf("usage: %s [-h] [-c number of threads to be involved in stress testing] [-s time in seconds (default is 10)]\n", argv[0]);
          return;
        case 'c':
          threadnum = atoi(optarg);
          break;
        case 's':
          SLEEPTIME = atoi(optarg);
          break;
      }
    }
  }
  pthread_t t1, t2, t3, t4, t5, t6, t7, t8;
  printf("info: this program uses a maximum of 8 threads.\nright now using: %d threads\n", threadnum);
  if (threadnum >= 1) {
    printf("info: starting thread t1...\n");
    if (pthread_create(&t1, NULL, calconnewthread, NULL) != 0) {
      perror("failed to create thread t1.\n");
      return;
    }
    printf("info: started thread t1 successfully with an id of %ld.\n", t1);
  }
  
  if (threadnum >= 2) {
    printf("info: starting thread t2...\n");
    if (pthread_create(&t2, NULL, calconnewthread, NULL) != 0) {
      perror("failed to create thread t2.");
      return;
    }
    printf("info: started thread t2 successfully with an id of %ld.\n", t2);
  }
  
  if (threadnum >= 3) {
    printf("info: starting thread t3...\n");
    if (pthread_create(&t3, NULL, calconnewthread, NULL) != 0) {
      perror("failed to create thread t3.");
      return;
    }
    printf("info: started thread t3 successfully with an id of %ld.\n", t3);
  }
  
  if (threadnum >= 4) {
    printf("info: starting thread t4...\n");
    if (pthread_create(&t4, NULL, calconnewthread, NULL) != 0) {
      perror("failed to create thread t4.");
      return;
    }
    printf("info: started thread t4 successfully with an id of %ld.\n", t4);
  }
  
  if (threadnum >= 5) {
    printf("info: starting thread t5...\n");
    if (pthread_create(&t5, NULL, calconnewthread, NULL) != 0) {
      perror("failed to create thread t5.");
      return;
    }
    printf("info: started thread t5 successfully with an id of %ld.\n", t5);
  }

  if (threadnum >= 6) {
    printf("info: starting thread t6...\n");
    if (pthread_create(&t6, NULL, calconnewthread, NULL) != 0) {
      perror("failed to create thread t6.");
      return;
    }
    printf("info: started thread t6 successfully with an id of %ld.\n", t6);
  }
  
  if (threadnum >= 7) {
    printf("info: starting thread t7...\n");
    if (pthread_create(&t7, NULL, calconnewthread, NULL) != 0) {
      perror("failed to create thread t7.");
      return;
    }
    printf("info: started thread t7 successfully with an id of %ld.\n", t7);
  }
  
  if (threadnum >= 8) {
    printf("info: starting thread t8...\n");
    if (pthread_create(&t8, NULL, calconnewthread, NULL) != 0) {
      perror("failed to create thread t8.");
      return;
    }
    printf("info: started thread t8 successfully with an id of %ld.\n", t8);
  }

  printf("info: no more threads to create...\ninfo: sleeping for %d seconds...\n", SLEEPTIME);
    
  sleep(SLEEPTIME);
  return;
}
