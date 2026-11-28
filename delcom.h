#ifndef DELCOMS
#define DELCOMS 1

#include <stdio.h>
#define TAG_KEEP 'k'
#define TAG_END  'e'
#define TAG_NONE 'n'
#define TAG_COMM 'c'
#define MXLEN 100000

typedef struct {
  char s;
  char tag;
} tagchar_t;

typedef struct {
  char       *s;
  long int size;
} tagged_arr;

tagged_arr delTaggedComsAndPrint(tagchar_t *str, int size, char *buf) {
  if (size <= 0) {
    size = MXLEN;
  }
  
  for (int i = 0; i < size; i++) {
    if (str[i].tag == TAG_KEEP) {
      buf[i] = str[i].s;
    }
  }
  static tagged_arr arr;
  arr.size = (unsigned long int) size;
  arr.s = buf;
  return arr;
}


void backslashhandler(bool incom, bool inlncom, bool slash, bool astr, bool closingastr, bool instr, bool escaped, bool insinglestr, bool keep_str, tagchar_t *str, int index) {
    
}

void charhandler(bool incom, bool inlncom, bool slash, bool astr, bool closingastr, bool instr, bool escaped, bool insinglestr, bool keep_str, tagchar_t *str, int index) {
  
}

void quotehandler(bool incom, bool inlncom, bool slash, bool astr, bool closingastr, bool instr, bool escaped, bool insinglestr, bool keep_str, tagchar_t *str, int index) {
  
}

void asterikhandler(bool incom, bool inlncom, bool slash, bool astr, bool closingastr, bool instr, bool escaped, bool insinglestr, bool keep_str, tagchar_t *str, int index) {
  
}

void slashhandler(bool incom, bool inlncom, bool slash, bool astr, bool closingastr, bool instr, bool escaped, bool insinglestr, bool keep_str, tagchar_t *str, int index) {
  
}

void defaulthandler(bool incom, bool inlncom, bool slash, bool astr, bool closingastr, bool instr, bool escaped, bool insinglestr, bool keep_str, tagchar_t *str, int index) {
  
}

int resolvecoms(bool *incom, bool *inlncom, bool *slash, bool *astr, bool *closingastr, bool *instr, bool *escaped, bool *insinglestr, bool keep_str, tagchar_t *str, int index) {
  switch(str[index].s) {
    case '\\':
      backslashhandler(&incom, &inlncom, &slash, &astr, &closingastr, &instr, &escaped, &insinglestr, &keep_str, str, index);
    case '\'':
      charhandler(     &incom, &inlncom, &slash, &astr, &closingastr, &instr, &escaped, &insinglestr, &keep_str, str, index);
    case '\"':
      quotehandler(    &incom, &inlncom, &slash, &astr, &closingastr, &instr, &escaped, &insinglestr, &keep_str, str, index);
    case '/':
      slashhandler(    &incom, &inlncom, &slash, &astr, &closingastr, &instr, &escaped, &insinglestr, &keep_str, str, index);
    case '*':
      asterikhandler(  &incom, &inlncom, &slash, &astr, &closingastr, &instr, &escaped, &insinglestr, &keep_str, str, index);
  }
}

tagged_arr init(char txt[], bool keep_str) {
  tagchar_t str[MXLEN];
  char s;
  static char buf[MXLEN];
  int i = 0;
  while((s = txt[i]) != '\0') {
    str[i].s = s;
    str[i].tag = TAG_NONE;
    i++;
  }
  str[i].s = '\0';
  str[i].tag = TAG_END;
  bool incom = false, escaped = false, isinsinglestr = false, inlncom = false, slash = false, astr = false, closingastr = false, instr = false;
  for(int j = 0; j < i; j++) {
    if (resolvecoms(&incom, &inlncom, &slash, &astr, &closingastr, &instr, &escaped, &isinsinglestr, keep_str, str, j) == -1) {
      static tagged_arr retarr;
      retarr.s = "syntax error\n";
      retarr.size = -1;
      return retarr;
    }
  }
  return delTaggedComsAndPrint(str, i, buf);
}

#endif // DELCOMS
