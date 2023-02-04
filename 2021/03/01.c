#include <stdio.h>

int main() {
  FILE *f;
  char c;
  int number_of_ones[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 };
  int epsilon, gamma, number_of_lines, index;


  f = fopen("input.txt", "r");

  if (f == NULL) {
    printf("Couldn't find the file.\n");
    return -1;
  }

  number_of_lines = 1;
  epsilon = gamma = 0b000000000000;

  while((c = fgetc(f)) != EOF) {
    switch(c) {
      case '0': {
        index++;
        break;
      }
      case '1': {
        number_of_ones[index]++;
        index++;
        break;
      }
      case '\n': {
        number_of_lines++;
        index = 0;
        break;
      }
      default: {
        printf("File formatting error.\n");
        return -2;
      }
    }
  }

  index = number_of_lines / 2;

  for (int i = 0; i < 12; i++) {
    if (number_of_ones[i] >= index) {
      gamma = (1 << (11 - i)) | gamma;
    } else {
      epsilon = (1 << (11 - i)) | epsilon;
    }
  }

  printf("%d\n", epsilon * gamma);
  
  return 0;
}