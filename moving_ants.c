/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:10:30 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 19:01:04 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	one_path_mvt(t_room *path, int total_ants)
{
	int count;

	count = 1;
	if (!path)
		return ;
	path->ant_num = 1;
	while (path_contains_ant(path) != 0)
	{
		if (count > total_ants)
		{
			shift_ants_next_room(path, 0);
			print_ants(path);
		}
		else
		{
			shift_ants_next_room(path, count);
			print_ants(path);
		}
		write(1, "\n", 1);
		count++;
	}
}

void	two_paths_mvt_2(t_room *path1, t_room *path2,
		int total_ants, int *count)
{
	if (*count <= total_ants + 1)
	{
		*count = *count + 1;
		shift_ants_next_room(path1, *count);
		*count = *count + 1;
		shift_ants_next_room(path2, *count);
	}
	else
	{
		shift_ants_next_room(path1, 0);
		shift_ants_next_room(path2, 0);
	}
	write(1, "\n", 1);
}

void	two_paths_mvt(t_room *path1, t_room *path2, int total_ants)
{
	int		count;
	int		ct;
	t_room	*tmp1;
	t_room	*tmp2;

	if (!path1 || !path2)
		return ;
	path1->ant_num = 1;
	path2->ant_num = 2;
	count = 2;
	ct = 0;
	tmp1 = path1;
	tmp2 = path2;
	while (path_contains_ant(path1) != 0 && path_contains_ant(path2) != 0)
	{
		ct = 0;
		while (ct <= count)
		{
			goto_antnum_n_print(path1, path2, ct, total_ants);
			ct++;
		}
		two_paths_mvt_2(path1, path2, total_ants, &count);
	}
}

void	moving_ants(t_room *final_list, int total_ants)
{
	t_room *path1;
	t_room *path2;

	if (lst_count(final_list) >= 2)
	{
		path1 = path_to_lst(final_list->name);
		path2 = path_to_lst(final_list->next->name);
		two_paths_mvt(path1, path2, total_ants);
	}
	else
	{
		path1 = path_to_lst(final_list->name);
		one_path_mvt(path1, total_ants);
	}
}
