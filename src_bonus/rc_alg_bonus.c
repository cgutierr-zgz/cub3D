/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_alg_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:22:31 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/26 19:09:27 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

static void	move_mouse(t_cub *cub, int *x_mouse, int *y_mouse)
{
	mlx_mouse_get_pos(cub->window, x_mouse, y_mouse);
	if (cub->screen.x - *x_mouse > cub->screen.x / 2 + (cub->screen.x / 20))
		rotate_x(cub, -cub->mov.rot_s * 1.25);
	else if (cub->screen.x - *x_mouse < cub->screen.x
		/ 2 - (cub->screen.x / 20))
		rotate_x(cub, cub->mov.rot_s * 1.25);
	if (cub->mov.x_mouse == *x_mouse
		&& cub->mov.y_mouse == *y_mouse && (cub->mov.delay % 7 == 0))
		mlx_mouse_move(cub->window, cub->screen.x / 2, cub->screen.y / 2);
	cub->mov.x_mouse = *x_mouse;
	cub->mov.y_mouse = *y_mouse;
}

static void	keys_init(t_cub *cub)
{
	if (cub->mov.down)
		key_s(cub);
	if (cub->mov.up)
		key_w(cub);
	if (cub->mov.left)
		key_a(cub);
	if (cub->mov.right)
		key_d(cub);
	if (cub->mov.rotate_left)
		key_left(cub);
	if (cub->mov.rotate_right)
		key_right(cub);
	if (cub->mov.attack)
		key_enter(cub);
	if (cub->mov.place)
		key_space(cub);
	if (cub->enter_tp)
		key_e(cub);
	if (cub->mov.delay % 25 == 0)
		cub->dmg = 0;
}

static void	raycast_initializaction(t_cub *cub, int *x_mouse, int *y_mouse)
{
	mlx_mouse_hide();
	cub->data.hit = 0;
	cub->data.mapx = (int)cub->raycast.posx;
	cub->data.mapy = (int)cub->raycast.posy;
	keys_init(cub);
	if (!cub->save_first)
		move_mouse(cub, x_mouse, y_mouse);
	cub->num_enemy = 0;
	iter_cub_list(cub, cub->txtrs.sprite_list, calcular_distancia);
	bubble_sort(cub->txtrs.sprite_list);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, cub->window);
	floorcasting(cub);
}

static void	print_pointer(t_cub *cub)
{
	int	i;

	i = 0;
	i = cub->fd;
	cub->data.color = 321321;
	while (i < 10)
	{
		my_pixel_put(&cub->txtrs.main_img, (cub->screen.x / 2),
			(cub->screen.y / 2), cub);
		my_pixel_put(&cub->txtrs.main_img, (cub->screen.x / 2),
			(cub->screen.y / 2) + i, cub);
		my_pixel_put(&cub->txtrs.main_img, (cub->screen.x / 2),
			(cub->screen.y / 2) - i, cub);
		my_pixel_put(&cub->txtrs.main_img, (cub->screen.x / 2) + i,
			(cub->screen.y / 2), cub);
		my_pixel_put(&cub->txtrs.main_img, (cub->screen.x / 2) - i,
			(cub->screen.y / 2), cub);
		i++;
	}
}

int	raycast(t_cub *cub)
{
	int	x;
	int	x_mouse;
	int	y_mouse;

	x = 0;
	if (cub->mov.delay + 1 == UINT_MAX)
		cub->mov.delay = 0;
	cub->mov.delay++;
	raycast_initializaction(cub, &x_mouse, &y_mouse);
	while (x < cub->screen.x)
	{
		wallcasting(cub, x);
		x++;
	}
	sprites(cub);
	print_pointer(cub);
	mlx_put_image_to_window(cub->mlx, cub->window,
		cub->txtrs.main_img.img, 0, 0);
	vida_hud(cub);
	hud_bonus(cub);
	mlx_string_put(cub->mlx, cub->window, 0, cub->screen.y - 10, 321321,
		"cub3D by cgutierr");
	if (cub->save_first)
		bmp_save(cub);
	return (0);
}
