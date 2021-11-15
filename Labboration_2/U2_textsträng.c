#include <stdio.h>

int main() {
  char message[100];
  scanf("%s", &message);
  for (int i = 0; message[i] != 0; i++) {
    message[i] -= 3;
  }
  printf("%s", message);
}
