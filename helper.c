/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:57:00 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 16:27:26 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*str_after_c(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (&str[++i]);
}

int		was_visited(t_room *rooms, char *name)
{
	t_room *tmp;

	tmp = rooms;
	while (ft_strcmp(tmp->name, name) != 0 && tmp->next)
		tmp = tmp->next;
	if (tmp->visited == 0)
		return (0);
	return (1);
}

t_room	*new_ant_elem(char *room_name)
{
	t_room *new;

	new = (t_room *)malloc(sizeof(t_room));
	new->name = ft_strdup(room_name);
	new->ant_num = 0;
	new->next = NULL;
	return (new);
}

int		are_st_end_connected(t_room *rooms, char *end)
{
	t_room *tmp;

	tmp = go_to_lst(rooms, end);
	if (tmp->level == 2147483647)
		return (0);
	else
		return (1);
}

t_room	*cure(t_room *final_lst)
{
	t_room *tmp;

	if (lst_count(final_lst) == 2)
	{
		if (ft_strcmp(final_lst->name, final_lst->next->name) == 0)
		{
			tmp = final_lst->next;
			free(final_lst->name);
			free(final_lst);
			return (tmp);
		}
		return (final_lst);
	}
	else
		return (final_lst);
}
