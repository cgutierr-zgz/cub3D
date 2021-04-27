/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_floorcasting_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:47:16 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/26 19:14:08 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

static void	setup(t_cub *cub, int y)
{
	cub->data.raydirx0 = cub->raycast.dirx - cub->raycast.planex;
	cub->data.raydiry0 = cub->raycast.diry - cub->raycast.planey;
	cub->data.raydirx1 = cub->raycast.dirx + cub->raycast.planex;
	cub->data.raydiry1 = cub->raycast.diry + cub->raycast.planey;
	cub->data.p = y - cub->screen.y / 2;
	cub->data.posz = 0.5 * cub->screen.y;
	cub->data.rowdistance = cub->data.posz / cub->data.p;
	cub->data.floorstepx = cub->data.rowdistance
		* (cub->data.raydirx1 - cub->data.raydirx0) / cub->screen.x;
	cub->data.floorstepy = cub->data.rowdistance
		* (cub->data.raydiry1 - cub->data.raydiry0) / cub->screen.x;
	cub->data.floorx
		= cub->raycast.posx + cub->data.rowdistance * cub->data.raydirx0;
	cub->data.floory
		= cub->raycast.posy + cub->data.rowdistance * cub->data.raydiry0;
}

static void	set_color(t_cub *cub)
{
	cub->data.cellx = (int)(cub->data.floorx);
	cub->data.celly = (int)(cub->data.floory);
	cub->data.tx = (int)(cub->txtrs.width[0] * (cub->data.floorx
				- cub->data.cellx)) & (cub->txtrs.width[0] - 1);
	cub->data.ty = (int)(cub->txtrs.height[0] * (cub->data.floory
				- cub->data.celly)) & (cub->txtrs.height[0] - 1);
	cub->data.floorx += cub->data.floorstepx;
	cub->data.floory += cub->data.floorstepy;
	cub->data.color = my_pixel_get(&cub->txtrs.img[6],
			cub->data.tx, cub->data.ty);
	cub->data.color = (cub->data.color >> 1) & 8355711;
}

void	floorcasting(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	while (y < cub->screen.y)
	{
		setup(cub, y);
		x = 0;
		while (x < cub->screen.x)
		{
			set_color(cub);
			my_pixel_put(&cub->txtrs.main_img, x, y, cub);
			cub->data.color = my_pixel_get(&cub->txtrs.img[5],
					cub->data.tx, cub->data.ty);
			cub->data.color = (cub->data.color >> 1) & 8355711;
			my_pixel_put(&cub->txtrs.main_img, x, cub->screen.y - y - 1, cub);
			x++;
		}
		y++;
	}
}
