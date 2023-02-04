#include <stdio.h>

int main() {
  FILE *f;
  char c;
  int input, horizontal, depth, aim;

  f = fopen("input.txt", "r");

  if (f == NULL) {
    printf("Couldn't open the file.\n");
    return -1;
  }

  horizontal = depth = aim = 0;

  while ((c = fgetc(f)) != EOF) {
    while (fgetc(f) != ' ') {}
    fscanf(f, "%d", &input);
    fgetc(f);
    
    switch (c) {
      case 'f': {
        horizontal += input;
        depth += (input * aim);
        break;
      }
      case 'u': {
        aim -= input;
        break;
      }
      case 'd': {
        aim += input;
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