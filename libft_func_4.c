/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:02:05 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 18:53:19 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	i = 0;
	k = 0;
	while (s1[k])
		str[i++] = s1[k++];
	k = 0;
	while (s2[k])
	{
		str[i] = s2[k];
		i++;
		k++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	i = 0;
	k = 0;
	while (s1[k])
		str[i++] = s1[k++];
	k = 0;
	str[i++] = '\a';
	while (s2[k])
	{
		str[i] = s2[k];
		i++;
		k++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin_free_both(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	i = 0;
	k = 0;
	while (s1[k])
		str[i++] = s1[k++];
	k = 0;
	while (s2[k])
	{
		str[i] = s2[k];
		i++;
		k++;
	}
	str[i] = 0;
	free(s1);
	free(s2);
	return (str);
}

int		ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*casted_haystack;

	i = 0;
	j = 0;
	casted_haystack = (char *)haystack;
	if (needle[0] == 0)
		return (-1);
	while (casted_haystack[i] != 0)
	{
		while (casted_haystack[i + j] == needle[j] && needle[j] != 0)
		{
			if (needle[j + 1] == 0)
				return (1);
			j++;
		}
		if (casted_haystack[i + j] != needle[j])
			j = 0;
		i++;
	}
	return (0);
}

int		ft_strstra(char *path, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!path)
		return (0);
	while (path[i])
	{
		if (ft_strcmp(tmp = str_till_ba(&path[i]), str) == 0)
		{
			free(tmp);
			return (1);
		}
		if (path[i] == '\a')
			i++;
		while (path[i] && path[i] != '\a')
			i++;
		free(tmp);
	}
	return (0);
}
