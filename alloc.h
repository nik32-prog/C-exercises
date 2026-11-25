#ifndef ALLOC_HDR
#define ALLOC_HDR 1
#define BUFSIZE 2000000000
static char buf[BUFSIZE];
static char *np;

char *alloc(long unsigned int n) {
  np = buf;
  if (buf + BUFSIZE - np >= n) {
    np += n;
    return np - n;
  } else {
    return 0;
  }
}

void afree(char *p) {
  if (p > buf && p < buf + BUFSIZE) {
    np = p;
  }
}

#endif
