#include <stdio.h>

char ft_tolower(char c) {
  if (c >= 'A' && c <= 'Z')
    return (c - 'A' + 'a');
  return (c);
}

int main(int ac, char **av) {
  if (ac == 2) {
    printf("character %c is alpha? --> %c", av[1][0], ft_tolower(av[1][0]));
  }
  return (0);
}
