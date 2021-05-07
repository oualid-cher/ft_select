/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 08:03:10 by ahmcherk          #+#    #+#             */
/*   Updated: 2020/01/25 18:06:31 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_put(int c)
{
	ft_putchar_fd(c, g_gl.fd);
	return (1);
}

int		main(int ac, char **av)
{
	int		c;
	int		i;
	int		dbl_len;

	c = 0;
	g_gl.i = 0;
	i = -1;
	if (ac < 2)
	{
		ft_putendl_fd("usage: ./ft_select [Param 1] [Param 2] [...]", 2);
		return (-1);
	}
	while (++i < 32)
		signal(i, sighandler);
	ft_set(ac, av);
	dbl_len = ac;
	while (1)
	{
		ft_print();
		c = 0;
		read(0, &c, 3);
		ft_keys(c, &dbl_len);
	}
}
