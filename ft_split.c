/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:54:59 by smounafi          #+#    #+#             */
/*   Updated: 2023/02/20 17:48:55 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_word(char *dst)
{
	int	a;
	int	b;
	int	count;

	a = 0;
	b = 0;
	count = 0;
	while (dst[a])
	{
		if (b == 0 && dst[a] != ' ' && dst[a] != '\t' && dst[a] != '\n')
		{
			b = 1;
			count++;
		}
		else if (b == 1 && (dst[a] == ' ' || dst[a] == '\t' || dst[a] == '\n'))
			b = 0;
		a++;
	}
	return (count);
}

char	*fill_word(char *p)
{
	int		a;
	int		i;
	char	*f;

	i = 0;
	a = 0;
	while (p[a] && p[a] != ' ' && p[a] != '\t' && p[a] != '\n')
		a++;
	f = malloc(a + 1);
	while (i < a)
	{
		f[i] = p[i];
		i++;
	}
	f[i] = '\0';
	return (f);
}

char	**ft_split(char *dst)
{
	int		a;
	int		i;
	char	**split;
	int		b;

	i = 0;
	a = 0;
	b = count_word(dst);
	split = malloc((sizeof(char *) * (b + 1)));
	while (*dst && i < b)
	{
		while (*dst == ' ' || *dst == '\t' || *dst == '\n')
			dst++;
		split[i] = fill_word(dst);
		i++;
		while (*dst != ' ' && *dst != '\t' && *dst != '\n')
			dst++;
	}
	split[i] = 0;
	return (split);
}
