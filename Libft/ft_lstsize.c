/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:19:32 by smounafi          #+#    #+#             */
/*   Updated: 2023/03/03 20:11:30 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_lstsize(t_shell *lst)
{
	int		i;
	t_shell	*new;

	i = 0;
	new = lst;
	while (new != NULL)
	{
		new = new->nextcmd;
		i++;
	}
	return (i);
}
