#include <stdio.h>
#include <math.h>
#define PI 3.141592


int input_accuracy(double* a){
  printf("Введите точность до 6 знаков после запятой: ");
  if((scanf("%lf", a) != 1))
  {
      printf("Ошибка!\n");
      return 1;
  }
  return 0;
}

int input_corner(int* c){
  printf("Введите угол: ");
  if((scanf("%d", c) != 1))
  {
      printf("Ошибка!\n");
      return 1;
  }
  return 0;
}

double radian(int deg){
  return deg * (PI/180);
}

int factorial(int n){
  int fact = 1;
  int i;
  if (n < 0){
        printf("Ошибка! Факториал отрицательного числа не существует");
        return 0;
  }
  else {
        for (i = 1; i <= n; ++i) {
            fact *= i;
        }
  }
  return fact;
}

double teylor(double rad, double acc){
  double ans = 1;
  double tey;
  short p = -1;
  double i = 2.0;

  tey = (pow(rad, i) / factorial( (int)i ));
  while (tey > acc){
    ans += p*tey;
    i += 2.0;
    tey = (pow(rad, i) / factorial(i));
    p *= -1;
  }
  return ans;
}

int main() {
  double accuracy, rad, cosinus;
  int degrees;

  if (input_accuracy(&accuracy) == 1) return 1;
  if (input_corner(&degrees) == 1) return 1;

  rad = radian(degrees);
  printf("Угол в радианах %lf\n", rad);

  cosinus = teylor(rad, accuracy);
  printf("Косинус приблизительный, с помощью рядов Тейлора %lf\n", cosinus);
  printf("Косинус точный %lf\n", cos(rad));

  return 0;
}
