/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:58:50 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 16:20:09 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*lst_dup(t_room *rooms)
{
	t_room	*cpy;
	t_room	*tmp;

	cpy = NULL;
	if (rooms)
	{
		tmp = rooms;
		while (tmp)
		{
			lst_pushback_room(&cpy, tmp->name);
			tmp = tmp->next;
		}
	}
	return (cpy);
}

t_room	*final_list(t_room *rooms, int total_ants)
{
	double	coups_multi;
	double	coups_shortest;

	if (lst_count(rooms->indep_lst) >= 1)
	{
		coups_multi = coup_for_multi(rooms, total_ants);
		coups_shortest = coup_for_shortest(rooms, total_ants);
		if (coups_multi < coups_shortest)
			return (lst_dup(rooms->indep_lst));
		else
		{
			if (coups_shortest == 0 && lst_count(rooms->indep_lst) > 1)
				return (lst_dup(rooms->indep_lst));
			return (return_shortest(rooms->g_paths));
		}
	}
	return (NULL);
}
