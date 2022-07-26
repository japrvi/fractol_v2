/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:45:56 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/07/26 21:58:04 by jpozuelo         ###   ########.fr       */
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
# define MANDEBROT 1
# define JULIA 2
# define NEWTON 3
# include <math.h>
# include <errno.h>
# include "mlx.h"
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
	t_complex		z_o;
	unsigned char	blue;
	unsigned char	red;
	unsigned char	green;
	unsigned char	transparent;
	int				type;
}	t_data;

//Funciones de renderizado
void	my_pixel_put(t_img *img, int x, int y, int color);
void	render(t_img *img, t_data *data);
int		rutine(t_img *data, int x, int y);

//Funciones para procesar la entrada de datos

//Funciones para asignar el numero complejo

//Funciones que implementa el algoritmo correspondiente
unsigned int	 burning(t_complex z, t_complex c, unsigned int it);
unsigned int	 m_j(t_complex z, t_complex c, unsigned int it);

//Funcion que captura el movimiento de raton

//Funcion que implementa ell zoom

//Funcion que crea el color

//Funcion para moverse con las flechas

//Funcion para aumentar el numero de iteraciones

#endif
