/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indepance.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:47:14 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 18:21:38 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*part2(char *tmp_name, char *inter_name)
{
	t_room *new;
	t_room *new2;

	new = create_new_name(tmp_name);
	new2 = create_new_name(inter_name);
	new->next = new2;
	return (new);
}

void	are_independant_2(char *cut_path1, char *cut_path2, char *tmp, int a)
{
	if (a == 1)
		free(tmp);
	free(cut_path1);
	free(cut_path2);
}

t_room	*create_new_name(char *s)
{
	t_room *new;

	new = (t_room *)malloc(sizeof(t_room));
	new->name = ft_strdup(s);
	new->next = NULL;
	return (new);
}

int		are_independant(char *path2, char *path1)
{
	char	*cut_path1;
	char	*cut_path2;
	char	*tmp;
	int		i;

	i = 0;
	cut_path1 = cut_st_end(path1);
	cut_path2 = cut_st_end(path2);
	if (!cut_path1 || !cut_path2)
		return (1);
	while (cut_path1[i])
	{
		if (ft_strstra(cut_path2, tmp = stra_til_c(&cut_path1[i], '\a')) == 1)
		{
			are_independant_2(cut_path1, cut_path2, tmp, 1);
			return (0);
		}
		while (cut_path1[i] != '\a' && cut_path1[i])
			i++;
		if (cut_path1[i] != 0)
			i++;
		free(tmp);
	}
	are_independant_2(cut_path1, cut_path2, tmp, 0);
	return (1);
}

t_room	*create_indep_lst(t_room *paths_lst)
{
	t_room *tmp;
	t_room *inter;

	tmp = paths_lst;
	if (lst_count(paths_lst) == 1)
		return (create_new_name(paths_lst->name));
	while (tmp)
	{
		inter = tmp;
		while (inter)
		{
			if (are_independant(tmp->name, inter->name) == 1)
				return (part2(tmp->name, inter->name));
			inter = inter->next;
		}
		tmp = tmp->next;
	}
	return (return_shortest(paths_lst));
}
