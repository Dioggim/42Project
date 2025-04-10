/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:51:50 by dgimenez          #+#    #+#             */
/*   Updated: 2025/04/10 11:51:50 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_in(t_data *data, double mouse_re, double mouse_im, double *range)
{
	data->min_x = mouse_re - (range[0] * 0.5 * 0.5);
	data->max_x = mouse_re + (range[0] * 0.5 * 0.5);
	data->min_y = mouse_im - (range[1] * 0.5 * 0.5);
	data->max_y = mouse_im + (range[1] * 0.5 * 0.5);
}

void	zoom_out(t_data *data, double mouse_re, double mouse_im, double *range)
{
	data->min_x = mouse_re - (range[0] * 0.5 * 2.0);
	data->max_x = mouse_re + (range[0] * 0.5 * 2.0);
	data->min_y = mouse_im - (range[1] * 0.5 * 2.0);
	data->max_y = mouse_im + (range[1] * 0.5 * 2.0);
}

void	key_zoom(t_data *data, double range_x, double range_y, int zoom_in)
{
	if (zoom_in)
	{
		data->min_x += range_x * 0.1;
		data->max_x -= range_x * 0.1;
		data->min_y += range_y * 0.1;
		data->max_y -= range_y * 0.1;
	}
	else
	{
		data->min_x -= range_x * 0.1;
		data->max_x += range_x * 0.1;
		data->min_y -= range_y * 0.1;
		data->max_y += range_y * 0.1;
	}
}
