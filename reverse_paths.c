/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:53:15 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 20:11:11 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_strcat_til_ba(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
		j++;
	if (src[i] == '\a')
		i++;
	while (src[i] != 0 && src[i] != '\a')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\a';
	j++;
	dest[j] = '\0';
	return (dest);
}

void	set_start(char c, int *start)
{
	*start = 0;
	if (c == '\a')
		*start = 1;
}

char	*reverse_str(char *str)
{
	char	*rev;
	int		i;
	int		j;
	int		start;

	i = ft_strlen(str);
	j = 0;
	(str[0] == '\a' ? (rev = ft_strnew((ft_strlen(str) - 1) + 1)) :
	(rev = ft_strnew(ft_strlen(str) + 1)));
	if (!str)
	{
		free(rev);
		return (NULL);
	}
	if (str[i - 1] == '\a')
		i -= 2;
	set_start(str[0], &start);
	while (i >= start)
	{
		if (str[i] == '\a' || i == start)
			ft_strcat_til_ba(rev, &str[i]);
		i--;
	}
	free(str);
	return (rev);
}

void	reverse_paths(t_room *rooms)
{
	t_room *paths;

	paths = rooms;
	while (paths)
	{
		paths->name = reverse_str(paths->name);
		paths = paths->next;
	}
}
