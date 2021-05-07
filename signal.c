/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:24:08 by ahmcherk          #+#    #+#             */
/*   Updated: 2020/01/25 17:59:04 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_sigwinch(void)
{
	tgetent(NULL, getenv("TERM"));
	g_gl.co = tgetnum("co");
	g_gl.li = tgetnum("li");
	ft_print();
}

static void	ft_cont(void)
{
	ft_termset();
	g_gl.co = tgetnum("co");
	g_gl.li = tgetnum("li");
	ft_print();
	signal(SIGTSTP, sighandler);
	signal(SIGSTOP, sighandler);
	signal(SIGTTIN, sighandler);
	signal(SIGTTOU, sighandler);
}

void		sighandler(int sig)
{
	if (!isatty(STDIN_FILENO))
	{
		ft_putendl_fd("stdin bad file descriptor.\n", 2);
		exit(-1);
	}
	if (sig == SIGWINCH)
		ft_sigwinch();
	else if (sig == SIGSTOP || sig == SIGTSTP || sig == SIGTTIN
			|| sig == SIGTTOU)
	{
		signal(sig, SIG_DFL);
		ft_termreset();
		ioctl(0, TIOCSTI, "\032");
	}
	else if (sig == SIGCONT)
		ft_cont();
	else
	{
		ft_termreset();
		exit(0);
	}
}
