/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 13:49:28 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/22 10:29:29 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

int	set_bit(int value, int index)
{
	return (value | index);
}

int	reset_bit(int value, int index)
{
	return (value & ~index);
}

int	is_bit_set(int value, int bitindex)
{
	return ((value & bitindex) == bitindex);
}
