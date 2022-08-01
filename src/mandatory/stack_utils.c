#include "../inc/push_swap.h"
#include "../libft/inc/ft_printf.h"

void    error(int *stack)
{
    free(stack);
    ft_printf("Error\n");
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

/* new atoi function to include error if less than INT_MIN 
or more thanINT_MAX is recieved as an arguement. and to include 
stack as a parameter. Also to make sure non numeric characters display error*/
int new_atoi(char *str, int *stack)
{
    int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if(str[i] < 48 || str[i] > 57)
			error(stack);
		res = res * 10 + (str[i] - '0');
		i++;
	}
    if(res < -2147483648 || res > 2147483647)
	    error(stack);
    return (sign * res);
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