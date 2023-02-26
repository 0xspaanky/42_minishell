/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:43:57 by smounafi          #+#    #+#             */
/*   Updated: 2023/02/26 13:52:13 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	i = -1;
	while (s1[++i])
	{
		if (i <= ft_strlen(s1))
			p[i] = s1[i];
	}
	j = -1;
	while (s2[++j])
	{
		if (i < ft_strlen(s1) + ft_strlen(s2))
			p[i] = s2[j];
		i++;
	}
	p[i] = '\0';
	return (p);
}
