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
  char                *s;
  unsigned long int size;
} tagged_arr;

tagged_arr delTaggedComsAndPrint(tagchar_t *str, int size, char *buf) {
  if (size <= 0) {
    size = MXLEN;
  }
  
  for (int i = 0; i < size; i++) {
    // printf("char:\t%c\ttag:\t%c\t\t", (*(str + i)).s, (*(str + i)).tag);
    if ((*(str + i)).tag == TAG_KEEP) {
      buf[i] = (*(str + i)).s;
    }
  }
  tagged_arr arr;
  arr.size = (unsigned long int) size;
  arr.s = buf;
  return arr;
}

void resolvecoms(bool *incom, bool *inlncom, bool *slash, bool *astr, bool *closingastr, bool *instr, bool keep_str, tagchar_t *str, int index) {
  switch(str[index].s) {
    case '/':
      if (*instr) {
        break;
      }
      if ( *inlncom ) {
        str[index].tag = TAG_COMM;
      } else if ( !( *incom ) && !( *inlncom ) && !( *slash )) {
        *slash = true;
      } else if ( *slash && !( *astr ) ) {
        *inlncom = true;
        str[index].tag     = TAG_COMM;
        str[index - 1].tag = TAG_COMM;
      } else if ( *closingastr ) {
        *inlncom = *astr = *closingastr = *slash = *incom = false;
        str[index].tag = TAG_COMM;
      }
      break;
    case '*':
      if (*instr) {
        break;
      }
      if ( *inlncom ) {
        ;
      } else if ( !( *slash ) ) {
        break;
      } else if ( *slash && !( *astr ) ) {
        *astr = true;
        *incom = true;
        str[index - 1].tag = TAG_COMM;
        str[index].tag     = TAG_COMM;
      } else if ( *astr ) {
        *closingastr = true;
      }
      break;
    case '\n':
      if ( *inlncom ) {
        *inlncom = false;
        str[index].tag = TAG_COMM;
      } else {
        str[index].tag = TAG_KEEP;
      }
      *closingastr = false;
      break;
    case '\"':
      if (*incom || *inlncom) {
        break;
      }
      if (!keep_str) {
        if (*instr) {
          str[index].tag = TAG_COMM;
          *instr = false;
        } else {
          *instr = true;
        }
      }
      break;
      
    default:
      str[index].tag = TAG_KEEP;
      *closingastr = false;
  }
  if (*incom || *inlncom || (*instr && !keep_str)) {
    str[index].tag = TAG_COMM;
  } else if (str[index].tag != TAG_COMM){
    str[index].tag = TAG_KEEP;
  }
  if (str[index].s != '/' && str[index].s != '*' && !( *incom ) && !( *inlncom )) {
    *slash = *astr = *closingastr = false;
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
  bool incom = false, inlncom = false, slash = false, astr = false, closingastr = false, instr = false;
  for(int j = 0; j < i; j++) {
    resolvecoms(&incom, &inlncom, &slash, &astr, &closingastr, &instr, keep_str, str, j);
  }
  return delTaggedComsAndPrint(str, i, buf);
}

#endif // DELCOMS
