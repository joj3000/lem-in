/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_final_paths_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:41:12 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 19:45:22 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		middle_string(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i / 2 + 1);
}

void	print_spaces(int count)
{
	while (count != 0)
	{
		write(1, " ", 1);
		count--;
	}
}

void	print_tube(int count)
{
	if (count != 0)
	{
		print_spaces(count);
		write(1, "|\n", 2);
		print_spaces(count);
		write(1, "\\___ ", 5);
	}
}
