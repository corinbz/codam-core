#include "push_swap.h"

int check_max_bits(node **head)
{
    node *a = find_max(*head);
    int max_bits = 0;
    unsigned long temp_index = a->index; // Store the index value in a temporary variable
    while(temp_index != 0)
    {
        temp_index = temp_index >> 1;
        max_bits++;
    }
    return max_bits;
}

void radix_sort(node **a,node **b)
{
    // printf("before cgheck max bits\n");
    // display_index(*a);
    int max_bits = check_max_bits(a);
    // printf("after check max bits\n");
    // display_index(*a);
    int i = 0;
    int j = 0;
    int a_len = count_elements(*a);
    // display_index(*a);
    while (i < max_bits)
    {
        // node *temp = *a;
        while(j < a_len)
        {
            // printf("a index is %lu\n",(*a)->index);
            // printf("is %lu >> %i & 1 == 1?\n",temp->index,i);
            // printf("temp->index = %lu | temp->index >> %i = %lu & 1 = %d\n",(*a)->index,i,(*a)->index >> i ,((*a)->index >> i & 1));
            if (!(((*a)->index) >> i & 1))
            {
                // printf("pushing %lu to b when &1 is 1\n",temp->index);
                push(a, b, 'b');
                // printf("stack a:\n");
                // display_elements(*a);
            }
            else
            {
                rotate(a);
                // printf("stack a:\n");
                // display_elements(*a);
            }
            j++;
        }
        j = 0;
        while (count_elements(*a) > 0)
        {
            // printf("pushing %lu to b when &1 is 0\n",(*a)->index);
            push(a, b, 'b');
        }
        while (count_elements(*b) > 0)
        {
            // printf("stack b:\n");
            // display_elements(*b);
            push(b, a, 'a');
        }
        i++;
    }
}