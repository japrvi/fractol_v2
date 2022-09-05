/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:37:02 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/09/05 20:49:53 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_zoom(int x, int y, double factor, t_data *data)
{
	t_complex			z_max;
	t_complex			z_min;

	z_max = get_complex(x + (XWINDOW / 2), y + (YWINDOW / 2), data);
	z_min = get_complex(x - (XWINDOW / 2), y - (YWINDOW / 2), data);
	printf("El raton esta en la posicion x: %d, y: %d\n", x, y);
	printf("La cuadricula actual tiene como maximos y minimos\n");
	printf("x_max = %f, x_min = %f, y_max = %f, y_min = %f\n", data->x_max, data->x_min, data->y_max, data->y_min);
	printf("z_max.real = %f z_min.real = %f z_max.im = %f z_min.im = %f\n", z_max.real, z_min.real, z_max.im, z_min.im);
	data->x_max = z_max.real;
	data->x_min = z_min.real;
	data->y_max = z_max.im;
	data->y_min = z_min.im;
	printf("La cuadricula actual tiene como maximos y minimos\n");
	printf("x_max = %f, x_min = %f, y_max = %f, y_min = %f\n", data->x_max, data->x_min, data->y_max, data->y_min);
	change_factor(&data->x_max, &data->x_min, factor);
	change_factor(&data->y_max, &data->y_min, factor);
	data->factor_x = set_factor(data->x_max, data->x_min, (double) XWINDOW);
	data->factor_y = set_factor(data->y_max, data->y_min, (double) YWINDOW);
	data->move *= factor;
}

void	zoom(double factor, t_data *data)
{
	printf("%f expected %f\n", data->x_max, data->x_max * factor);
	change_factor(&data->y_max, &data->y_min, factor);
	change_factor(&data->x_max, &data->x_min, factor);
	printf("now %f", data->x_max);
	data->factor_x = set_factor(data->x_max, data->x_min, (double) XWINDOW);
	data->factor_y = set_factor(data->y_max, data->y_min, (double) YWINDOW);
	data->move *= factor;
}
