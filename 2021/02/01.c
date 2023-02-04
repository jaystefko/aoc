#include <stdio.h>

int main() {
  FILE *f;
  char c;
  int input, horizontal, depth;

  f = fopen("input.txt", "r");

  if (f == NULL) {
    printf("Couldn't open the file.\n");
    return -1;
  }

  horizontal = depth = 0;

  while ((c = fgetc(f)) != EOF) {
    while (fgetc(f) != ' ') {}
    fscanf(f, "%d", &input);
    fgetc(f);
    
    switch (c) {
      case 'f': {
        horizontal += input;
        break;
      }
      case 'u': {
        depth -= input;
        break;
      }
      case 'd': {
        depth += input;
        break;
      }
      default: {
        printf("Wierd error\n");
        fclose(f);
        return -2;
      }
    }
  }

  printf("%d\n", horizontal * depth);

  fclose(f);
  return 0;
}