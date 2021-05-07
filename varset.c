/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:23:48 by ahmcherk          #+#    #+#             */
/*   Updated: 2020/01/25 18:07:41 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_spset(int ac)
{
	int		i;

	i = -1;
	g_gl.sp = (int *)malloc(sizeof(int) * ac);
	while (++i < ac)
		g_gl.sp[i] = 0;
}

int		ft_biglen(char **str)
{
	int		i;
	int		len;
	int		biglen;

	i = 0;
	biglen = 0;
	len = 0;
	while (str[++i])
		if ((len = ft_strlen(str[i])) > biglen)
			biglen = len;
	return (biglen);
}

void	ft_set(int ac, char **av)
{
	if (!isatty(STDIN_FILENO))
	{
		ft_putstr_fd("stdin bad file descriptor.\n", 2);
		exit(-1);
	}
	ft_termset();
	ft_spset(ac);
	g_gl.av = av;
	g_gl.co = tgetnum("co");
	g_gl.li = tgetnum("li");
	g_gl.biglen = ft_biglen(g_gl.av);
	g_gl.cursor = 1;
}
