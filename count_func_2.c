/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_func_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:26:34 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 15:56:02 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lst_count(t_room *rooms)
{
	int		count;
	t_room	*tmp;

	tmp = rooms;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int		size_path(char *path)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (!path)
		return (0);
	while (path[i])
	{
		if (path[i] == '\a')
			count++;
		i++;
	}
	return (count + 1);
}

int		rooms_count(char *path)
{
	int i;
	int count;
	int flag;

	i = 0;
	flag = 0;
	count = 0;
	if (!path)
		return (0);
	if (path[i] == '\a')
		flag++;
	while (path[i])
	{
		if (path[i] == '\a')
			count++;
		i++;
	}
	if (path[i - 1] == '\a')
		flag++;
	return (count - flag + 1);
}
