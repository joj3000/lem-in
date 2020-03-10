/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_front_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:31:30 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 19:53:57 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lst_pushback_room(t_room **list, char *str)
{
	t_room *new;
	t_room *init;

	init = *list;
	new = (t_room *)malloc(sizeof(t_room));
	new->name = ft_strdup(str);
	new->next = NULL;
	if (!(*list))
	{
		*list = new;
		return ;
	}
	while (init->next != NULL)
		init = init->next;
	init->next = new;
	return ;
}

t_room	*lst_pushb_room(t_room *old, t_room *path)
{
	t_room *tmp;

	tmp = old;
	if (!old)
		return (path);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = path;
		return (old);
	}
}

void	add_links(t_room **rooms, char *line)
{
	t_room	*tmp;
	char	*tmp2;

	tmp = (*rooms);
	while (ft_strcmp(tmp->name, tmp2 = str_til_c(line, '-')) != 0 && tmp->next)
		tmp = tmp->next;
	links_pushback(&tmp->links, str_after_c(line, '-'));
	free(tmp2);
	tmp = (*rooms);
	while (ft_strcmp(tmp->name,
	ft_strdup(str_after_c(line, '-'))) != 0 && tmp->next)
		tmp = tmp->next;
	links_pushback(&tmp->links, tmp2 = str_til_c(line, '-'));
	free(tmp2);
}
