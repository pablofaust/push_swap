/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:10:10 by pfaust            #+#    #+#             */
/*   Updated: 2018/11/28 12:00:17 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbinstr(const char *s)
{
	unsigned int	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			ft_putchar(s[i++]);
			if (i % 4 == 0)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
