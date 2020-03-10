/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:33:47 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 16:18:41 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	levels_errors(t_room *rooms, char **st_end, int *flag)
{
	if (rooms)
	{
		mark_start(rooms, st_end[0]);
		mark_levels(rooms, st_end[0], -1);
	}
	if (error_management_2(rooms, st_end, &flag) == 1)
	{
		ft_putstr("\033[0;91;mERROR\033[0m\n");
		free_everything_2(rooms, st_end, flag);
		return (0);
	}
	return (1);
}

int	error_management(char **line, int **flag)
{
	static int	first = 0;
	static int	flag_start = 0;
	static int	flag_end = 0;
	static int	flag_total_ants = 0;
	static int	flag_exist_room = 0;

	first++;
	if ((*flag)[1] == -2)
		return (1);
	if (is_digit_only(*line) && first == 1 && ft_atoi(*line) != 0)
		flag_total_ants = 1;
	if (ft_strcmp(*line, "##start") == 0)
		flag_start = 1;
	if (ft_strcmp(*line, "##end") == 0)
		flag_end = 1;
	if (is_char_or_ht(*line, ' ') == 1)
		flag_exist_room = 1;
	if (is_char_or_ht(*line, '-') == 1)
	{
		(*flag)[2] = 1;
		if (flag_start == 0 || flag_end == 0 ||
		flag_total_ants == 0 || flag_exist_room == 0)
			return (1);
	}
	return (0);
}

int	error_management_2(t_room *rooms, char **st_end, int **flag)
{
	if (!rooms || !st_end || !flag)
		return (1);
	if (*flag[2] == -1)
	{
		ft_putstr("\033[0;91;mERROR\033[0m\n");
		return (1);
	}
	if (!go_to_lst(rooms, st_end[1]))
		return (1);
	if (are_st_end_connected(rooms, (st_end)[1]) == 0)
		return (1);
	return (0);
}
