/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcular_distancias_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:55:07 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/24 15:01:35 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	calcular_distancia(t_cub *cub, void *content)
{
	t_sprite	*sapato;

	sapato = content;
	if (sapato->texture == 8)
		cub->num_enemy += 1;
	sapato->dist = pow(sapato->x - cub->raycast.posx, 2)
		+ pow(sapato->y - cub->raycast.posy, 2);
}
