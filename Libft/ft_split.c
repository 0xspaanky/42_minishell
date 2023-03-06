/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:54:59 by smounafi          #+#    #+#             */
/*   Updated: 2023/03/06 20:01:58 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	count_word(char *dst)
// {
// 	int	a;
// 	int	b;
// 	int	count;
// 	a = 0;
// 	b = 0;
// 	count = 0;
// 	while (dst[a])
// 	{
// 		if (b == 0 && dst[a] != ' ' && dst[a] != '\t' && dst[a] != '\n')
// 		{
// 			b = 1;
// 			count++;
// 		}
// 		else if (b == 1 && (dst[a] == ' ' || dst[a] == '\t' || dst[a] == '\n'))
// 			b = 0;
// 		a++;
// 	}
// 	return (count);
// }

// char	*fill_word(char *p)
// {
// 	int		a;
// 	int		i;
// 	char	*f;
// 	i = 0;
// 	a = 0;
// 	while (p[a] && p[a] != ' ' && p[a] != '\t' && p[a] != '\n')
// 		a++;
// 	f = malloc(a + 1);
// 	while (i < a)
// 	{
// 		f[i] = p[i];
// 		i++;
// 	}
// 	f[i] = '\0';
// 	return (f);
// }

// char	**ft_split(char *dst)
// {
// 	int		a;
// 	int		i;
// 	char	**split;
// 	int		b;
// 	i = 0;
// 	a = 0;
// 	b = count_word(dst);
// 	split = malloc((sizeof(char *) * (b + 1)));
// 	while (*dst && i < b)
// 	{
// 		while (*dst == ' ' || *dst == '\t' || *dst == '\n')
// 			dst++;
// 		split[i] = fill_word(dst);
// 		i++;
// 		while (*dst != ' ' && *dst != '\t' && *dst != '\n')
// 			dst++;
// 	}
// 	split[i] = 0;
// 	return (split);
// }

int	ft_count_word(char *str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		if(str[i] == 34 || str[i] == 39)
		{
			i++;
			while(str[i] != 34 && str[i] != 39)
				i++;
		}
		if(j == 0 && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			j = 1;
			count++;
		}
		else if (j == 1 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
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
	}
	while (str[j] && str[j] != ' ' && str[j] != '\t' && str[j] != '\n')
		j++;
	s1 = malloc(j + 1);
	while (i < j)
	{
		s1[i] = str[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char *skip_single_double_quotes(char *str)
{
	while(*str != 34 && *str != 39)
		str++;
	str++;
	if (*str != ' ')
	{
		while(*str != 34 && *str != 39)
			str++;
	}
	return(str);
}

char	**ft_split(char *str)
{
	int		i;
	char	**split;
	int		count;
	int x;
	
	i = 0;
	x = 0;
	count = ft_count_word(str);
	split = malloc((sizeof(char *) * (count + 1)));
	while (*str && i < count)
	{//HANDDLE string before quotes like and have space inside         yes"hello there"
		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
			str++;
		split[i] = fill_word(str);
		i++;
		if(*str == 34 || *str == 39)
		{
			str++;
			str = skip_single_double_quotes(str);
		}
		while (*str && ( *str != ' ' && *str != '\t' && *str != '\n'))
			str++;
	}
	split[i] = 0;
	return (split);
}