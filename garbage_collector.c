/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:31:50 by aahlyel           #+#    #+#             */
/*   Updated: 2023/02/07 21:26:52 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void    ft_exit(char *err_messg, int exit_status)
{
	if (!exit_status)
	{
		ft_lstclear(&g_garbg, free);
		exit(EXIT_SUCCESS);
	}
	if (err_messg)
		ft_putendl_fd(err_messg, STDERR_FILENO);
	else if (errno)
		perror("");
	ft_lstclear(&g_garbg, free);
	exit(EXIT_FAILURE);
}

void    *ft_malloc(void *pointer, int is_tmp)
{
	t_list	*new;
	
	new = NULL;
	if (!pointer)
		ft_exit(ERR_ALLOC, 1);
	new = ft_lstnew(pointer);
	if (!new)
	{
		free(pointer);
		ft_exit(ERR_ALLOC, 1);
	}
	ft_lstadd_front(&g_garbg, new);
	return (pointer);
}

t_list	*ft_lstnew(void	*pointer)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = pointer;
	new->is_tmp = 0;
	return (NULL);
}
