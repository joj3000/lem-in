/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:16:57 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 15:55:04 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ct_nb_links(t_room *rooms)
{
	int count;

	count = 0;
	while (rooms->links)
	{
		count++;
		rooms->links = rooms->links->next;
	}
	return (count);
}

int		strlen_til_c(char *s, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

int		strlena_til_c(char *s, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	if (s[i] == '\a')
		i++;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

int		strln_til_ba(char *path)
{
	int i;

	i = 0;
	if (!path)
		return (0);
	if (path[i] == '\a')
		i++;
	while (path[i] && path[i] != '\a')
		i++;
	if (path[0] == '\a')
		return (i - 1);
	return (i);
}

int		count_ba(char *path)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (path[i])
	{
		if (path[i] == '\a')
			count++;
		i++;
	}
	return (count);
}
