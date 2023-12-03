#include "push_swap.h"
#include "./libft/libft.h"
#include <stdlib.h>
int main(int ac, char** av)
{
	//Declare pointers to two data structures/linked lists, one for stack `a` and another for `b`
		//Set both pointers to NULL to avoid undefined behaviour and indicate we're starting with empty stacks
	// node *a;
	// node *b;
	// a = NULL;
	// b = NULL;

	//Handle input count errors. Argument count must be 2 or more, and the second input must not be empty
	//If input errors, return error
	if(ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	//Handle both cases of input, whether a variable number of command line arguments, or as a string
		//If the input of numbers is as a string, call split() to split the substrings

	//Initialize stack `a` by appending each input number as a node to stack `a`
		//Handle integer overflow, duplicates, and syntax errors, e.g. input must only contain digits, or `-` `+` signs
			//If errors found, free stack `a` and return error
		//Check for each input, if it is a long integer
			//If the input is a string, convert it to a long integer 
		//Append the nodes to stack `a`

	//Check if stack `a` is sorted
		//If not sorted, implement our sorting algorithm 
			//Check for 2 numbers
				//If so, simply swap the numbers
			//Check for 3 numbers
				//If so, implement our simple `sort three` algorithim
			//Check if the stack has more than 3 numbers
				//If so, implent our Turk Algorithm

	//Clean up the stack
	return (0);
}

