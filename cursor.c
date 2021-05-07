/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 08:44:20 by ahmcherk          #+#    #+#             */
/*   Updated: 2020/01/25 17:33:15 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_checkwin(void)
{
	int		len;

	len = ft_strdbllen(g_gl.av);
	if (((g_gl.co / g_gl.biglen) * g_gl.li) < len)
	{
		ft_putstr_fd("Window Too Small", g_gl.fd);
		return (1);
	}
	return (0);
}

void		ft_print(void)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = -1;
	tputs(tgetstr("cl", NULL), 1, ft_put);
	if (ft_checkwin())
		return ;
	while (g_gl.av[++i])
	{
		if (i == g_gl.cursor)
			tputs(tgetstr("us", NULL), 1, ft_put);
		if (g_gl.sp[i])
			tputs(tgetstr("mr", NULL), 1, ft_put);
		x = ((i - 1) / g_gl.li) * (g_gl.biglen + 1);
		y = (i - 1) % g_gl.li;
		tputs(tgoto(tgetstr("cm", NULL), x, y), 1, ft_put);
		ft_putstr_fd(g_gl.av[i], g_gl.fd);
		if (i == g_gl.cursor)
			tputs(tgetstr("ue", NULL), 1, ft_put);
		if (g_gl.sp[i])
			tputs(tgetstr("me", NULL), 1, ft_put);
	}
}
