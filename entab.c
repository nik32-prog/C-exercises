#include "splice.h"
#include <stdio.h>
#define MXLEN 10000
#define MXTABS 1000
#define TRUE 1
#define FALSE 0
#define TABSIZE 4

int checktrue(int *buf, int size) {
  if (size <= 0) {
    return FALSE;
  }
  int possible = TRUE;
  for (int i = 0; i < size; i++) {
    if (buf[i] == FALSE) {
      possible = FALSE;
    }
  }
  return possible;
}

int main() {
  char buf[MXLEN];
  int tmp, i, j;
  for (i = 0; (tmp = getchar()) != EOF; i++) {
    buf[i] = tmp;
  }
  int indicies[MXTABS];
  /*
  i is now (the biggest initialized index of buf) + 1...
  */
  int _i = 0;
  int tmpi = 0;
  int intab = FALSE;
  int tmpbuf[TABSIZE];
  for (j = 0; j < i; j++) {
    if (buf[j] == ' ' && intab == FALSE) {
      intab = TRUE;
      wipe(tmpbuf, TABSIZE);
      tmpbuf[0] = TRUE;
    } else if (buf[j] == ' ' && intab == TRUE) {
      tmpi++;
      tmpbuf[tmpi] = TRUE;
    }
    if (checktrue(tmpbuf, TABSIZE) == TRUE) {
      indicies[_i] = j - TABSIZE + 1;
      _i++;
    }
  }
  for (int _j = 0; _j < _i; _j++) {
    for (int i = 0; i < TABSIZE; i++) {
      if (del(buf, MXLEN, 0, indicies[_j]) == -1) {
        printf("exiting due to fatal error...\n");
        return -1;
      }
    }
    if (splice(buf, MXLEN, 0, indicies[_j], '\t') == -1) {
      printf("exiting due to fatal error... \n");
      return -1;
    }
  }
  for (int index = 0; index < i; index++) {
    putchar(buf[index]);
  }
  return 0;
}
