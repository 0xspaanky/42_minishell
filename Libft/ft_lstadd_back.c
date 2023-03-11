/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:30:33 by smounafi          #+#    #+#             */
/*   Updated: 2023/03/11 12:52:56 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_shell	*ft_lstlast(t_shell *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->nextcmd != NULL)
		lst = lst->nextcmd;
	return (lst);
}

void	ft_lstadd_back(t_shell **lst, t_shell *new)
{
	t_shell	*last_node;
	if (!*lst)
	{
		*lst = new;
		return;
	}
	last_node = ft_lstlast(*lst);
	last_node->nextcmd = new;
}
