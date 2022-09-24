#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float float_rand( float min, float max )
{
    float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
    return min + scale * ( max - min );      /* [min, max] */
}

int main(void) {
  srand((unsigned)time(NULL));
  float soucet = 0.0, answer = 0.0;
  int sum = 0, count = 0;

  for (int i = 0; i < 10000000; i++) {
    while (soucet < 1) {
      soucet += float_rand(0.0, 1.0);
      count++;
    }
    soucet = 0;
    sum += count;
    count = 0;
  }
  answer = (float)sum / 10000000;
  printf("Check it out: %f\n", answer);
  return 0;
}
