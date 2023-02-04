#include <stdio.h>

int main() {
  FILE *f;
  char c;
  int input, current, max;

  f = fopen("input.txt", "r");

  if (f == NULL) {
    printf("Couldn't open the file.\n");
    return -1;
  }

  current = max = 0;

  while (fscanf(f, "%d", &input) == 1) {
    current += input;
    
    fgetc(f);
    c = fgetc(f);

    if (c == '\n') {
      if (current > max) max = current;
      current = 0;
    }
    
    ungetc(c, f);
  }

  if (current > max) max = current;

  printf("%d\n", max);

  return 0;
}