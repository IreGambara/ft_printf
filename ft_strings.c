/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igambara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:04:28 by igambara          #+#    #+#             */
/*   Updated: 2021/02/13 19:04:32 by igambara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strings(char *ret, t_flags flags)
{
	if (flags.precision == -1 && flags.width == 0)
		return (ret);
	if (flags.precision == 0)
	{
		free(ret);
		ret = (ft_strdup(""));
	}
	else if (flags.precision)
	{
		if ((size_t)flags.precision < ft_strlen(ret))
			ret[flags.precision] = 0;
	}
	if (flags.width && (size_t)flags.width > ft_strlen(ret))
		ret = ft_spaces(ret, flags);
	return (ret);
}
