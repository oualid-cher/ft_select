/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:21:39 by ahmcherk          #+#    #+#             */
/*   Updated: 2020/01/25 17:25:08 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_termset(void)
{
	g_gl.fd = open("/dev/tty", O_RDWR);
	tcgetattr(0, &g_gl.new);
	g_gl.old = g_gl.new;
	g_gl.new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, 0, &g_gl.new);
	if (tgetent(NULL, getenv("TERM")) < 1)
	{
		ft_putendl_fd("Environment Error", 2);
		exit(-1);
	}
	tputs(tgetstr("vi", NULL), 1, ft_put);
	tputs(tgetstr("ti", NULL), 1, ft_put);
}

void	ft_termreset(void)
{
	tcsetattr(0, 0, &g_gl.old);
	tputs(tgetstr("ve", NULL), 1, ft_put);
	tputs(tgetstr("te", NULL), 1, ft_put);
	close(g_gl.fd);
}
