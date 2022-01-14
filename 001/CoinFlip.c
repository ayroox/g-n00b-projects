#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main () {
  struct timeval te; 
  gettimeofday(&te, NULL);
  srandom(te.tv_sec*1000LL + te.tv_usec/1000);

  switch(random() % 2) {
    case 0:
      printf("Heads!\n");
      break;
    case 1:
      printf("Tails!\n");
      break;
  }

  return 0;
}