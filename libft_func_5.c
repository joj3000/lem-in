/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:29:05 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 18:54:16 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		*ft_memset(void *b, int c, int len)
{
	int			i;
	char		*str;

	str = (char *)b;
	i = 0;
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}

void		ft_bzero(void *s, int n)
{
	if (n == 0)
		return ;
	ft_memset(s, 0, n);
}

char		*ft_strnew(int size)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(str, size);
	str[size] = '\0';
	return (str);
}

char		*ft_strsub(char *s, int start, int len)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(cpy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len)
	{
		cpy[i] = s[start + i];
		len--;
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}
