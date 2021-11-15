#include <stdio.h>

int main() {
  int array_size;
  //printf("Ange ett tal från 1 till 10: ");
  scanf("%d", &array_size);
  while (array_size > 10 || array_size <= 0) {
    //printf("Ange ett tal från 1 till 10: ");
    scanf("%d", &array_size);
  }
  int list_a[array_size], list_b[array_size];
  //printf("Lista a: ");
  for (int i = 0; i < array_size; i++) {
    scanf("%d", &list_a[i]);
  }
  //printf("Lista b: ");
  for (int j = 0; j < array_size; j++) {
    scanf("%d", & list_b[j]);
  }
  for (int k = 0; k < array_size; k++) {
    printf("%d\n", list_a[k] + list_b[k]);
  }
}





