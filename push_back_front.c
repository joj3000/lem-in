/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:23:00 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 19:52:01 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lst_pushback(t_room **list, char *line)
{
	t_room *new;
	t_room *init;

	init = *list;
	new = (t_room *)malloc(sizeof(t_room));
	new->links = (t_room *)malloc(sizeof(t_room));
	new->name = dup_til_char(line, ' ');
	new->links = NULL;
	new->next = NULL;
	new->visited = 0;
	new->level = 2147483647;
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

void	links_pushback_part2(t_room **rooms, char *s)
{
	(*rooms) = (t_room *)malloc(sizeof(t_room));
	(*rooms)->name = ft_strdup(s);
	((*rooms)->links) = (t_room *)malloc(sizeof(t_room));
	(*rooms)->links = NULL;
	(*rooms)->next = NULL;
	(*rooms)->visited = 0;
}

void	links_pushback(t_room **rooms, char *s)
{
	t_room		*new;
	t_room		*init;
	static int	i = 0;

	init = (*rooms);
	if (i == 0)
	{
		*rooms = (t_room *)malloc(sizeof(t_room));
		*rooms = NULL;
		i++;
	}
	if (!(*rooms))
		links_pushback_part2(rooms, s);
	else
	{
		new = (t_room *)malloc(sizeof(t_room));
		new->name = ft_strdup(s);
		new->links = (t_room *)malloc(sizeof(t_room));
		(new)->links = NULL;
		new->next = NULL;
		new->visited = 0;
		while (init->next != NULL)
			init = init->next;
		init->next = new;
	}
}

void	gpaths_pushback(t_room **rooms, char *path)
{
	t_room *new;
	t_room *init;

	if (!((*rooms)->g_paths))
	{
		new = (t_room *)malloc(sizeof(t_room));
		new->name = ft_strdup(path);
		new->next = NULL;
		(*rooms)->g_paths = new;
	}
	else
	{
		init = (*rooms)->g_paths;
		new = (t_room *)malloc(sizeof(t_room));
		new->name = ft_strdup(path);
		new->next = NULL;
		while (init->next != NULL)
			init = init->next;
		init->next = new;
	}
}

void	lst_pushcpyfront(t_room **paths, t_room *tmp)
{
	t_room *cpy;

	cpy = (t_room *)malloc(sizeof(t_room));
	cpy->next = NULL;
	cpy->name = ft_strdup(tmp->name);
	cpy->level = tmp->level;
	cpy->next = (*paths);
	*paths = cpy;
}
