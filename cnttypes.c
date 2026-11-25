#include <stdio.h>

void main() {
  int num, tmp, i, white, other;
  int digits[10];

  white = other = 0;
  for (i = 0; i < 10; i++) {
    digits[i] = 0;
  }
  while ((tmp = getchar()) != EOF) {
    if (tmp >= '0' && tmp <= '9') {
      digits[tmp - '0']++;
    } else if (tmp == ' ' || tmp == '\n' || tmp == '\t' || tmp == '\v') {
      white++;
    } else {
      other++;
    }
  }
  printf("digits:\n");
  for (i = 0; i < 10; i++) {
    printf("%d's:\t%d\n", i, digits[i]);
  }
  printf("whitespaces:\t%d\n", white);
  printf("other characters:\t%d\n", other);  
}
