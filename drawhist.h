#ifndef DRAWHIST
#define DRAWHIST 1
#include <stdio.h>
#include <math.h>
// size should be allowed indicies of words
// mode should be 'v' or 'h' to print a vertical or
// horizontal histogram respectively
// words should be an array of numbers
// wid should be target width for the histogram
void drawhist(char mode, int words[], int size, int wid) {
  if (mode == 'h') {
    /* find biggest element in words[] */
    int biggest = 0;
    for (int i = 0; i < size; i++) {
      if (words[i] > biggest) {
        biggest = words[i];
      }
    }
    for (int i = 0; i <= size; i++) {
      printf("%d\n", words[i]);
    }
    /* calculate the scale... */
    //int scale = 1;
    //if (biggest > wid) {
    //  scale = ceil(biggest/wid);
    //}
    for (int i = 0; i < size; i++) {
      printf("%2d|", i + 1);
      for (int j = 0; j < words[i + 1]; j += 1) {
        if (j/1 <= wid) {
          printf("#");
        } else {
          break;
        }
      }
      printf("\n");
    }
    printf("---");
    for (int i = 0; i < wid; i++) {
      printf("-");
    }
    printf("\n");
    for (int i = 0; i < wid/2; i += 1) {
      if (i != 0) {
        printf("%2d", i);
      }
    }
  } else if (mode == 'v') {
        
  } else {
    printf("drawhist: invalid mode");
  }
  return;
}

#endif
