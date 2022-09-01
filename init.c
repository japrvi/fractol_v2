/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:16:35 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/09/01 20:40:12 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_mlx_init(t_data *data, t_img *img)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, XWINDOW, YWINDOW, "FRACTOL");
	img->img = mlx_new_image(data->mlx, XWINDOW, YWINDOW);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_lenght, &img->endian);
}

t_complex	get_complex(int x, int y, t_data *data)
{
	t_complex	complex;

	complex.real = data->factor_x * (double) x + data->x_min;
	complex.im = data->factor_y * (double) y + data->y_min;
	return (complex);
}

void	atributes_init(t_data *data, t_img *img)
{
	data->img = img;
	data->x_max = 2.0;
	data->y_max = 2.0;
	data->x_min = -2.0;
	data->y_min = -2.0;
	data->move = 0.1;
	data->iterations = 5000;
	data->factor_x = (data->x_max - data->x_min) / ((double) XWINDOW);
	data->factor_y = (data->y_max - data->y_min) / ((double) YWINDOW);
	data->blue = 155;
	data->red = 155;
	data->green = 155;
	data->rendering = 0;
}
