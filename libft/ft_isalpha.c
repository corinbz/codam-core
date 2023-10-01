#include <stdio.h>

int ft_isalpha(char c) {
  if ((c > 'a' && c < 'z') || (c > 'A' && c < 'Z'))
    return (1);
  return (0);
}

int main(int ac, char **av) {
  if (ac == 2) {
    printf("character %c is alpha? --> %d", av[1][0], ft_isalpha(av[1][0]));
  }
  return (0);
}
