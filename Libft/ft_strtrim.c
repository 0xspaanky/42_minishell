/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:27:00 by smounafi          #+#    #+#             */
/*   Updated: 2023/03/12 22:31:30 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strtrim(char *s1, char *set)
{
	size_t	len_s1;
	size_t	i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	len_s1 = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (len_s1 > i && ft_strchr(set, s1[len_s1]))
		len_s1--;
	return (ft_substr(s1, i, len_s1 - i + 1));
}
