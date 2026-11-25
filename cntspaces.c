#include <stdio.h>

int main() {
  int tmp;
  int spaces = 0;
  while ((tmp = getchar()) != EOF) {
  	if (tmp == '\n' || tmp == '\t' || tmp == ' ') {
  		spaces++;
  	}
  }

  printf("spaces (tabs, new lines, or spaces):\n%d\n", spaces);
}
