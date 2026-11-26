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
    if (str[i].tag == TAG_KEEP) {
      buf[i] = str[i].s;
    }
  }
  static tagged_arr arr;
  arr.size = (unsigned long int) size;
  arr.s = buf;
  return arr;
}

int resolvecoms(bool *incom, bool *inlncom, bool *slash, bool *astr, bool *closingastr, bool *instr, bool *escaped, bool *insinglestr, bool keep_str, tagchar_t *str, int index) {
  int retval = 0;
  switch(str[index].s) {
    case '\'':
      if (*slash && *astr && *closingastr) {
        *closingastr = false;
        str[index].tag = TAG_COMM;
        break;
      } else if (*incom || *inlncom || *escaped || *instr) {
        break;
      } else if (*slash && !*astr) {
        *slash = false;
      }
      if (*insinglestr) {
        *insinglestr = false;
        if (!keep_str) {
          str[index].tag = TAG_COMM;
        } else {
          str[index].tag = TAG_KEEP;
        }
      } else {
        *insinglestr = true;
        if (!keep_str) {
          str[index].tag = TAG_COMM;
        } else {
          str[index].tag = TAG_KEEP;
        }
      }
      break;
    case '\"':
      if (*slash && *astr && *closingastr) {
        str[index].tag = TAG_COMM;
        *closingastr = false;
        break;
      } else if (*incom || *inlncom || *escaped || *insinglestr) {
        str[index].tag = TAG_COMM;
        break;
      } else if (*slash && !*astr) {
        *slash = false;
      }
      if (*instr) {
        *instr = false;
        if (!keep_str) {
          str[index].tag = TAG_COMM;
        } else {
          str[index].tag = TAG_KEEP;
        }
      } else {
        *instr = true;
        if (!keep_str) {
          str[index].tag = TAG_COMM;
        } else {
          str[index].tag = TAG_KEEP;
        }
      }
      break;
    case '\\':
      if (*slash && *astr && *closingastr) {
        *closingastr = false;
        str[index].tag = TAG_COMM;
        break;
      } else if (*incom || *inlncom || *escaped) {
        str[index].tag = TAG_COMM;
        break;
      } else if (*slash && !*astr) {
        *slash = false;
      }

      *escaped = true;
      str[index].tag = TAG_COMM;
      break;
    case '/':
      if (*escaped || (*incom && !*closingastr) || *inlncom) {
        str[index].tag = TAG_COMM;
        break;
      } else if (*insinglestr || *instr) {
        if (!keep_str) {
          str[index].tag = TAG_COMM;
        } else {
          str[index].tag = TAG_KEEP;
        }
        break;
      }
      if (!*closingastr) {
        *slash = true;
        str[index].tag = TAG_KEEP;
        break;
      } else if (!*closingastr && *slash) {
        *incom = false;
        str[index].tag = TAG_COMM;
        break;
      } else {
        *inlncom = true;
        str[index    ].tag = TAG_COMM;
        str[index - 1].tag = TAG_COMM;
        break;
      }
    case '*':
      if (*inlncom || *escaped || *instr || *insinglestr) {
        str[index].tag = TAG_COMM;
        break;
      } else if (!*incom && !*slash) {
        str[index].tag = TAG_KEEP;
        break;
      }
      if (*slash && !*incom) {
        *astr = true;
        *incom = true;
        str[index    ].tag = TAG_COMM;
        str[index - 1].tag = TAG_COMM;
        break;
      } else if (*incom && !*closingastr) {
        str[index].tag = TAG_COMM;
        *closingastr = true;
        break;
      } else if (*incom && *closingastr) {
        str[index].tag = TAG_COMM;
        *closingastr = true;
        break;
      }
    case '\n':
      if (*instr || *insinglestr) {
        retval = -1; // syntax error
        break;
      } else if (*inlncom) {
        *inlncom = false;
        str[index].tag = TAG_COMM;
      } else {
        // just a new line
        str[index].tag = TAG_KEEP;
        break;
      }
    default:
      if (*incom || *inlncom) {
        str[index].tag = TAG_COMM;
      } else if ((*instr || *insinglestr) && !keep_str) {
        str[index].tag = TAG_COMM;
      } else {
        str[index].tag = TAG_KEEP;
      }
    
       
  }
  return retval;
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
