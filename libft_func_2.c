/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:49:58 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 18:30:29 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_atoi(char *str)
{
	int i;
	int neg;
	int nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i])
		i++;
	if (str[i] == '-' && str[i])
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= 48 && str[i] <= 57))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (neg * nb);
}

static void		modulo_count(long int n, long int *count)
{
	long int r;

	if (n >= 1)
	{
		r = n % 10;
		n = (n - r) / 10;
		modulo_count(n, count);
		*count = *count + 1;
	}
}

static long int	malloc_count(long int n)
{
	long int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	if (n < 0)
		n *= -1;
	modulo_count(n, &count);
	return (count);
}

static void		modulo_put_in_str(long int n,
		char *str, char *str_base, int *index)
{
	long int r;

	if (n < 0)
		n *= -1;
	if (n >= 1)
	{
		*index = *index - 1;
		r = n % 10;
		n = (n - r) / 10;
		str[*index] = str_base[r];
		modulo_put_in_str(n, str, str_base, index);
	}
}

char			*ft_itoa(int n)
{
	char		*str_base;
	long int	n2;
	char		*str;
	int			index;
	int			end;

	str_base = "0123456789";
	n2 = n;
	if (n2 == 0)
	{
		str = malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	index = malloc_count(n2);
	end = malloc_count(n2);
	if (!(str = (char *)malloc(sizeof(char) * (malloc_count(n2) + 1))))
		return (0);
	modulo_put_in_str(n2, str, str_base, &index);
	str[end] = '\0';
	if (n2 < 0)
		str[0] = '-';
	return (str);
}
