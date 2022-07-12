#include <stdio.h>
#include <stdlib.h>
//#include "push_swap.h"
//#include "libft.h"

typedef struct p_stack
{
    int *a;
    int *b;
    int a_size;
    int b_size;
}       t_stack;

void    error(int *stack)
{
    free(stack);
    printf("Error\n");
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
int	sorted(int *stack, int size)
{
	int a; 
	int	d;
	int	i;

	a = 1;
	d = 1;
	i = 0;
  while ((a == 1 || d == 1) && i < size - 1) {
    if (stack[i] < stack[i+1])
      d = 0;
    else if (stack[i] > stack[i+1])
      a = 0;
    i++;
  }

  if (a == 1)
  {
	printf("Sorted\n");
	return 1;
  }
  else
  {
	printf("Not Sorted\n");
	return 0;
  }
}



void display(int *stack, int size)
{
	int i;
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

void    init_stack(char **argv)
{
    t_stack     stack;
    int         size;
    int         i;

    i = -1;
    size = argv_strlen(argv);
    stack.a = (int *)malloc(sizeof(int) * size);
    stack.a_size = size;
    if(!stack.a)
        return ; 
    stack.b = (int *)malloc(sizeof(int) * size);
    if(!stack.b)
    {
        free(stack.a);
        return ;
    }
	stack.b_size = 0;
    while(++i < size)
        stack.a[i] = new_atoi(argv[i], stack.a);
    check_dup(stack.a, size);
	sorted(stack.a, stack.a_size);
	display(stack.a, stack.a_size);
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_putword(char *word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **s2, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!s2)
			return (0);
		ft_putword(s2[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	s2[word] = 0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	num_words;

	if (!s)
		return (0);
	num_words = ft_count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (0);
	ft_split_words(s, c, s2, num_words);
	return (s2);
}

int main(int argc, char **argv)
{
    /*t_stack stack;*/

    if(argc > 1)
    {
        argv++;
        if(argc == 2)
            argv = ft_split(*argv, ' ');
        init_stack(argv);
		return(0);
    }
	return(0);
}
