/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:41:14 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/24 14:56:45 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	set_text_bonus(t_cub **cub)
{
	(*cub)->map_d.stecho = "./resources/textures/techo.xpm";
	(*cub)->map_d.ssuelo = "./resources/textures/suelo.xpm";
	(*cub)->map_d.s3_txt = "./resources/textures/health.xpm";
	(*cub)->map_d.s4_txt = "./resources/textures/berd.xpm";
	(*cub)->map_d.s5_txt = "./resources/textures/teleport.xpm";
	(*cub)->map_d.s_inv = "./resources/textures/transparent.xpm";
	(*cub)->map_d.s52_txt = "./resources/textures/teleport02.xpm";
	(*cub)->map_d.sber_dead = "./resources/textures/deadberd.xpm";
	(*cub)->map_d.s_chan = "./resources/textures/chancla01.xpm";
	(*cub)->map_d.s_chan2 = "./resources/textures/chancla02.xpm";
}

void	set_array_bonus(t_cub **cub, char ***textures)
{
	textures[5] = &(*cub)->map_d.stecho;
	textures[6] = &(*cub)->map_d.ssuelo;
	textures[7] = &(*cub)->map_d.s3_txt;
	textures[8] = &(*cub)->map_d.s4_txt;
	textures[9] = &(*cub)->map_d.s5_txt;
	textures[10] = &(*cub)->map_d.s_inv;
	textures[11] = &(*cub)->map_d.s52_txt;
	textures[12] = &(*cub)->map_d.sber_dead;
	textures[13] = &(*cub)->map_d.s_chan;
	textures[14] = &(*cub)->map_d.s_chan2;
}

static void	spr_five(t_cub *cub, t_sprite **sprite, int z)
{
	cub->num_tp += 1;
	cub->map.map_matrix[cub->map.matrix_act][z] = '5';
	(*sprite)->texture = 9;
	if (!cub->start_tp.x && !cub->start_tp.y)
	{
		cub->start_tp.x = cub->map.matrix_act;
		cub->start_tp.y = z;
	}
	else
	{
		cub->end_tp.x = cub->map.matrix_act;
		cub->end_tp.y = z;
	}
}

void	each_sprite(char c, t_cub *cub, t_sprite **sprite, int z)
{
	if (c == '2')
	{
		cub->map.map_matrix[cub->map.matrix_act][z] = '2';
		(*sprite)->texture = 4;
	}
	else if (c == '3')
	{
		cub->map.map_matrix[cub->map.matrix_act][z] = '3';
		(*sprite)->texture = 7;
	}
	else if (c == '4')
	{
		cub->map.map_matrix[cub->map.matrix_act][z] = '4';
		(*sprite)->texture = 8;
	}
	else if (c == '5')
		spr_five(cub, sprite, z);
}
