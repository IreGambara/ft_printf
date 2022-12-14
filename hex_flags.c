/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igambara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:04:41 by igambara          #+#    #+#             */
/*   Updated: 2021/02/13 19:04:45 by igambara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexa_pr(char *ret, t_flags flags, int pointer)
{
	char	*p;
	int		i;

	i = 0;
	if (!(p = ft_calloc(flags.precision + 1, 1)))
		return (NULL);
	if (flags.precision > -1)
	{
		while (flags.precision > (int)ft_strlen(ret))
		{
			p[i] = '0';
			i++;
			flags.precision--;
		}
		ret = ft_strjoin2(p, ret);
		if (pointer == 1)
			ret = ft_strjoin("0x", ret);
		flags.width = flags.width ? flags.width : flags.zero;
		if (flags.width > 0)
		{
			if (flags.width > flags.precision)
				ret = ft_hexa_width(ret, flags);
		}
	}
	return (ret);
}

char	*ft_hexa_width(char *ret, t_flags flags)
{
	char	*p;
	int		i;

	i = 0;
	if (!(p = ft_calloc(flags.width + 1, 1)))
		return (NULL);
	while (flags.width > (int)ft_strlen(ret))
	{
		p[i] = ' ';
		i++;
		flags.width--;
	}
	if (flags.minus > 0)
		ret = ft_strjoin1(ret, p);
	else
		ret = ft_strjoin(p, ret);
	free(p);
	return (ret);
}

char	*ft_hexa_zero(char *ret, t_flags flags, int pointer)
{
	char	*p;
	int		i;

	i = 0;
	if (!(p = ft_calloc(flags.width + 1, 1)))
		return (NULL);
	if (flags.zero > 0)
	{
		while (flags.width > (int)ft_strlen(ret) + pointer)
		{
			p[i] = '0';
			i++;
			flags.width--;
		}
		ret = ft_strjoin(p, ret);
		free(p);
	}
	if (pointer == 1)
		ret = ft_strjoin("0x", ret);
	return (ret);
}

char	*ft_hexa(char *ret, t_flags flags, char c)
{
	int pointer;

	pointer = (c == 'p');
	if (flags.precision == 0 && ret[0] == '0')
		ret[0] = 0;
	if (flags.precision > -1)
		ret = ft_hexa_pr(ret, flags, pointer);
	else if (flags.zero > 0 && !flags.minus)
		ret = ft_hexa_zero(ret, flags, pointer);
	else if (flags.width > 0)
	{
		if (pointer)
			ret = ft_strjoin("0x", ret);
		ret = ft_hexa_width(ret, flags);
	}
	else if (pointer)
		ret = ft_strjoin("0x", ret);
	return (ret);
}
