/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:45:56 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/09/07 22:04:07 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# ifndef XWINDOW
#  define XWINDOW 600
# endif
# ifndef YWINDOW
#  define YWINDOW 600
# endif
# define MANDELBROT 1
# define JULIA 2
# define SHIP 3
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include "./mlx/mlx.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_img;

typedef struct s_complex
{
	double	real;
	double	im;
}	t_complex;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	double			x_max;
	double			y_max;
	double			x_min;
	double			y_min;
	double			factor_x;
	double			factor_y;
	double			move;
	double			inv_x;
	double			inv_y;
	unsigned int	iterations;
	unsigned char	blue;
	unsigned char	red;
	unsigned char	green;
	unsigned char	transparent;
	unsigned int	(*rutine)(t_complex, t_complex, unsigned int);
	int				type;
	int				rendering;
	t_complex		constant;
	t_img			*img;
}	t_data;

void			my_pixel_put(t_img *img, int x, int y, int color);
void			render(t_data *data);
int				rutine(t_data *data, t_complex vary);
int				render_next_frame(t_data *data);
void			display_error(void);
void			parse(t_data *data, int argc, char **argv);
void			image_mlx_init(t_data *data, t_img *img);
void			atributes_init(t_data *data, t_img *img);
void			hooks_init(t_data *data);
t_complex		get_complex(int v_x, int v_y, t_data *data);
double			set_factor(double v_max, double v_min, double inv_v);
unsigned int	set_color(unsigned int it, t_data *data);
unsigned int	burning(t_complex z, t_complex c, unsigned int it);
unsigned int	m_j(t_complex z, t_complex c, unsigned int it);
void			change_size(double *v_max, double *v_min, double increase);
void			change_factor(double *v_max, double *v_min, double increase);
void			colors(int key_code, t_data *data);
void			zoom_in(int x, int y, t_data *data);
void			zoom_out(int x, int y, t_data *data);
void			zoom(double factor, t_data *data);
#endif
