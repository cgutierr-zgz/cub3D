/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_aux_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:57:20 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/26 18:58:11 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	hud_bonus(t_cub *cub)
{
	if (cub->attack)
	{
		mlx_put_image_to_window(cub->mlx, cub->window,
			cub->txtrs.img[14].img, cub->screen.x / 2, cub->screen.y - 200);
		cub->attack = 0;
	}
	else
		mlx_put_image_to_window(cub->mlx, cub->window,
			cub->txtrs.img[13].img, cub->screen.x / 2, cub->screen.y - 200);
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
		mlx_put_image_to_window(cub->mlx,
			cub->window, cub->txtrs.img[7].img, 10 + (vidas * 20), 50);
	if (cub->num_enemy == 0 && cub->won == 0)
	{
		printf("\nYou killed them all!\nYou can keep on playing\n");
		cub->won = 1;
	}
}
