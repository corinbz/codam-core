#include "push_swap.h"

void display_error(void)
{
   char *error_message = "Error\n";
    write(2, error_message, ft_strlen(error_message));
    exit(1);
}