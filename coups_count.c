/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coups_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:01:34 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 16:17:07 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

double		coup_per_path(double moyenne_rooms, double total_ants)
{
	if (moyenne_rooms > 2)
		return (moyenne_rooms + total_ants - 2);
	else
		return (0);
}

double		coup_for_multi(t_room *rooms, double total_ants)
{
	t_room	*tmp;
	double	total_rooms;

	tmp = rooms->indep_lst;
	total_rooms = 0;
	while (tmp)
	{
		total_rooms += rooms_count(tmp->name);
		tmp = tmp->next;
	}
	return (coup_per_path(total_rooms / 2, total_ants / 2));
}

double		coup_for_shortest(t_room *rooms, double total_ants)
{
	double	total_rooms;
	t_room	*tmp;

	tmp = return_shortest(rooms->g_paths);
	total_rooms = rooms_count(tmp->name);
	return (coup_per_path(total_rooms, total_ants));
}
