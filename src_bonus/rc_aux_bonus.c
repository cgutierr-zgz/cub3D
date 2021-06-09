/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_aux_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:57:20 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/09 14:51:49 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

static void	draw_n_pixels(int n_pixels, t_cub *cub, int i, int i2)
{
	int	x;
	int	x2;

	x = 0;
	while (x < n_pixels)
	{
		x2 = 0;
		while (x2 < n_pixels)
		{
			if ((i + x) < cub->screen.x && (i2 + x2 + 125) < cub->screen.y
				&& cub->show_minimap)
				my_pixel_put(&cub->txtrs.main_img, i + x, i2 + x2 + 125, cub);
			x2++;
		}
		x++;
	}
}

//FIXME: qu eno sea más grande que la pantalla
typedef struct s_minimap
{
	int	i;
	int	i2;
	int	offsetx;
	int	offsety;
}	t_minimap;

/*
** ' ' -> Espacio vacío
** '0' -> Suelo/Techo
** '1' -> Muros
** '2' -> Sprites
** '3' -> Objetos que curan
** '4' -> Objetos que hieren
** '5' -> Teleport
** '9' -> Puertas secretas
*/

static void	set_color(t_cub *cub, int i, int i2)
{
	cub->data.color = 321123321;
	if (cub->map.map_matrix[i][i2] == '1')
		cub->data.color = 23132;
	else if (cub->map.map_matrix[i][i2] == '0')
		cub->data.color = 45324321;
	else if (cub->map.map_matrix[i][i2] == '3')
		cub->data.color = create_trgb(0, 0, 255, 0);
	else if (cub->map.map_matrix[i][i2] == '4')
		cub->data.color = create_trgb(0, 255, 0, 0);
	else if (cub->map.map_matrix[i][i2] == '5')
		cub->data.color = create_trgb(0, 182, 73, 245);
	if ((int)cub->raycast.posx == i && (int)cub->raycast.posy == i2)
		cub->data.color = create_trgb(0, 0, 0, 0);
}

// SI SE QUIERE 1 PIXEL DE DISTANCIA ENTRE CADA ITEM
//  draw_n_pixels(4, cub, m.i2 + m.offsetx, m.i + m.offsety);

static void	minimap(t_cub *cub)
{
	t_minimap	m;

	m.offsety = 0;
	m.i = 0;
	while (m.i < cub->map.map_lines)
	{
		m.i2 = 0;
		m.offsetx = 0;
		while (m.i2 < cub->map.max_len)
		{
			set_color(cub, m.i, m.i2);
			if (cub->map.map_matrix[m.i][m.i2] != ' ')
				draw_n_pixels(5, cub, m.offsetx, m.offsety);
			m.i2++;
			m.offsetx += 5;
		}
		m.offsety += 5;
		m.i++;
	}
}

void	hud_bonus(t_cub *cub)
{
	if (cub->attack)
	{
		mlx_put_image_to_window(cub->mlx, cub->window, cub->txtrs.img[14].img,
			cub->screen.x / 2, cub->screen.y - 200);
		cub->attack = 0;
	}
	else
		mlx_put_image_to_window(cub->mlx, cub->window, cub->txtrs.img[13].img,
			cub->screen.x / 2, cub->screen.y - 200);
	minimap(cub);
}

void	vida_hud(t_cub *cub)
{
	char	*num;
	char	*vida;
	char	*num_enemy;
	char	*num_enemyj;
	int		vidas;

	num = ft_itoa(cub->vida);
	vida = ft_strjoin("HP: ", num);
	free(num);
	num_enemy = ft_itoa(cub->num_enemy);
	num_enemyj = ft_strjoin("Enemies: ", num_enemy);
	free(num_enemy);
	mlx_string_put(cub->mlx, cub->window, 0, 25, 321321, vida);
	mlx_string_put(cub->mlx, cub->window, 0, 50, 321321, num_enemyj);
	free(vida);
	free(num_enemyj);
	vidas = -1;
	while (++vidas < cub->vida)
		mlx_put_image_to_window(cub->mlx, cub->window, cub->txtrs.img[7].img, 10
			+ (vidas * 20), 50);
	if (cub->num_enemy == 0 && cub->won == 0)
	{
		printf("\nYou killed them all!\nYou can keep on playing\n");
		cub->won = 1;
	}
}
