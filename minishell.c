/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:02:04 by smounafi          #+#    #+#             */
/*   Updated: 2023/02/27 17:33:23 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char **ft_replace_var_with_env_value(char **splitted_str, char **env)
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

char *ft_convert_2d_to_str_and_separate(char **splited_string)
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

char	**ft_split_with_hashtag(char *str)
{
	int		i;
	char	**split;
	int		count;
	
	i = 0;
	count = ft_count_word_for_str(str);
	split = malloc(sizeof(char *) * (count + 1));
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

char *separate_special_chars(char *str, char split_with)
{
	char **splitted;
	char *hold_char;
	char *ret;
	int i;

	i = 0;
	ret = ft_calloc(1,1);
	hold_char = malloc(2);
	hold_char[0] = split_with;
	hold_char[1] = '\0';
	splitted = ft_split_wid_char(str, split_with);
	while(splitted[i])
	{
		if(splitted[i + 1])
		{
			ret = ft_strjoin(ret, splitted[i]);
			ret = ft_strjoin(ret, "#");
			i++;
			ret = ft_strjoin(ret, hold_char);
			splitted[i] = ft_strjoin("#", splitted[i]);
			ret = ft_strjoin(ret, splitted[i]);
		}
		else if(splitted[i + 1] == NULL)
		{
			ret = ft_strjoin("#", hold_char);
			splitted[i] = ft_strjoin("#", splitted[i]);
			ret = ft_strjoin(ret, splitted[i]);
		}
		i++;	
	}
	return(ret);
}

char **handling_special_chars(char **splitted_string)
{
	int x;
	int y;
	int index;
	char split_with;

	x = 0;
	y = 0;
	index = 0;
	while(splitted_string[y])
	{
		x = 0;
		while(splitted_string[y][x])
		{
			if(splitted_string[y][x] == '>' || splitted_string[y][x] == '<' || splitted_string[y][x] == '|')
			{
				split_with = splitted_string[y][x];
				splitted_string[y] = separate_special_chars(splitted_string[y], split_with);
				break;
			}
			x++;
		}
		y++;
	}
	return(splitted_string);
}


int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
    char *input;
    char **splited_string;
    char *splited_str;
	int count;
	int counter;
	int i;
	int j;

    i = 0;
    j = 0;
	count = 0;	
    input = readline("\033[1;33mminishell> \033[0m");
	count = ft_count_word(input);
    //add_history(input);
    splited_string = ft_split(input);
    splited_string = ft_replace_var_with_env_value(splited_string, env);
	splited_string = handling_special_chars(splited_string);
	splited_str = ft_convert_2d_to_str_and_separate(splited_string);
	splited_string = ft_split_with_hashtag(splited_str);
	counter = ft_count_word_for_str(splited_str);
	while(j < counter)
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