/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vida_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:44:20 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/26 18:46:24 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	dda_check(t_cub *cub)
{
	if (cub->map.map_matrix[cub->data.mapx][cub->data.mapy] == '1'
		|| cub->map.map_matrix[cub->data.mapx][cub->data.mapy] == '9')
		cub->data.hit = 1;
}

void	sumar_vida(t_cub *cub, int x, int y)
{
	pthread_t	threads;

	cub->map.map_matrix[x][y] = '0';
	cub->search.x = x;
	cub->search.y = y;
	iter_cub_sprite_list(cub, cub->txtrs.sprite_list);
	cub->vida += 1;
	pthread_create(&threads, 0, (void *)llamar_system, (void *)"say yummy!");
}

void	restar_vida(t_cub *cub, int x, int y)
{
	pthread_t	threads;

	cub->map.map_matrix[x][y] = '0';
	cub->search.x = x;
	cub->search.y = y;
	iter_cub_sprite_list(cub, cub->txtrs.sprite_list);
	cub->dmg = 1;
	pthread_create(&threads, 0, (void *)llamar_system, (void *)"say ouh!");
	cub->vida -= 1;
	if (cub->vida == 0)
	{
		printf(RED "\nYou died!\n" RESET);
		destroy(cub);
	}
}
