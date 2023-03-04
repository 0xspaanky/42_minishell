/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:19:02 by smounafi          #+#    #+#             */
/*   Updated: 2023/03/03 20:18:59 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstadd_front(t_shell **lst, t_shell *new)
{
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->nextcmd = *lst;
		*lst = new;
	}
}
