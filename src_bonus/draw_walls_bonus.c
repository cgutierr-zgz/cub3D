/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:45:28 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/23 09:30:06 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	draw_walls(t_cub *cub, int *draw, int x)
{
	*draw = cub->data.drawstart;
	while (*draw <= cub->data.drawend)
	{
		cub->data.texy
			= (int)cub->data.texpos & (cub->txtrs.height[cub->data.texnum] - 1);
		cub->data.texpos += cub->data.step;
		cub->data.color = my_pixel_get(&cub->txtrs.img[cub->data.texnum],
				cub->data.texx, cub->data.texy);
		if ((cub->data.color & 0x00FFFFFF) == 0)
			cub->data.color = (cub->data.color >> 1) & 8355711;
		my_pixel_put(&cub->txtrs.main_img, x, *draw, cub);
		*draw += 1;
	}
}
