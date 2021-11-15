#include <stdio.h>

void calc(float param1, float param2, char operator);

int main() {
  float a, b;
  char op;
  scanf("%f %c %f", &a, &op, &b);
  calc(a, b, op);
}

void calc(float param1, float param2, char operator){
  float result = 1;
  switch (operator){
    case '+':
      printf("%g", param1+param2);
      break;
    case '-':
      printf("%g", param1-param2);
      break;
    case '*':
      printf("%g", param1*param2);
      break;
    case '/':
      if(param2 == 0){
        printf("NaN");
      }
      else{
        printf("%g", param1/param2);
      }
      break;
    case '^':
      if(param2 > 0){
        for (int i=0; i < param2; i++)
        {
          result *= param1;
        }
      }
      else if(param2 < 0){
        param2 *= -1;
        for (int i=0; i < param2; i++)
        {
          result /= param1;
        }
      }
      printf("%g", result);
      break;
    default: 
      printf("Ej en giltig funktion!");
  }
}
