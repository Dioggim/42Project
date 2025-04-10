/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:51:50 by dgimenez          #+#    #+#             */
/*   Updated: 2025/04/10 11:51:50 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	set_color_scheme(double t, int *rgb)
{
	double	intensity;
	double	rainbow;

	intensity = 1.0 - (0.7 * t);
	rainbow = 6.28318530718 * t;
	rgb[0] = intensity * (int)(127 * sin(rainbow) + 128);
	rgb[1] = intensity * (int)(127 * sin(rainbow + 2.0944) + 128);
	rgb[2] = intensity * (int)(127 * sin(rainbow + 4.18879) + 128);
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
