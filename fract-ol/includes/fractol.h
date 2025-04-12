/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:51:50 by dgimenez          #+#    #+#             */
/*   Updated: 2025/04/12 23:34:06 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1200
# define HEIGHT 900
# define MAX_ITER 500

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362
# define KEY_PLUS 61
# define KEY_MINUS 45

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_complex
{
	double	real;
	double	imag;
}		t_complex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	int			max_iter;
	int			fractal_type;
	t_complex	julia_c;

}		t_data;

/* Main functions */
void		init_data(t_data *data);
int			handle_key(int keycode, t_data *data);
int			handle_mouse(int button, int x, int y, t_data *data);
int			close_window(t_data *data);
void		draw_fractal(t_data *data);

/* Fractal functions */
int			mandelbrot_iteration(t_complex c, int max_iter);
int			julia_iteration(t_complex z, t_complex c, int max_iter);
int			burning_ship_iteration(t_complex c, int max_iter);
void		calculate_pixel(t_data *data, int x, int y);

/* Color functions */
int			create_color(int iterations, int max_iter);

/* Movement and zoom functions */
void		zoom_in(t_data *data, double mouse_re,
				double mouse_im, double *range);
void		zoom_out(t_data *data, double mouse_re,
			double mouse_im, double *range);
void		key_zoom(t_data *data, double range_x,
			double range_y, int zoom_in);
void		move_view(t_data *data, double range_x,
				double range_y, int dir);

/* Utility functions */
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_complex	create_complex(double real, double imag);

#endif
