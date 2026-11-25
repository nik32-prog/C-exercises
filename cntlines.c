#include <stdio.h>

void main() {
  int lines, tmp;
  lines = 0;
  while ((tmp = getchar()) != EOF) {
    if (tmp == '\n') {
      lines++;
    }
  }
  printf("lines:\n%d\n", lines);
  /* just to find out what EOF is...  */
  printf("EOF is %d\n", tmp);
}
