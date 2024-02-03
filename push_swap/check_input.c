#include "push_swap.h"

int are_duplicates(char **av)
{
    int i;
    int j;
    i = 0;
    if(ft_atol(av[i]) == __INT64_MAX__)
        i++;
    j = i + 1;
    while(av[i])
    {
        while(av[j])
        {
            if (ft_atol(av[i]) == ft_atol(av[j]))
                display_error();
            j++;
        }
        i++;
        j = i + 1;
    }
    return (0);
}