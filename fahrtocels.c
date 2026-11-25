#include <stdio.h>
#define LOW -100
#define HIGH 100
#define STEP 10

float fahrtocels(float fahr) {
  float cels = ((fahr - 32) * 5) / 9;
  return cels;
}

void main() {
  printf("farenheit\tcelsius\n");
  for (float fahr = LOW; fahr <= HIGH; fahr += STEP) {
    printf("%3.2f\t\t%3.2f\n", fahr, fahrtocels(fahr));
  }
}
