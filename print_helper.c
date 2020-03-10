/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:32:06 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 19:46:54 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
**void	print_room_name(t_room *rooms)
**{
**	t_room *tmp;
**
**	tmp = rooms;
**	while (tmp)
**	{
**		printf("%s\n", tmp->name);
**		tmp = tmp->next;
**	}
**}
**
**void	print_name_vis_lvl(t_room **rooms)
**{
**	while ((*rooms))
**	{
**		printf("\n%s\n", (*rooms)->name);
**		printf("  --> vis = %d\n", (*rooms)->visited);
**		printf("  --> lvl = %d\n", (*rooms)->level);
**		(*rooms) = (*rooms)->next;
**	}
**}
**
**void	print_all(t_room *rooms)
**{
**	t_room *tmp;
**	t_room *lks;
**
**	tmp = rooms;
**	while (tmp)
**	{
**		lks = tmp->links;
**		printf("\n%s\n----\n", tmp->name);
**		while (lks)
**		{
**			printf("%s\n", (lks)->name);
**			lks = lks->next;
**		}
**		tmp = tmp->next;
**	}
**}
**
**void	print_links(t_room *rooms)
**{
**	t_room *tmp;
**	t_room *lks;
**
**	lks = (t_room *)malloc(sizeof(t_room));
**	tmp = rooms;
**	lks = (rooms)->links;
**	tmp->links = lks;
**	write(1, "\n---LINKS of ", 13);
**	ft_putstr(tmp->name);
**	write(1, "---\n", 4);
**	while (tmp->links != NULL)
**	{
**		ft_putstr((tmp->links)->name);
**		write(1, "\n", 1);
**		tmp->links = (tmp->links)->next;
**	}
**	write(1, "-------------\n", 14);
**}
**
**void	print_name_nblinks(t_room **rooms)
**{
**	write(1, "\nname = ", 8);
**	ft_putstr((*rooms)->name);
**	write(1, "\nnb links = ", 12);
**	ft_putnbr(ct_nb_links(*rooms));
**	write(1, "\n", 1);
**}
*/
