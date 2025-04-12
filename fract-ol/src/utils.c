/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:51:50 by dgimenez          #+#    #+#             */
/*   Updated: 2025/04/12 23:12:58 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	set_color_scheme(double t, int *rgb)
{
	// Cores mais simples e bem visíveis
	rgb[0] = (int)(255 * sin(t * 3.14159));
	rgb[1] = (int)(255 * cos(t * 3.14159));
	rgb[2] = (int)(255 * (1.0 - t));
}

int	create_color(int iterations, int max_iter)
{
	double	t;
	int		rgb[3];
	int		i;

	if (iterations == max_iter)
		return (0x000000);
	t = (double)iterations / max_iter;
	set_color_scheme(t, rgb);
	i = -1;
	while (++i < 3)
	{
		if (rgb[i] < 0)
			rgb[i] = 0;
		else if (rgb[i] > 255)
			rgb[i] = 255;
	}
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}
