/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_wid_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:37:58 by smounafi          #+#    #+#             */
/*   Updated: 2023/02/27 14:59:26 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_words(char *s, char c)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (counter);
}

char	**free_strings(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		strings[i] = NULL;
		i++;
	}
	free(strings);
	strings = NULL;
	return (strings);
}

int	get_word_len(char *s, char c)
{
	int	j;

	j = 0;
	while (s[j] && s[j] != c)
		j++;
	return (j);
}

char	**ft_split_wid_char(char *s, char c)
{
	int		j;
	int		index;
	char	**string;

	j = 0;
	index = 0;
	if (!s)
		return (NULL);
	string = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!string)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			string[index++] = ft_substr(s, 0, get_word_len(s, c));
			if (!string[index - 1])
				return (free_strings(string));
			s += get_word_len(s, c);
		}
	}
	string[index] = NULL;
	return (string);
}
