/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_final_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:38:12 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 19:44:57 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		print_room_1(char *s, int i, int count)
{
	char *tmp;

	(void)count;
	write(1, "(", 2);
	ft_putstr(tmp = str_til_c(&s[i], '\a'));
	write(1, ")", 2);
	free(tmp);
}

static void		print_only_one_path(char *s)
{
	int		i;
	int		count_spaces;
	char	*tmp;

	count_spaces = 0;
	i = 0;
	while (s[i])
	{
		write(1, "\n", 1);
		print_tube(count_spaces);
		if (count_spaces == 0)
		{
			print_spaces(5 + (middle_string((tmp = str_til_c(&s[i], '\a')))
			/ 2));
			free(tmp);
		}
		print_room_1(s, i, count_spaces);
		count_spaces += 5 + middle_string(tmp = str_til_c(&s[i], '\a'));
		free(tmp);
		while (s[i] && s[i] != '\a')
			i++;
		if (s[i] == '\a')
			i++;
	}
	write(1, "\n", 1);
}

void			print_final_paths(t_room *final)
{
	t_room *tmp;

	tmp = final;
	if (!final)
		return ;
	if (lst_count(final) == 1)
	{
		print_only_one_path(final->name);
	}
	else
	{
		print_only_one_path(final->name);
		print_only_one_path(final->next->name);
	}
	free_lst(final);
}
