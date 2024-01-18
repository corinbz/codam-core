#include "push_swap.h"

int are_duplicates(char **av)
{
    int i;
    int j;
    i = 1;
    j = i + 1;
    while(av[i])
    {
        while(av[j])
        {
            // printf("i is %i\nj is %i\n",i,j);
            // printf("comparing %i with %i\n",atoi(av[i]),atoi(av[j]));
            if (atoi(av[i]) == atoi(av[j]))
                return (1);
            j++;
        }
        i++;
        j = i + 1;
    }
    return (0);
}