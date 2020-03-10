/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shit_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:22:22 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 21:03:11 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_everything(t_room *rooms, char *line, char **st_end, int *flag)
{
	t_room *tmp;

	free(flag);
	if (st_end[0])
		free(st_end[0]);
	if (st_end[1])
		free(st_end[1]);
	free(st_end);
	free(line);
	while (rooms)
	{
		tmp = rooms;
		rooms = rooms->next;
		if (tmp->links)
			free_lst(tmp->links);
		free(tmp->name);
		tmp->name = NULL;
	}
}

void	free_everything_2(t_room *rooms, char **st_end, int *flag) // is it due to the rooms->start not freed ?
{
	t_room	*tmp;
	int		k;
	int		l;
	int		m;

	k = 0;
	l = 0;
	m = 0;
	(void)flag;
	(void)st_end;
	free_things(st_end, flag);
	while (rooms)
	{
		tmp = rooms;
		rooms = rooms->next;
		if (tmp->links)
			free_lst(tmp->links);
		if (tmp->start && m == 0)
			free(tmp->start);
		if (tmp->indep_lst && k == 0)
			free_lst(tmp->indep_lst);
		if (tmp->g_paths && l == 0)
			free_lst(tmp->g_paths);
	//	free(tmp->name);
	//	free(tmp);
		tmp->name = NULL;
		k++;
		l++;
		m++;
	}
}
