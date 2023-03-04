/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:19:47 by smounafi          #+#    #+#             */
/*   Updated: 2023/03/03 20:22:21 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_shell	*ft_lstnew(char **cmd)
{
	t_shell	*nd;

	nd = malloc(sizeof(t_shell));
	if (!nd)
		return (0);
	nd->cmd = cmd;
	nd->nextcmd = NULL;
	return (nd);
}