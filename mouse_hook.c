/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:37:02 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/09/07 22:43:45 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int x, int y, t_data *data)
{
	t_complex			z_max;
	t_complex			z_min;

	z_max = get_complex(x + (XWINDOW / 4), y + (YWINDOW / 4), data);
	z_min = get_complex(x - (XWINDOW / 4), y - (YWINDOW / 4), data);
	data->x_max = z_max.real;
	data->x_min = z_min.real;
	data->y_max = z_max.im;
	data->y_min = z_min.im;
	data->factor_x = set_factor(z_max.real, z_min.real, data->inv_x);
	data->factor_y = set_factor(z_max.im, z_min.im, data->inv_y);
	data->move = 10 * set_factor(z_max.real, z_min.real, data->inv_x);
}

void	zoom_out(int x, int y, t_data *data)
{
	t_complex			z_max;
	t_complex			z_min;

	z_max = get_complex(x + (XWINDOW * 2), y + (YWINDOW * 2), data);
	z_min = get_complex(x - (XWINDOW * 2), y - (YWINDOW * 2), data);
	data->x_max = z_max.real;
	data->x_min = z_min.real;
	data->y_max = z_max.im;
	data->y_min = z_min.im;
	data->factor_x = set_factor(z_max.real, z_min.real, data->inv_x);
	data->factor_y = set_factor(z_max.im, z_min.im, data->inv_y);
	data->move = 10 * set_factor(z_max.real, z_min.real, data->inv_x);
}
