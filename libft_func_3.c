/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:52:52 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 18:51:16 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*ft_strchr(char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	if (!(char)c || ft_strlen(s) == 0)
		return (str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

int			ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	i = 0;
	c_s1 = (unsigned char *)s1;
	c_s2 = (unsigned char *)s2;
	while (c_s1[i] == c_s2[i] && c_s1[i] != 0 && c_s2[i] != 0)
		i++;
	return (c_s1[i] - c_s2[i]);
}

char		*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	i = ft_strlen(s1);
	if (!(str = malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void		ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}
