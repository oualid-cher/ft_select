/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:05:38 by ahmcherk          #+#    #+#             */
/*   Updated: 2020/01/25 16:21:57 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_arrows(int c, int *dbl_len)
{
	if (c == KEYDOWN)
		if (++g_gl.cursor > *dbl_len - 1)
			g_gl.cursor = 1;
	if (c == KEYUP)
		if (--g_gl.cursor < 1)
			g_gl.cursor = *dbl_len - 1;
	if (c == KEYRIGHT)
		if ((g_gl.cursor += g_gl.li) > *dbl_len - 1)
			g_gl.cursor = (g_gl.cursor - 1) % g_gl.li + 1;
	if (c == KEYLEFT)
		if ((g_gl.cursor -= g_gl.li) < 1)
			if ((g_gl.cursor += g_gl.li + ((*dbl_len - 1) / g_gl.li) *
			g_gl.li) > *dbl_len - 1)
				g_gl.cursor -= g_gl.li;
}

static void	ft_del(int c, int *dbl_len)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < g_gl.cursor)
		;
	while (i < *dbl_len - 1)
	{
		g_gl.av[i] = g_gl.av[i + 1];
		g_gl.sp[i] = g_gl.sp[i + 1];
		i++;
	}
	g_gl.av[i] = NULL;
	*dbl_len -= 1;
	if (g_gl.cursor > *dbl_len - 1)
		g_gl.cursor = *dbl_len - 1;
	if (*dbl_len == 1)
	{
		ft_termreset();
		exit(0);
	}
}

static void	ft_enter(int dbl_len)
{
	int		i;
	int		k;

	i = -1;
	k = 0;
	ft_termreset();
	while (++i < dbl_len - 1)
		if (g_gl.sp[i])
		{
			if (k)
				ft_putchar_fd(' ', 1);
			if (!k)
				k = 1;
			ft_putstr_fd(g_gl.av[i], 1);
		}
	exit(1);
}

void		ft_keys(int c, int *dbl_len)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	j = -1;
	tmp = NULL;
	if (c == 27)
	{
		ft_termreset();
		exit(0);
	}
	ft_arrows(c, dbl_len);
	if (c == ' ')
	{
		g_gl.sp[g_gl.cursor] = g_gl.sp[g_gl.cursor] ? 0 : 1;
		if (++g_gl.cursor > *dbl_len - 1)
			g_gl.cursor = 1;
	}
	if (c == 127)
		ft_del(c, dbl_len);
	if (c == '\n')
		ft_enter(*dbl_len);
}
