/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:47:57 by smounafi          #+#    #+#             */
/*   Updated: 2023/03/06 20:48:39 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr_s1;
	char	*ptr;
	int		i;
	int		len;

	ptr_s1 = (char *)s1;
	i = 0;
	len = ft_strlen(s1);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (0);
	while (ptr_s1[i] && i < len)
	{
		ptr[i] = ptr_s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}