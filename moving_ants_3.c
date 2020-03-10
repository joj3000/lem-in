/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ants_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:25:39 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 19:07:44 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		path_contains_ant(t_room *path)
{
	t_room *tmp;

	tmp = path;
	while (tmp)
	{
		if (tmp->ant_num != 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	shift_ants_next_room(t_room *path, int count)
{
	t_room *tmp;
	t_room *prev;

	tmp = path;
	tmp->prev_num = count;
	prev = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		tmp->prev_num = prev->ant_num;
		tmp = tmp->next;
		prev = prev->next;
	}
	tmp = path;
	while (tmp)
	{
		tmp->ant_num = tmp->prev_num;
		tmp = tmp->next;
	}
	tmp = path;
	while (tmp)
		tmp = tmp->next;
}

int		lowest_ant_num(t_room *path)
{
	t_room	*tmp;
	int		lowest;

	tmp = path;
	while (tmp)
	{
		if (tmp->ant_num != 0)
			break ;
		if (tmp->ant_num == 0)
			tmp = tmp->next;
	}
	if (tmp == NULL)
		return (0);
	lowest = tmp->ant_num;
	while (tmp && tmp->ant_num != 0)
	{
		if (tmp->ant_num < lowest)
			lowest = tmp->ant_num;
		tmp = tmp->next;
	}
	return (lowest);
}

int		just_sup_ant_num(t_room *path, int current)
{
	t_room	*tmp;
	int		just_sup;

	tmp = path;
	just_sup = 2147483647;
	while (tmp)
	{
		if (tmp->ant_num > current && tmp->ant_num <= just_sup)
			just_sup = tmp->ant_num;
		tmp = tmp->next;
	}
	if (just_sup == 2147483647)
		return (0);
	return (just_sup);
}
