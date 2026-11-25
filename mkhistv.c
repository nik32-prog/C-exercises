#include <stdio.h>
#define MAXLEN 25
#define MAXWID 75
#define IN 1
#define OUT 0

void drawgraph(int words[], int mxheight, int mxwid) {
  int tmp = 0;
  int j, i;
  for (i = 0; i <= mxwid; i++) {
    j = words[i];
    if (j > tmp) {
      tmp = j;
    }
  }
  if (tmp > mxheight) {
    tmp = mxheight;
  }
  
  int height = tmp;
  for (int i = height; i > 0; i--) {
    printf("%2d", i);
    for (int j = 0; j < mxwid; j++) {
      int tmp = words[j];
      if (tmp >= i) {
        printf("| #");
      } else {
        printf("|  ");
      }
    }
    printf("\n");
  }
  for (int i = 0; i < mxwid; i++) {
    printf("---");
  }
  printf("\n  ");
  for (int i = 0; i < mxwid; i++) {
    printf(" %2d", i + 1);
  }
  printf("\n");
  
}

void main() {
  int tmp, state, chars;
  int words[MAXLEN + 1];
  for (int i = 0; i <= MAXLEN; i++) {
    words[i] = 0;
  }
  chars = 0;
  tmp = 0;
  state = OUT;
  do {
    tmp = getchar();
    if (tmp != ' ' && tmp != '\n' && tmp != '\t') {
      state = IN;
      chars++;
    } else {
      if (state == IN) {
        state = OUT;
        words[(chars - 1)]++;
        chars = 0;
      } else {
        state = OUT;
      }
    }
  } while (tmp != EOF);
  int mxwid = MAXLEN + 1;
  int mxheight = MAXWID;
  printf("\n");
  drawgraph(words, mxheight, mxwid);
}
