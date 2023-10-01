#include <stdio.h>

char ft_toupper(char c) {
  if (c >= 'a' && c <= 'z')
    return (c - 'a' + 'A');
  return (c);
}

int main(int ac, char **av) {
  if (ac == 2) {
    printf("character %c is alpha? --> %c", av[1][0], ft_toupper(av[1][0]));
  }
  return (0);
}
