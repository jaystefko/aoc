#include <stdio.h>

int main() {
  FILE *file_pointer;
  int grandpa, father, child, last, result;

  file_pointer = fopen("input.txt", "r");

  if (file_pointer == NULL) {
    printf("Coulnd't open the file.\n");
    return 0;
  }

  last = -1;
  result = 0;

  fscanf(file_pointer, "%d", &grandpa);
  fscanf(file_pointer, "%d", &father);

  while ((fscanf(file_pointer, "%d", &child)) == 1) {
    if (grandpa + father + child > last) result++;
    last = grandpa + father + child;
    grandpa = father;
    father = child;
  }

  printf("%d\n", result - 1);

  fclose(file_pointer);
  return 0;
}
