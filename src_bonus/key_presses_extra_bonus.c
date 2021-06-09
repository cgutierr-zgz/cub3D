/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_presses_extra_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:43:07 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/09 14:53:57 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	key_m(t_cub *cub)
{
	cub->show_minimap = 1;
}

void	*llamar_system(void *str)
{
	char	*cosa;

	cosa = str;
	system(cosa);
	return (NULL);
}

void	key_space(t_cub *cub)
{
	int	x;
	int	y;

	cub->mov.place = 0;
	cub->attack = 1;
	x = (int)(cub->raycast.posx + cub->raycast.dirx);
	y = (int)(cub->raycast.posy + cub->raycast.diry);
	if (cub->map.map_matrix[x][y] == '9')
		cub->map.map_matrix[x][y] = '0';
	else if (cub->map.map_matrix[x][y] == '0')
		cub->map.map_matrix[x][y] = '9';
}

void	key_enter(t_cub *cub)
{
	int			x;
	int			y;
	pthread_t	threads;

	cub->attack = 1;
	x = (int)(cub->raycast.posx + cub->raycast.dirx);
	y = (int)(cub->raycast.posy + cub->raycast.diry);
	if (cub->map.map_matrix[x][y] == '4')
	{
		cub->map.map_matrix[x][y] = '0';
		cub->search.x = x;
		cub->search.y = y;
		pthread_create(&threads, 0, (void *)llamar_system, (void *)"say damn!");
		iter_cub_sprite_list(cub, cub->txtrs.sprite_list);
	}
}

void	key_e(t_cub *cub)
{
	int	x;
	int	y;

	cub->enter_tp = 1;
	x = (int)(cub->raycast.posx + cub->raycast.dirx * cub->mov.mov_s);
	y = (int)(cub->raycast.posy + cub->raycast.diry * cub->mov.mov_s);
	if (cub->map.map_matrix[x][y] == '5' && cub->enter_tp == 1)
	{
		if (cub->start_tp.x == x && cub->start_tp.y == y)
		{
			cub->raycast.posx = (double)cub->end_tp.x + 0.5;
			cub->raycast.posy = (double)cub->end_tp.y + 0.5;
		}
		else
		{
			cub->raycast.posx = (double)cub->start_tp.x + 0.5;
			cub->raycast.posy = (double)cub->start_tp.y + 0.5;
		}
	}
	cub->enter_tp = 0;
}
