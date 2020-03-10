/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:08:45 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 18:58:00 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	mark_visited(t_room **rooms, char *name)
{
	t_room *tmp;

	tmp = *rooms;
	while (ft_strcmp(tmp->name, name) != 0 && tmp->next)
		tmp = tmp->next;
	tmp->visited = 1;
}

void	mark_start(t_room *rooms, char *start)
{
	t_room *tmp;

	tmp = go_to_lst(rooms, start);
	tmp->visited = 1;
	tmp->level = 1;
}

int		mark_levels(t_room *rooms, char *go_to, int level)
{
	t_room *tmp;
	t_room *lks;

	tmp = go_to_lst(rooms, go_to);
	level++;
	if (was_visited(rooms, tmp->name) == 1 && tmp->level <= level)
		return (0);
	if (was_visited(rooms, tmp->name) == 1 && tmp->level > level)
		tmp->level = level;
	if (was_visited(rooms, tmp->name) == 0)
	{
		tmp->level = level;
		mark_visited(&rooms, tmp->name);
	}
	lks = tmp->links;
	while (lks)
	{
		mark_levels(rooms, lks->name, level);
		lks = lks->next;
	}
	return (1);
}
