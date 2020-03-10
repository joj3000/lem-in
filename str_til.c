/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_til.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:33:48 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 20:14:21 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*dup_til_char(char *s, char c)
{
	int		i;
	int		count;
	char	*cpy;

	i = 0;
	count = 0;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	cpy = (char *)malloc(sizeof(char) * count + 1);
	i = 0;
	while (s[i] && s[i] != c)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char	*str_til_c(char *s, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * strlen_til_c(s, c) + 1);
	while (s[i] && s[i] != c)
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

char	*stra_til_c(char *s, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * strlena_til_c(s, c) + 1);
	if (!s)
		return (NULL);
	if (s[i] == '\a')
		i++;
	while (s[i] && s[i] != c)
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

char	*str_till_ba(char *patht)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = (char *)malloc(sizeof(char) * strln_til_ba(patht) + 1);
	if (patht[0] == '\a')
		i++;
	while (patht[i] && patht[i] != '\a')
	{
		tmp[j] = patht[i];
		j++;
		i++;
	}
	tmp[j] = 0;
	return (tmp);
}

char	*cut_st_end(char *path)
{
	char	*new;
	int		flag_s;
	int		flag_e;
	int		i;

	i = 0;
	if (!path || count_ba(path) <= 1)
		return (NULL);
	if (path[i] == '\a')
		i++;
	while (path[i] != '\a')
		i++;
	flag_s = i + 1;
	i = ft_strlen(path) - 1;
	if (path[i] == '\a')
		i--;
	while (path[i] != '\a')
		i--;
	flag_e = i;
	new = (char *)malloc(sizeof(char) * (flag_e - flag_s) + 1);
	i = 0;
	while (flag_s < flag_e)
		new[i++] = path[flag_s++];
	new[i] = 0;
	return (new);
}
