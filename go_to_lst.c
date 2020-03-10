/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:11:53 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 16:24:47 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*go_to_lst(t_room *rooms, char *name)
{
	t_room *tmp;

	tmp = rooms;
	while (ft_strcmp(tmp->name, name) != 0 && (tmp)->next)
		(tmp) = (tmp)->next;
	return (tmp);
}
