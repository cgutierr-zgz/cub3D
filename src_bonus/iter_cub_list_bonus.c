/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_cub_list_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:35:42 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/25 22:50:37 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	iter_cub_list(t_cub *cub, t_list *lst, void (*f)(t_cub *, void *))
{
	t_list	*ptr;

	if (lst)
	{
		while (lst)
		{
			ptr = lst->next;
			f(cub, lst->content);
			lst = ptr;
		}
	}
}

static void	iter_aux(t_sprite **spr)
{
	if ((*spr)->texture == 8)
		(*spr)->texture = 12;
	else
		(*spr)->texture = 10;
}

void	iter_cub_sprite_list(t_cub *cub, t_list *lst)
{
	t_list		*ptr;
	t_sprite	*spr;

	if (lst)
	{
		spr = lst->content;
		if (cub->search.x == spr->x && cub->search.y == spr->y)
			iter_aux(&spr);
		while (lst)
		{
			ptr = lst->next;
			if (ptr)
				spr = ptr->content;
			if (cub->search.x == spr->x && cub->search.y == spr->y)
			{
				iter_aux(&spr);
				break ;
			}
			lst = ptr;
		}
	}
}
