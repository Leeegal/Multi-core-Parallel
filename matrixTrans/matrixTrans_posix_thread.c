/**
 * Matrix (N*N) multiplication with multiple threads.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

#define ROWS 500
#define COLS 500
int matrix[ROWS][COLS];
int result[COLS][ROWS];

void initMatrix() {
  int num = 0;
  printf("Before transpose:\n");
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      matrix[i][j] = num++;
      // printf("%d ", matrix[i][j]);
    }
    // printf("\n");
  }
  // printf("\n");
}

void printResult() {
  for(int i = 0; i < COLS; i++) {
    for(int j = 0; j < ROWS; j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void* run(void *n) {
  int index = ((int)n) - 1;
  // if(index == 0) {
  //   printf("zero 2");
  // }
  // printf("number: %d\n", index);

  for(int i = 0; i < COLS; i++) {
    result[i][index] = matrix[index][i];
  }
}

int main() {
  time_t start = clock();
  initMatrix();
  pthread_t threads[ROWS];
  for(int i = 0; i < ROWS; i++) {
     int rc = pthread_create(&threads[i], NULL, run, (void *)(i + 1));
    if(rc) {
      printf("[error] return code from pthread_create() is %d\n", rc);
    }
  }
  for(int i = 0; i < ROWS; i++) {
    pthread_join(threads[i], NULL);
  }

  time_t end = clock();
  // printResult();
  printf("the running time is : %f\n", (double)(end -start)/CLOCKS_PER_SEC);
}
