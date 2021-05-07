/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:58:26 by ahmcherk          #+#    #+#             */
/*   Updated: 2020/01/25 17:24:34 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_SELECT_H
# define _FT_SELECT_H
# include "libft/libft.h"

typedef struct	s_global
{
	struct termios	old;
	struct termios	new;
	int				co;
	int				li;
	int				i;
	int				*sp;
	char			**av;
	int				biglen;
	int				cursor;
	int				fd;
}				t_global;
t_global		g_gl;
int				ft_put(int c);
void			ft_print(void);
void			ft_termset(void);
void			ft_termreset(void);
void			ft_spset(int ac);
int				ft_biglen(char **str);
void			ft_set(int ac, char **av);
void			ft_keys(int c, int *dbl_len);
void			sighandler(int sig);
#endif
