/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:45:56 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/08/24 20:40:46 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# ifndef XWINDOW
#  define XWINDOW 800
# endif
# ifndef YWINDOW
#  define YWINDOW 800
# endif
# define MANDELBROT 1
# define JULIA 2
# define SHIP 3
# include <math.h>
# include <errno.h>
# include "./minilibx_opengl_20191021/mlx.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_img;

typedef struct	s_complex
{
	double	real;
	double	im;
}	t_complex;

typedef struct	s_data
{
	void			*mlx;
	void			*mlx_win;
	double			x_max;
	double			y_max;
	double			x_min;
	double			y_min;
	double			factor_x;
	double			factor_y;
	unsigned int	iterations;
	unsigned char	blue;
	unsigned char	red;
	unsigned char	green;
	unsigned char	transparent;
	int				(*rutine) (t_complex, t_complex, unsigned int);
	int				type;
	t_complex		constant;
}	t_data;

//Funciones de renderizado
void			my_pixel_put(t_img *img, int x, int y, int color);
void			render(t_img *img, t_data *data);
int				rutine(t_data *data, t_complex vary);

//Funciones para procesar la entrada de datos
void			display_error();
void			parse(t_data *data, int argc, char **argv);

//Funciones para inicializar los atributos
void			image_mlx_init(t_data *data, t_img *img);
void			atributes_init(t_data *data);
//Funciones para asignar el numero complejo
t_complex		get_complex(int	v_x, int v_y, t_data *data);

//Funciones que implementa el algoritmo correspondiente
unsigned int	 burning(t_complex z, t_complex c, unsigned int it);
unsigned int	 m_j(t_complex z, t_complex c, unsigned int it);

//Funcion que captura el movimiento de raton

//Funcion que implementa ell zoom

//Funcion que crea el color

//Funcion para moverse con las flechas

//Funcion para aumentar el numero de iteraciones

#endif
