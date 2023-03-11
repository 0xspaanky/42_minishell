/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:02:07 by smounafi          #+#    #+#             */
/*   Updated: 2023/03/10 21:28:03 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct t_files
{
    char    *file_name;
    struct t_files *next_file;
    char    typefile;

}   t_files;

typedef struct t_shell
{
    char **cmd;
    struct t_shell *nextcmd;
    t_files *files;

}   t_shell;

char	**ft_split(char *dst);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
int     ft_count_word(char *str);
char	**ft_split_wid_char(char *s, char c);
t_shell	*ft_lstnew(char **cmd);
void	ft_lstadd_back(t_shell **lst, t_shell *new);
void	ft_lstadd_front(t_shell **lst, t_shell *new);
#endif