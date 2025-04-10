/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:51:50 by dgimenez          #+#    #+#             */
/*   Updated: 2025/04/10 11:51:50 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move_view(t_data *data, double range_x, double range_y, int dir)
{
	if (dir == KEY_LEFT)
	{
		data->min_x -= range_x * 0.1;
		data->max_x -= range_x * 0.1;
	}
	else if (dir == KEY_RIGHT)
	{
		data->min_x += range_x * 0.1;
		data->max_x += range_x * 0.1;
	}
	else if (dir == KEY_UP)
	{
		data->min_y -= range_y * 0.1;
		data->max_y -= range_y * 0.1;
	}
	else if (dir == KEY_DOWN)
	{
		data->min_y += range_y * 0.1;
		data->max_y += range_y * 0.1;
	}
}
