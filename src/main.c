/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 15:55:53 by twoerdem       #+#    #+#                */
/*   Updated: 2019/09/12 14:42:39 by twoerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_player(t_filler *filler, char *line)
{
	if (ft_strstr(line, "p2"))
	{
		filler->player = 'x';
		filler->enemy = 'o';
	}
	else
	{
		filler->player = 'o';
		filler->enemy = 'x';
	}
}

int		main(void)
{
	t_filler	*filler;
	char		*line;

	filler = (t_filler *)malloc(sizeof(t_filler));
	get_next_line(0, &line);
	check_player(filler, line);
	free(line);
	while (get_next_line(0, &line))
	{
		free(line);
		make_map(filler, line);
		make_piece(filler);
		trim_piece(filler);
		filler->best_solve_distance = 0;
		solve_filler(filler);
		ft_delmap(filler->map);
		ft_delmap(filler->piece);
		ft_delmap(filler->piece_trimmed);
		ft_putnbr(filler->best_x - filler->start_x);
		ft_putchar(' ');
		ft_putnbr(filler->best_y - filler->start_y);
		ft_putchar('\n');
	}
}
