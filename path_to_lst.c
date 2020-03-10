/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:29:08 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 19:43:12 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*path_to_lst(char *path)
{
	t_room	*new;
	t_room	*to_del;
	char	*tmp;
	int		i;

	i = 0;
	new = NULL;
	if (!path)
		return (NULL);
	if (path[i] == '\a')
		i++;
	while (path[i])
	{
		new = lst_pushb_room(new,
		new_ant_elem(tmp = str_til_c(&path[i], '\a')));
		while (path[i] != '\a' && path[i])
			i++;
		i++;
		free(tmp);
	}
	to_del = new;
	new = new->next;
	free_room(to_del);
	return (new);
}
