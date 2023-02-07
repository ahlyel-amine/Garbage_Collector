/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:31:48 by aahlyel           #+#    #+#             */
/*   Updated: 2023/02/07 22:45:16 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/errno.h>
#include <stdint.h>
# define ERR_ALLOC "Error Cannot allocate memory"


typedef struct s_list
{
	void			*content;
	int				is_tmp:1;
	struct s_list	*next;
}	t_list;

static t_list	*g_garbg;

#endif