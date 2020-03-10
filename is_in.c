/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:40:25 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 18:24:51 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	is_char_or_ht(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			if (s[0] != '#')
				return (1);
		i++;
	}
	return (0);
}

int	is_end_present(char *s, char *end)
{
	if (ft_strcmp(s, end) == 0)
		return (1);
	else
		return (0);
}

int	is_c(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_in(t_room *rooms, char *s)
{
	t_room *tmp;

	tmp = rooms;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, s) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_c_in(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
