#include <stdio.h>

int main() {
  FILE *f;
  char c;
  int input, current, max, max2, max3;

  f = fopen("input.txt", "r");

  if (f == NULL) {
    printf("Couldn't open the file.\n");
    return -1;
  }

  current = max = max2 = max3 = 0;

  while (fscanf(f, "%d", &input) == 1) {
    current += input;
    
    fgetc(f);
    c = fgetc(f);

    if (c == '\n') {
      if (current > max) {
        max2 = max;
        max = current;
      }
      else if (current > max2) {
        max3 = max2;
        max2 = current;
      }
      else if (current > max3) max3 = current;
      current = 0;
    }
    
    ungetc(c, f);
  }

  if (current > max) {
    max2 = max;
    max = current;
  }
  else if (current > max2) {
    max3 = max2;
    max2 = current;
  }
  else if (current > max3) max3 = current;

  printf("%d\n", max + max2 + max3);

  return 0;
}