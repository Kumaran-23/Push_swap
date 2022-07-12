#include <stdio.h>
#include <stdlib.h>

typedef struct p_stack
{
    int *a;
    int *b;
    int a_size;
    int b_size;
}       t_stack;

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
    stack.b_size = 0;
    if(!stack.b)
    {
        free(stack.a);
        return ;
    }
    while(++i < size)
        stack.a[i] = new_atoi(argv[i], stack.a);
    check_dup(stack.a, size);
}

static int	ft_wordcounter(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		i++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * n + 1);
	if (!dup)
		return (NULL);
	while (s[i] && i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[n] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_wordcounter(s, c) + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		len = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > len)
			result[j++] = ft_strndup(&s[len], i - len);
	}
	result[j] = NULL;
	return (result);
}

int main(int argc, char **argv)
{
	if(argc > 1)
    {
        argv++;
        if(argc == 2)
            argv = ft_split(*argv, ' ');
        init_stack(argv);
    }
}