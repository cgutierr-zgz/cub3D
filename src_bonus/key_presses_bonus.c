/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_presses_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 23:13:50 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/26 18:43:14 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	key_w(t_cub *cub)
{
	int	x;
	int	y;

	x = (int)(cub->raycast.posx + cub->raycast.dirx * cub->mov.mov_s);
	y = (int)(cub->raycast.posy);
	if (cub->map.map_matrix[x][y] != '1' && cub->map.map_matrix[x][y] != '2')
	{
		if (cub->map.map_matrix[x][y] == '3' && cub->vida < 5)
			sumar_vida(cub, x, y);
		else if (cub->map.map_matrix[x][y] == '4' && cub->vida > 0)
			restar_vida(cub, x, y);
		cub->raycast.posx += cub->raycast.dirx * cub->mov.mov_s;
	}
	x = (int)(cub->raycast.posx);
	y = (int)(cub->raycast.posy + cub->raycast.diry * cub->mov.mov_s);
	if (cub->map.map_matrix[x][y] != '1' && cub->map.map_matrix[x][y] != '2')
	{
		if (cub->map.map_matrix[x][y] == '3' && cub->vida < 5)
			sumar_vida(cub, x, y);
		else if (cub->map.map_matrix[x][y] == '4' && cub->vida > 0)
			restar_vida(cub, x, y);
		cub->raycast.posy += cub->raycast.diry * cub->mov.mov_s;
	}
}

void	key_a(t_cub *cub)
{
	int	x;
	int	y;

	x = (int)(cub->raycast.posx - cub->raycast.planex * cub->mov.mov_s);
	y = (int)(cub->raycast.posy);
	if (cub->map.map_matrix[x][y] != '1' && cub->map.map_matrix[x][y] != '2')
	{
		if (cub->map.map_matrix[x][y] == '3' && cub->vida < 5)
			sumar_vida(cub, x, y);
		else if (cub->map.map_matrix[x][y] == '4' && cub->vida > 0)
			restar_vida(cub, x, y);
		cub->raycast.posx -= cub->raycast.planex * cub->mov.mov_s;
	}
	x = (int)(cub->raycast.posx);
	y = (int)(cub->raycast.posy - cub->raycast.planey * cub->mov.mov_s);
	if (cub->map.map_matrix[x][y] != '1' && cub->map.map_matrix[x][y] != '2')
	{
		if (cub->map.map_matrix[x][y] == '3' && cub->vida < 5)
			sumar_vida(cub, x, y);
		else if (cub->map.map_matrix[x][y] == '4' && cub->vida > 0)
			restar_vida(cub, x, y);
		cub->raycast.posy -= cub->raycast.planey * cub->mov.mov_s;
	}
}

void	key_s(t_cub *cub)
{
	int	x;
	int	y;

	x = (int)(cub->raycast.posx - cub->raycast.dirx * cub->mov.mov_s);
	y = (int)(cub->raycast.posy);
	if (cub->map.map_matrix[x][y] != '1' && cub->map.map_matrix[x][y] != '2')
	{
		if (cub->map.map_matrix[x][y] == '3' && cub->vida < 5)
			sumar_vida(cub, x, y);
		else if (cub->map.map_matrix[x][y] == '4' && cub->vida > 0)
			restar_vida(cub, x, y);
		cub->raycast.posx -= cub->raycast.dirx * cub->mov.mov_s;
	}
	x = (int)(cub->raycast.posx);
	y = (int)(cub->raycast.posy - cub->raycast.diry * cub->mov.mov_s);
	if (cub->map.map_matrix[x][y] != '1'
		&& cub->map.map_matrix[x][y] != '2')
	{
		if (cub->map.map_matrix[x][y] == '3' && cub->vida < 5)
			sumar_vida(cub, x, y);
		else if (cub->map.map_matrix[x][y] == '4' && cub->vida > 0)
			restar_vida(cub, x, y);
		cub->raycast.posy -= cub->raycast.diry * cub->mov.mov_s;
	}
}

void	key_d(t_cub *cub)
{
	int	x;
	int	y;

	x = (int)(cub->raycast.posx + cub->raycast.planex * cub->mov.mov_s);
	y = (int)(cub->raycast.posy);
	if (cub->map.map_matrix[x][y] != '1' && cub->map.map_matrix[x][y] != '2')
	{
		if (cub->map.map_matrix[x][y] == '3' && cub->vida < 5)
			sumar_vida(cub, x, y);
		else if (cub->map.map_matrix[x][y] == '4' && cub->vida > 0)
			restar_vida(cub, x, y);
		cub->raycast.posx += cub->raycast.planex * cub->mov.mov_s;
	}
	x = (int)(cub->raycast.posx);
	y = (int)(cub->raycast.posy + cub->raycast.planey * cub->mov.mov_s);
	if (cub->map.map_matrix[x][y] != '1' && cub->map.map_matrix[x][y] != '2')
	{
		if (cub->map.map_matrix[x][y] == '3' && cub->vida < 5)
			sumar_vida(cub, x, y);
		else if (cub->map.map_matrix[x][y] == '4' && cub->vida > 0)
			restar_vida(cub, x, y);
		cub->raycast.posy += cub->raycast.planey * cub->mov.mov_s;
	}
}
