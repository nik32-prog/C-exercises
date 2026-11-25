#include <stdio.h>
#include "splice.h"
#define NUM_SPACES 4
#define MXLEN 10000

void main() {
  char txt[MXLEN];
  int tmp, i;
  i = 0;
  while ((tmp = getchar()) != EOF) {
    if (i < MXLEN) {
      txt[i] = tmp;
      i++;
    } else {
      printf("function main() in detab.c:\n\ttext is too long...\n\tterminating\n");
      return;
    }
  }
  int indicies[MXLEN];
  int j = 0;
  for (i = 0; i < MXLEN; i++) {
    // double action: initializing indicies and getting the indicies of all the tabs
    if (txt[i] == '\t') {
      indicies[j] = i;
      j++;
    } else {
      indicies[i] = 0;
    }
  }
  for (i = 0; i < j; i++) {
    del(txt, MXLEN, 0, indicies[i]);
    for (int _i = 0; _i < 4; _i++) {
      splice(txt, MXLEN, 0, indicies[i], ' ');
    }
    for (int _i = 0; _i < j - i; _i++) {
      indicies[_i] += 3;
    }
  }
  for (i = 0; txt[i] != '\0'; i++) {
    putchar(txt[i]);
  }
  putchar('\n');
}
