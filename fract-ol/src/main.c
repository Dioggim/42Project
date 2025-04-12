/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:51:50 by dgimenez          #+#    #+#             */
/*   Updated: 2025/04/12 23:10:43 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	print_usage(void)
{
	if (write(1, "Usage: ./fractol [fractal_type]\n", 32) < 0
		|| write(1, "Available fractals:\n", 20) < 0
		|| write(1, "  mandelbrot\n", 13) < 0
		|| write(1, "  julia\n", 8) < 0
		|| write(1, "  ship\n", 7) < 0)
	{
		exit(1);
	}
	exit(1);
}

static void	set_fractal_type(t_data *data, char *type)
{
	if (!strcmp(type, "mandelbrot"))
		data->fractal_type = 1;
	else if (!strcmp(type, "julia"))
		data->fractal_type = 2;
	else if (!strcmp(type, "ship"))
		data->fractal_type = 3;
	else
		print_usage();
}

void	draw_fractal(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			calculate_pixel(data, x, y);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->min_x = -2.0;
	data->max_x = 1.0;
	data->min_y = -1.5;
	data->max_y = 1.5;
	data->max_iter = MAX_ITER;
	data->julia_c = create_complex(-0.4, 0.6);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		print_usage();
	init_data(&data);
	set_fractal_type(&data, argv[1]);
	draw_fractal(&data);
	mlx_hook(data.win, 2, 1L << 0, handle_key, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_mouse_hook(data.win, handle_mouse, &data);
	mlx_loop(data.mlx);
	return (0);
}
