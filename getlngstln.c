#include <stdio.h>
#define MXLEN 1000

int getln(char ln[], int lim) {
  int i, c;
  int tmp = -1;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    if (i < lim - 1) {
      ln[i] = c;
    } else {
      tmp = i;
    }
  }
  if (tmp == -1) {
    tmp = i;
  }
  if (c == '\n') {
    ln[tmp] = c;
    tmp++;
  }
  ln[tmp] = '\0';
  return i;
}

void cp(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0') {
    i++;
  }
  return;
}

void main() {
  int strlenrn;
  int mxlensf;
  char ln[MXLEN];
  char longest[MXLEN];

  mxlensf = 0;
  while ((strlenrn = getln(ln, MXLEN)) > 0) {
    if (strlenrn > mxlensf) {
      mxlensf = strlenrn;
      cp(longest, ln);
    }
  }
  if (mxlensf > 0) {
    printf("longest line:\n%s\n", longest);
  }
  return;
}
