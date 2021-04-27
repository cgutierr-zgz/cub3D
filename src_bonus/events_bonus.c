/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:34:25 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/25 15:06:09 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	my_pixel_put(t_img *data, int x, int y, t_cub *cub)
{
	char	*dst;
	int		rojo;

	rojo = get_r(cub->data.color) + 50;
	if (rojo > 255)
		rojo = 255;
	if (cub->dmg)
		cub->data.color = create_trgb(get_t(cub->data.color), rojo,
				get_g(cub->data.color) / 2, get_b(cub->data.color) / 2);
	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = cub->data.color;
}

int	my_pixel_get(t_img *data, int x, int y)
{
	return (*(unsigned int *)(data->addr + (y
			* data->line_l + x * (data->bpp / 8))));
}

/*
** Cierra el programa, tonto
**	system("leaks cub3D");
*/

int	destroy(t_cub *cub)
{
	free_content_cub(cub);
	free_content_map_matrix(cub);
	ft_lstclear(&cub->txtrs.sprite_list, clear_matrix_content);
	free(cub->data.zbuffer);
	printf(GREEN "\nHave a nice day!\n" RESET);
	exit(0);
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == K_W)
		cub->mov.up = 0;
	if (keycode == K_A)
		cub->mov.left = 0;
	if (keycode == K_S)
		cub->mov.down = 0;
	if (keycode == K_D)
		cub->mov.right = 0;
	if (keycode == K_LEFT)
		cub->mov.rotate_left = 0;
	if (keycode == K_RIGHT)
		cub->mov.rotate_right = 0;
	if (keycode == L_SHIFT && (cub->mov.mov_s > 0.05))
		cub->mov.mov_s /= 2;
	if (keycode == ENTER)
		cub->mov.attack = 0;
	if (keycode == SPACE)
		cub->mov.place = 0;
	if (keycode == K_E)
		cub->enter_tp = 0;
	return (keycode);
}

int	keys(int keycode, t_cub *cub)
{
	if (keycode == K_ESC)
		destroy(cub);
	if (keycode == K_W)
		cub->mov.up = 1;
	if (keycode == K_A)
		cub->mov.left = 1;
	if (keycode == K_S)
		cub->mov.down = 1;
	if (keycode == K_D)
		cub->mov.right = 1;
	if (keycode == K_LEFT)
		cub->mov.rotate_left = 1;
	if (keycode == K_RIGHT)
		cub->mov.rotate_right = 1;
	if (keycode == L_SHIFT)
		cub->mov.mov_s *= 2;
	if (keycode == ENTER && cub->mov.attack == 0)
		cub->mov.attack = 1;
	if (keycode == SPACE && cub->mov.place == 0)
		cub->mov.place = 1;
	if (keycode == K_E && cub->enter_tp == 0)
		cub->enter_tp = 1;
	return (keycode);
}
