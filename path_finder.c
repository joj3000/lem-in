/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:41:03 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 19:41:13 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_strjoin_free_test(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	i = 0;
	k = 0;
	while (s1[k])
		str[i++] = s1[k++];
	k = 0;
	while (s2[k])
	{
		str[i] = s2[k];
		i++;
		k++;
	}
	str[i] = 0;
	if (s1 || s1 != NULL)
		free(s1);
	return (str);
}

int		other_paths_inf_level(t_room *rooms, t_room *name)
{
	t_room	*tmp;
	t_room	*lks;
	t_room	*lks_cpy;
	int		flag;

	tmp = name;
	lks = name->links;
	flag = 0;
	while (lks)
	{
		lks_cpy = go_to_lst(rooms, lks->name);
		if (lks_cpy->level == name->level - 1)
			flag++;
		lks = lks->next;
	}
	if (flag >= 2)
		return (1);
	else
		return (0);
}

t_room	*recursive_other_path_finder(t_room **rooms,
		char *go_to, char *path, int level)
{
	t_room			*tmp;
	t_room			*lks;
	static t_room	*final = NULL;

	tmp = go_to_lst(*rooms, go_to);
	if (ft_strstra(path, tmp->name) == 1 || level < -1)
		return (NULL);
	if (ft_strstra(path, tmp->name) == 0)
	{
		if (path && tmp->name)
			path = ft_strjoin_free(path, tmp->name);
	}
	if (ft_strstra(path, (*rooms)->start) == 1)
	{
		lst_pushback(&final, path);
		return (final);
	}
	lks = tmp->links;
	while (lks)
	{
		recursive_other_path_finder(rooms, lks->name, path, level - 1);
		lks = lks->next;
	}
	free(path);
	return (final);
}

void	flag_shortest(t_room *paths)
{
	t_room	*tmp;
	int		shortest;

	tmp = paths;
	if (!paths)
		return ;
	shortest = size_path(paths->name);
	while (tmp)
	{
		if (size_path(tmp->name) < shortest)
			shortest = size_path(tmp->name);
		tmp = tmp->next;
	}
	tmp = paths;
	while (tmp)
	{
		if (size_path(tmp->name) == shortest)
			tmp->shortest = 1;
		else
			tmp->shortest = 0;
	}
}

t_room	*return_shortest(t_room *paths)
{
	t_room	*tmp;
	int		shortest;

	tmp = paths;
	if (!paths)
		return (NULL);
	shortest = size_path(paths->name);
	while (tmp)
	{
		if (size_path(tmp->name) < shortest)
			shortest = size_path(tmp->name);
		tmp = tmp->next;
	}
	tmp = paths;
	while (tmp)
	{
		if (size_path(tmp->name) == shortest)
		{
			tmp = create_new_name(tmp->name);
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
