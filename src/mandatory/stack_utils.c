#include "../inc/push_swap.h"
#include "../libft/inc/ft_printf.h"

void    error(int *stack)
{
    free(stack);
    write(2 , "Error", 5);
	write(2, "\n", 1);
    exit(1);
}

/* to get the lenght of argv for stack size and main */
int argv_strlen(char **argv)
{
    int i;

    i = 0;
    while(*argv)
    {
        argv++;
        i++;
    }
    return(i);
}

/*new atoi function to include error if less than INT_MIN 
or more thanINT_MAX is recieved as an arguement. and to include 
stack as a parameter. Also to make sure non numeric characters display error*/

int	new_atoi(char *str, int *stack)
{
	unsigned int		i;
	int					neg;
	unsigned long int	num;

	i = 0;
	num = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error(stack);
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	if ((num > 2147483648 && neg == -1) || (num > 2147483647 && neg == 1))
		error(stack);
	return (num * neg);
}


/* to check if stack is sorted in ascending order */
int	sorted(int *stack, int size, int order)
{
	int	i;

	if (order == 0)
	{
		i = 1;
		while (i < size)
		{
			if (stack[i] < stack[i - 1])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] < stack[i])
				return (0);
			i++;
		}
		return (1);
	}
}



void displayA(int *stack, int size)
{
	int i;
	printf("Stack A:\n");
	for(i = 0; i < size; i++)
	{
		printf("%d\n", stack[i]);
	}
}

void displayB(int *stack, int size)
{
	int i;
	printf("Stack B:\n");
	for(i = 0; i < size; i++)
	{
		printf("%d\n", stack[i]);
	}
}
/* to check duplicate numbers in stack */
void	check_dup(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while(i < size)
	{
		while(j < size)
		{
			if(stack[i] == stack[j])
				error(stack);
			j++;
		}
		i++;
		j = i + 1;
	}
}