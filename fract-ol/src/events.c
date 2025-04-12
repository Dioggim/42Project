/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:51:50 by dgimenez          #+#    #+#             */
/*   Updated: 2025/04/12 23:13:27 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_mouse(int button, int x, int y, t_data *data)
{
	double	range[2];
	double	mouse_re;
	double	mouse_im;

	range[0] = data->max_x - data->min_x;
	range[1] = data->max_y - data->min_y;
	mouse_re = data->min_x + ((double)x / WIDTH) * range[0];
	mouse_im = data->min_y + ((double)y / HEIGHT) * range[1];
	if (button == SCROLL_UP)
		zoom_in(data, mouse_re, mouse_im, range);
	else if (button == SCROLL_DOWN)
		zoom_out(data, mouse_re, mouse_im, range);
	draw_fractal(data);
	return (0);
}

int	handle_key(int keycode, t_data *data)
{
	double	range_x;
	double	range_y;

	range_x = data->max_x - data->min_x;
	range_y = data->max_y - data->min_y;
	if (keycode == KEY_ESC)
		close_window(data);
	else if (keycode >= KEY_LEFT && keycode <= KEY_DOWN)
		move_view(data, range_x, range_y, keycode);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		key_zoom(data, range_x, range_y, keycode == KEY_PLUS);
	draw_fractal(data);
	return (0);
}

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
