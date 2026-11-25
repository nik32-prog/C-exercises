#include <stdio.h>
#include "drawhist.h"
#define MAXLEN 25
#define OUT 0
#define IN 1
#define TARGWID 25

int main() {
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
  drawhist('h', words, MAXLEN, TARGWID);
  return 0;
}
