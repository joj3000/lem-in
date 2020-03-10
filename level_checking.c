/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:05:16 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 18:26:27 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		level_of_end(t_room *rooms, char *end)
{
	t_room *r;

	r = go_to_lst(rooms, end);
	return (r->level);
}

int		level_of_name(t_room *rooms, char *s)
{
	t_room *tmp;

	tmp = rooms;
	while (ft_strcmp(tmp->name, s) != 0 && (tmp)->next)
		(tmp) = (tmp)->next;
	return (tmp->level);
}

t_room	*go_to_level(t_room *rooms, int level)
{
	t_room *tmp;

	tmp = rooms;
	while (tmp->level != level && tmp)
		tmp = tmp->next;
	return (tmp);
}

t_room	*go_to_inf_level(t_room *rooms, char *s)
{
	t_room	*tmp;
	t_room	*lks;
	t_room	*cpy;
	int		level;

	tmp = go_to_lst(rooms, s);
	lks = tmp->links;
	level = tmp->level;
	while (lks)
	{
		cpy = go_to_lst(rooms, lks->name);
		if (cpy->level == level - 1)
			return (cpy);
		lks = lks->next;
	}
	return (NULL);
}
