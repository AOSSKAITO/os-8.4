#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>

#define K 1024
#define SIZE 1024*100
int main(int ac,char *av[]){
    
    int i,j,count;
    char *pool = (char *)malloc(SIZE*K);
    count = 0;
    j = 0;
    if (mlock((char *)main , 4096)) {
      perror("main mlock");
	     exit(1);
    }
    if (mlock((char *)pool , SIZE*K)) {
      perror("pool mlock");
	     exit(1);
    }
  for(;;) {
	   for(i = 0; i < SIZE*K; i++) {
	      pool[i] = j++;
	     }
	fprintf(stderr,"loop %5d\n",count++);
  }
}