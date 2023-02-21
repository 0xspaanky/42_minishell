/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:02:04 by smounafi          #+#    #+#             */
/*   Updated: 2023/02/21 21:52:29 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_word(char *dst)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (dst[i])
	{
		if(dst[i] == 34 || dst[i] == 39)
		{
			i++;
			while(dst[i] != 34 && dst[i] != 39)
				i++;
		}
		if (j == 0 && dst[i] != ' ' && dst[i] != '\t' && dst[i] != '\n')
		{
			j = 1;
			count++;
		}
		else if (j == 1 && (dst[i] == ' ' || dst[i] == '\t' || dst[i] == '\n'))
			j = 0;
		i++;
	}
	return (count);
}

char	*fill_word(char *str)
{
	int		j;
	int		i;
	char	*s1;

	i = 0;
	j = 0;
	if(str[j] == 34 || str[j] == 39)
	{
		j++;
		while(str[j] != 34 && str[j] != 39)
			j++;
		if(str[j + 1] != ' ')
		{
			while(str[j] != ' ')
			{
				j++;
			}
		}
	}
	else
	{
		while (str[j] && str[j] != ' ' && str[j] != '\t' && str[j] != '\n')
			j++;
	}
	j += 1;
	s1 = malloc(j + 1);
	while (i < j)
	{
		s1[i] = str[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	**ft_split(char *dst)
{
	int		x;
	int		i;
	char	**split;
	int		b;

	i = 0;
	x = 0;
	b = count_word(dst);
	split = malloc((sizeof(char *) * (b + 1)));
	while (*dst && i < b)
	{
		while (*dst == ' ' || *dst == '\t' || *dst == '\n')
			dst++;
		split[i] = fill_word(dst);
		i++;
		if(*dst == 34 || *dst == 39)
		{
			dst++;
			while(*dst != 34 && *dst != 39)
				dst++;
			dst++;
			if (*dst != ' ')
			{
				while(*dst != ' ')
				{
					dst++;
				}
			}
		}
		else
		{
			while (*dst != ' ' && *dst != '\t' && *dst != '\n')
				dst++;
		}
	}
	split[i] = 0;
	return (split);
}

int main()
{
    char *input;
    char **splited_string;
    int i = 0;
	int count = 0;

    input = readline("> ");
	count = count_word(input);
    //add_history(input);
    splited_string = ft_split(input);
    int x = count_word(input);
	printf("X = %d\n", x);
    while(i < x)
    {
        printf("-- %s\n", splited_string[i]);
        i++;
    }
    free(input);
    return 0;
}