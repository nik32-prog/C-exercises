#include <stdio.h>

void main() {
  int tmp;
  tmp = getchar();

  while (tmp != EOF) {
    switch (tmp) {
      case '\t':
        printf("\\t");
        break;
      case '\b':
        printf("\\b");
      case '\\':
        printf("\\\\");
    }
  }
}
