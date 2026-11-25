#include <stdio.h>
#define MXLN 1000
#define MNLN 80

void prln(char ln[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%c", ln[i]);
  }
  printf("\n");
}

void clear(char ln[], int size) {
  for (int i = 0; i < size; i++) {
    ln[i] = 0;
  }
}

void main() {
  char ln[MXLN];
  char tmp;
  int chars = 0;
  int i = 0;
  tmp = getchar();
  while (tmp != EOF) {
    if (tmp != '\n') {
      chars++;
      ln[i] = tmp;
      i++;
    } else {
      if (chars > MNLN) {
        prln(ln, chars);
        
      }
      chars = 0;
      clear(ln, MXLN);
    }
    tmp = getchar();
  }
}
