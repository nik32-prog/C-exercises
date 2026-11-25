#include <stdio.h>
#include "alloc.h"

void main() {
  char *p1, *p2, *p3, *p4, *p5;
  p1 = alloc(1024);
  p1 = "skibidi toilet\n";
  /* now it is time to do a little stress test... */
  for(long int i = 0; i < 1000000000; i++) {
    
    p2 = alloc(9000000000);
    afree(p2);
  }
  // ok now let's make a couple more pointers...
  p3 = alloc(64000);
  // this should return 0...
  if ((p4 = alloc(1000)) == 0) {
    printf("not enough memory in buffer...\n");
  } else {
    printf("a miracle has happened!\n");
    afree(p4);
  }
  p5 = alloc(1);
  afree(p5);
  afree(p3);
  afree(p2);
  printf("%s\n", p1);
  afree(p1);
}
