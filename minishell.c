/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:02:04 by smounafi          #+#    #+#             */
/*   Updated: 2023/02/25 23:37:51 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

// void skip_single_double_quotes(char *str)
// {
// 	while(*str != 34 && *str != 39)
// 		str++;
// 	str++;
// 	if (*str != ' ')
// 	{
// 		while(*str != ' ')
// 		{
// 			str++;
// 		}
// 	}
// }

char	**ft_split(char *str)
{
	int		i;
	char	**split;
	int		count;

	i = 0;
	count = ft_count_word(str);
	split = malloc((sizeof(char *) * (count + 1)));
	while (*str && i < count)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		split[i] = fill_word(str);
		i++;
		if(*str == 34 || *str == 39)
		{
			str++;
			while(*str != 34 && *str != 39)
				str++;
			str++;
			if (*str != ' ')
			{
				while(*str != ' ')
				{
					str++;
				}
			}
		}
		else
			while (*str != ' ' && *str != '\t' && *str != '\n')
				str++;
	}
	split[i] = 0;
	return (split);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (count && size == SIZE_MAX / count)
		return (0);
	ptr = (char *)malloc(count * size);
	if (!ptr)
		return (0);
	while (i < count * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char *ft_get_environment(char *splitted_str, char **env)
{
	char *envirement;
    int i;
    int count;
    int j;

    j = 0;
    count = 0;
    i = 0;
    envirement = ft_calloc(1,1);
    while (env[i])
    {
        j = 0;
        while (splitted_str[j]  &&  env[i][j] != '=' )
        {
            if (env[i][j] == splitted_str[j])
                j++;
            else
                break ;
        } 
        if (env[i][j] == '=')
        {
            envirement = ft_strjoin(envirement, (env[i] + j + 1));
            count = 1;
            break ;
        }
        i++;
    }
    if (count == 0)
        return ("\0");
    return(envirement);
}

char **ft_search_in_splitted_str(char **splitted_str, char **env)
{
	int x;
	int y;

	y = 0;
	while(splitted_str[y])
	{
		x = 0;
		while(splitted_str[y][x])
		{
			if(splitted_str[y][x] == '$')
			{
				x++;
				if(x == 1)
				{
					// printf("STR 1 = %s\n",splitted_str[y]);
					// printf("ENV 1 = %s\n", get_environment(splitted_str[y] + x, env));
					splitted_str[y] = ft_get_environment(splitted_str[y] + x, env);
				}
				else if(x > 1)
				{
					// printf("STR 2 = %s\n",splitted_str[y]);
					// printf("ENV 2 = %s\n", get_environment(splitted_str[y], env));
				 	splitted_str[y] = ft_strjoin(ft_substr(splitted_str[y], 0, x - 1), ft_get_environment(splitted_str[y] + x - 1, env));
				}
			}
			x++;
		}
		y++;
	}
	return splitted_str;
}

char *ft_convert_2d_to_str(char **splited_string)
{
	int y;
	char *str;

	y = 0;
	str = ft_calloc(1,1);
	while(splited_string[y])
	{
		str = ft_strjoin(str, splited_string[y]);
		str = ft_strjoin(str, "#");
		y++;
	}
	str[ft_strlen(str)] = '\0';
	return(str);
}

int	ft_count_word_for_str(char *str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		if(j == 0 && str[i] != '#')
		{
			j = 1;
			count++;
		}
		else if (j == 1 && str[i] == '#')
			j = 0;
		i++;
	}
	return (count);
}

char	*fill_word_for_str(char *str)
{
	int		j;
	int		i;
	char	*s1;
	
	i = 0;
	j = 0;
	while (str[j] && str[j] != '#')
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

char	**ft_split_with_special_chars(char *str)
{
	int		i;
	char	**split;
	int		count;
	
	i = 0;
	count = ft_count_word_for_str(str);
	split = malloc(sizeof(char *) * (count + 1));
	printf("count %d\n", count);
	while (*str && i < count)
	{
		while (*str == '#')
			str++;
		split[i] = fill_word_for_str(str);
		i++;
		while (*str != '#')
			str++;
	}
	split[i] = 0;
	return (split);
}

/*           HANDLE SPLIT WITH | < > << >>            */

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
    char *input;
    char **splited_string;
    char *splited_str;
	int count;
	int i;
	int j;

    i = 0;
    j = 0;
	count = 0;	
    input = readline("> ");
	count = ft_count_word(input);
    //add_history(input);
    splited_string = ft_split(input);
    splited_string = ft_search_in_splitted_str(splited_string, env);
    while(i < count)
    {
        printf("-- %s\n", splited_string[i]);
        i++;
    }
	splited_str = ft_convert_2d_to_str(splited_string);
    printf("-- %s\n", splited_str);
	splited_string = ft_split_with_special_chars(splited_str);
	while(j < count)
    {
        printf("-- %s\n", splited_string[j]);
        j++;
    }
    free(input);
    return 0;
}









// int pipe_index;
// int left_redir_index;
// int right_redir_index;
// int left_herdoc_index;
// int right_herdoc_index;
// pipe_index = 0;
// left_redir_index = 0;
// right_redir_index = 0;
// left_herdoc_index = 0;
// right_herdoc_index = 0;
// if(str[i] == '|')
// 	pipe_index = i;
// if(str[i] == '<')
// 	left_redir_index = i;
// if(str[i] == '>')
// 	right_redir_index = i;
// if(str[i] == '<<')
// 	left_herdoc_index = i;
// if(str[i] == '>>')
// 	right_herdoc_index = i;