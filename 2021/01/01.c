#include <stdio.h>

int main() {
  FILE *file_pointer;
  int input, last, result;

  file_pointer = fopen("input.txt", "r");

  if (file_pointer == NULL) {
    printf("Coulnd't open the file.\n");
    return 0;
  }

  last = -1;
  result = 0;

  while ((fscanf(file_pointer, "%d", &input)) == 1) {
    if (input > last) result++;
    last = input;
  }

  printf("%d\n", result - 1);

  fclose(file_pointer);
  return 0;
}