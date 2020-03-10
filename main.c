/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 08:16:40 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 20:48:19 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		do_shit(t_room *rooms, char **st_end, int *flag)
{
	t_room *finalst;

	rooms->start = st_end[0];
	rooms->g_paths = recursive_other_path_finder(&rooms, st_end[1], "",
	level_of_name(rooms, st_end[1]));
	reverse_paths(rooms->g_paths);
	rooms->indep_lst = create_indep_lst(rooms->g_paths);
	moving_ants(finalst = cure(final_list(rooms, flag[1])), flag[1]);
	free_lst(finalst);
	print_final_paths(cure(final_list(rooms, flag[1])));
}

void		initialize_things(char **st_end, int *flag)
{
	flag[0] = -1;
	flag[1] = -1;
	flag[2] = -1;
	st_end[0] = NULL;
	st_end[1] = NULL;
}

void		gnl_part2(t_room **rooms, char **line, int **flag)
{
	if (ft_strcmp(*line, "##start") == 0)
		*flag[0] = 1;
	if (ft_strcmp(*line, "##end") == 0)
		*flag[0] = 2;
	if (is_char_or_ht(*line, ' ') == 1)
		lst_pushback(rooms, *line);
	else if (is_char_or_ht(*line, '-') == 1)
		add_links(rooms, *line);
	free(*line);
}

int			gnl(t_room **rooms, char **line, char **st_end, int **flag)
{
	static int flag1 = -1;

	if (flag1 == -1)
	{
		flag1 = ft_atoi(*line);
		*flag[0] = 0;
	}
	if (*flag[0] == 1)
	{
		if (is_c(*line, ' ') == 1)
			st_end[0] = str_til_c(*line, ' ');
		else
			return (-2);
		*flag[0] = 0;
	}
	if (*flag[0] == 2)
	{
		if (is_c(*line, ' ') == 1)
			st_end[1] = str_til_c(*line, ' ');
		else
			return (-2);
		*flag[0] = 8;
	}
	gnl_part2(rooms, line, flag);
	return (flag1);
}

int			main(void)
{
	char	*line;
	t_room	*rooms;
	char	**st_end;
	int		*flag;

	rooms = NULL;
	flag = (int *)malloc(sizeof(int) * 3);
	st_end = (char **)malloc(sizeof(char *) * 2);
	initialize_things(st_end, flag);
	while (get_next_line(0, &line) > 0)
	{
		if (error_management(&line, &flag) == 1)
		{
			ft_putstr("\033[0;91;mERROR\033[0m\n");
			free_everything(rooms, line, st_end, flag);
			return (0);
		}
		flag[1] = gnl(&rooms, &line, st_end, &flag);
	}
	if (levels_errors(rooms, st_end, flag) == 0)
		return (0);
	do_shit(rooms, st_end, flag);
	free_everything_2(rooms, st_end, flag);
}
