/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:02:04 by smounafi          #+#    #+#             */
/*   Updated: 2023/02/24 23:38:35 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_word(char *str)
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
	int		x;
	int		y;
	char	*s1;
	// char	*s2 = NULL;
	
	i = 0;
	j = 0;
	x = 0;
	y = 0;
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
	/***********************************/
	// else if(str[j] == '$')
	// {
	// 	j++;
	// 	x = j;
	// 	while(str[x] != ' ')
	// 		x++;
	// 	s2 = malloc(x + 1);
	// 	while(str[j] != ' ')
	// 	{
	// 		s2[y] = str[j];
	// 		j++;
	// 		y++;
	// 	}
	// 	printf("**%s**\n", s2);
	// 	// while(getenv(str) != ' ')
	// 	// 	j++;
	// 	// j--;
	// 	// while(x < j)
	// 	// {
	// 	// 	s2[x] = str[x + 1];
	// 	// 	x++;
	// 	// }
	// 	// s2[x] = '\0';
	// 	// s2 = getenv(s2);
	// 	// str = s2;
	// 	//printf("**** %d ****\n", j);
	// }
	/***********************************/
	else
		while (str[j] && str[j] != ' ' && str[j] != '\t' && str[j] != '\n')
			j++;
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

char	**ft_split(char *str)
{
	int		x;
	int		i;
	char	**split;
	int		b;

	i = 0;
	x = 0;
	b = count_word(str);
	split = malloc((sizeof(char *) * (b + 1)));
	while (*str && i < b)
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
		{
			while (*str != ' ' && *str != '\t' && *str != '\n')
				str++;
		}
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
		return (calloc(1, 1));
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

int inter(char *s1, char *s2)
{
	int i;
	int j;
	size_t res;
	
	i = 0;
	j = 0;
	res = 0;
	while(s1[i] && s2[j])
	{
		if(s1[i] == s2[j])
			res++;
		if(res == ft_strlen(s1) - 1)
			return(1);
		i++;
		j++;
	}
	return(0);
}

// char *get_environment(char *splitted_str, char **env)
// {
// 	int w;
// 	int x;
// 	int y;
	
// 	w = 0;
// 	x = 0;
// 	y = 0;
// 	splitted_str++; // escape $ in the splitted string
// 	while(env[y])
// 	{
// 		if(inter(splitted_str, env[y]))
// 		{
// 			while(*env[y] != '=')
// 				env[y]++;
// 			env[y]++; // escape = 
// 			splitted_str = env[y];
// 			break;
// 		}
// 		y++;
// 	}
// 	return splitted_str;
// }

char *get_environment(char *splitted_str, char **env)
{
	char *envirement;
    int i;
    int count;
    int j;

    j = 0;
    count = 0;
    i = 0;
    envirement = ft_calloc(1,1);
    while (env[i] != NULL)
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
char **search_in_splitted_str(char **splitted_str, char **env)
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
					splitted_str[y] = get_environment(splitted_str[y] + x, env);
				else if(x > 1)
				 	splitted_str[y] = ft_strjoin(ft_substr(splitted_str[y], 0, x - 1), get_environment(splitted_str[y] + x - 1, env));
			}
			x++;
		}
		y++;
	}
	return splitted_str;
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
    char *input;
    char **splited_string;
	int count;
	int i;

    i = 0;
	count = 0;	
    input = readline("> ");
	count = count_word(input);
    //add_history(input);
    splited_string = ft_split(input);
    splited_string = search_in_splitted_str(splited_string, env);
    while(i < count)
    {
        printf("-- %s\n", splited_string[i]);
        i++;
    }
    free(input);
    return 0;
}