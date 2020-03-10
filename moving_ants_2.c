/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ants_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:14:34 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 19:05:58 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	part_2(int ant_num, char *name)
{
	color_ants(ant_num);
	write(1, "-", 1);
	ft_putstr(name);
	write(1, " ", 1);
}

void	color_ants(int ant_num)
{
	int			color;
	char		*final_text;
	static int	colors[12] = {91, 92, 93, 94, 95, 96, 97, 31, 32, 33, 34, 35};

	color = colors[(ant_num - 1) % 12];
	final_text = ft_strdup("\033[0;");
	final_text = ft_strjoin_free_both(final_text, ft_itoa(color));
	final_text = ft_strjoin_free_both(final_text, ft_strdup(";mL"));
	final_text = ft_strjoin_free_both(final_text, ft_itoa(ant_num));
	final_text = ft_strjoin_free_both(final_text, ft_strdup("\033[0m"));
	ft_putstr(final_text);
	free(final_text);
}

void	print_ants(t_room *path)
{
	int		count;
	int		cursor;
	t_room	*tmp;

	cursor = just_sup_ant_num(path, 0);
	count = lst_count(path);
	while (cursor != 0)
	{
		tmp = path;
		while (tmp->ant_num != cursor)
			tmp = tmp->next;
		color_ants(tmp->ant_num);
		write(1, "-", 1);
		ft_putstr(tmp->name);
		write(1, " ", 1);
		cursor = just_sup_ant_num(path, cursor);
	}
}

void	goto_antnum_n_print(t_room *path1,
		t_room *path2, int ant_num, int total_ants)
{
	t_room *tmp1;
	t_room *tmp2;

	tmp1 = path1;
	tmp2 = path2;
	if (ant_num == 0)
		return ;
	if (ant_num > total_ants)
		return ;
	while (tmp1 && tmp1->ant_num != ant_num)
		tmp1 = tmp1->next;
	while (tmp2 && tmp2->ant_num != ant_num)
		tmp2 = tmp2->next;
	if (tmp1 != NULL)
	{
		color_ants(tmp1->ant_num);
		write(1, "-", 1);
		ft_putstr(tmp1->name);
		write(1, " ", 1);
	}
	if (tmp2 != NULL)
		part_2(tmp2->ant_num, tmp2->name);
}
