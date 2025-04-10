/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:51:50 by dgimenez          #+#    #+#             */
/*   Updated: 2025/04/10 11:51:50 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot_iteration(t_complex c, int max_iter)
{
	t_complex	z;
	double		temp;
	int			i;

	z = create_complex(0, 0);
	i = 0;
	while (i < max_iter)
	{
		if ((z.real * z.real + z.imag * z.imag) > 4.0)
			break ;
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = temp;
		i++;
	}
	return (i);
}

int	julia_iteration(t_complex z, t_complex c, int max_iter)
{
	double	temp;
	int		i;

	i = 0;
	while (i < max_iter)
	{
		if ((z.real * z.real + z.imag * z.imag) > 4.0)
			break ;
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = temp;
		i++;
	}
	return (i);
}

int	burning_ship_iteration(t_complex c, int max_iter)
{
	t_complex	z;
	double		temp;
	int			i;

	z = create_complex(0, 0);
	i = 0;
	while (i < max_iter)
	{
		if ((z.real * z.real + z.imag * z.imag) > 4.0)
			break ;
		z.real = fabs(z.real);
		z.imag = fabs(z.imag);
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = temp;
		i++;
	}
	return (i);
}

void	calculate_pixel(t_data *data, int x, int y)
{
	t_complex	c;
	int			iterations;
	double		real_factor;
	double		imag_factor;

	real_factor = (data->max_x - data->min_x) / (WIDTH - 1);
	imag_factor = (data->max_y - data->min_y) / (HEIGHT - 1);
	c.real = data->min_x + (x * real_factor);
	c.imag = data->min_y + (y * imag_factor);
	if (data->fractal_type == 1)
		iterations = mandelbrot_iteration(c, data->max_iter);
	else if (data->fractal_type == 2)
		iterations = julia_iteration(c, data->julia_c, data->max_iter);
	else
		iterations = burning_ship_iteration(c, data->max_iter);
	my_mlx_pixel_put(data, x, y,
		create_color(iterations, data->max_iter));
}
