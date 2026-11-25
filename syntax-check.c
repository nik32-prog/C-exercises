#include <stdio.h>
#include "delcom.h"
#include "splice.h"
#define  SURROUND_LEN 20
#define  BUFSIZE 100000
#define  STACKSIZE 1000
#define  BRACE_TYPES  2

typedef  char brace;

typedef struct {
  brace  start_brace;
  brace    end_brace;
}         brace_pair;

typedef struct {
  unsigned int  line;
  brace_pair       b;
}        stack_frame;

typedef struct {
  unsigned int  line;
  stack_frame *stack;
  int  current_frame;
  char *surroundings;
}         synt_error;

typedef struct {
  char         found;
  char      expected;
  char         *stat;
  int         retval;
}           ret_stat;

typedef unsigned long int idx_t;

static inline void update_surround(char item, char *surround) {
  del(surround, SURROUND_LEN, 0, 0);
  surround[SURROUND_LEN - 1] = item;
  return;
}

static inline int push(stack_frame frame, stack_frame *stack, idx_t *idx) {
  (*idx)++;
  if (*idx < 0 || *idx >= STACKSIZE) {
    return -1;
  }
  stack[*idx] = frame;
  return 0;
}
static inline void pop(stack_frame *stack, idx_t *idx) {
  stack[*idx].b.start_brace = '\0';
  stack[*idx].b.end_brace   = '\0';
  stack[*idx].line          =   0 ;
  (*idx)--;
  
  return;
}

int main(void) {
  brace_pair square;
  square.start_brace = '[';
  square.end_brace = ']';

  brace_pair round;
  round.start_brace = '(';
  round.end_brace = ')';

  brace_pair curly;
  curly.start_brace = '{';
  curly.end_brace = '}';

  brace_pair braces[] = {square, round, curly};
  /******************/
  // very important thing to keep track of
  idx_t curr_ind = 0;
  /******************/
  stack_frame stack[STACKSIZE];
  char s[BUFSIZE], c, *txt;
  unsigned int i = 0;
  ret_stat status;
  status.stat = "OK";
  status.found = '\0';
  status.expected = '\0';
  status.retval = 0;
  while((c = getchar()) != EOF) {
    s[i] = c;
    i++;
  }
  idx_t j = (idx_t)i;
  // delete the comments...
  // idk why i called the function init, but that's just how it is...
  // probably cause i cp'ed some code to a header file, so i didn't know what to change main() to...
  tagged_arr tmp_txt;
  tmp_txt = init(s, false);
  txt = tmp_txt.s;

  // alr time to actually check some syntax !!!
  synt_error err;
  unsigned long int curr_line = 0;
  char curr_surround[SURROUND_LEN];
  for(int i = 0; i < SURROUND_LEN; i++) {
    curr_surround[i] = txt[i];
  }

  for(idx_t i = 0; i < j; i++) {
    
  }
  
  return status.retval;
}
