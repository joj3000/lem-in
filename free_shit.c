/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:05:03 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 16:23:47 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_elem(t_room *rooms)
{
	free(rooms->name);
	rooms->next = NULL;
	rooms->name = NULL;
	free(rooms);
	rooms = NULL;
}

void	free_lst(t_room *rooms)
{
	t_room *tmp;

	while (rooms)
	{
		tmp = rooms;
		rooms = rooms->next;
		free_elem(tmp);
	}
}

void	free_room(t_room *to_del)
{
	free(to_del->name);
	to_del->name = NULL;
	free(to_del);
	to_del = NULL;
}

void	free_things(char **st_end, int *flag)
{
	free(flag);
	free(st_end[0]);
	free(st_end[1]);
	free(st_end);
	st_end[0] = NULL;
	st_end[1] = NULL;
}
