#ifndef SPLICE
#include <stdio.h>
#define SPLICE 1

void wipe(int array[], int size) {
  for (int i = 0; i < size; i++) {
    array[i] = 0;
  }
}

// i is the starting position, j is the ending position
int swap(char str[], int size, int i, int j) {
  if (i >= size || j >= size || i < 0 || j < 0) {
    printf("function: swap() in header file splice.h:\nfatal error:params i and j are not allowed indicies\n");
    return -1;
  }
  char tmp;
  tmp = str[i];
}

// size should be the char str[size] in initialization
// datasize should be the last index that contains useful data. if datasize is set to 0 (it does not matter to you)
// then size-1 will be used
int splice(char str[], int size, int datasize, int index, char item) {
  if (datasize == 0) {
    datasize = size - 1;
  } else if (datasize >= size) {
    printf("function splice() in splice.h:\n\twarning: datasize is more or equal to size.\n\tsetting datasize = size - 1 ...\n");
    datasize = size - 1;
  }
  if (index < 0 || index >= size) {
    printf("function splice() in splice.h:\n\tfatal error: index is out of bounds\n\tterminating...\n");
    return -1;
  }
  if (index >= datasize) {
    printf("function splice() in splice.h: \n\twarning: index is out of data range\n\tsetting datasize to index + 1...\n");
    datasize = index + 1;
  }
  int val = 0;
  for (int i = 0; i < datasize - index; i++) {
    if (swap(str, size, datasize - i - 1, datasize - i) == -1) {
      printf("function splice() in splice.h:\n\tfatal error in function swap()\n\tterminating...\n");
      val = -1;
      break;
    }
  }
  if (val == -1) {
    return -1;
  }
  str[index] = item;
  return 0;
}

int del(char str[], int size, int datasize, int index) {
  if (datasize == 0) {
    datasize = size - 1;
  } else if (datasize >= size) {
    printf("function del() in splice.h:\n\twarning: datasize is more or equal to size.\n\tsetting datasize = size - 1 ...\n");
    datasize = size - 1;
  }
  if (index < 0 || index >= size) {
    printf("function del() in splice.h:\n\tfatal error: index is out of bounds\n\tterminating...\n");
    return -1;
  }
  if (index >= datasize) {
    printf("function del() in splice.h: \n\twarning: index is out of data range\n\tsetting datasize to index + 1...\n");
    datasize = index + 1;
  }
  for (int i = 0; i < datasize - index; i++) {
    str[index + i] = str[index + i + 1];
  }
}

#endif
