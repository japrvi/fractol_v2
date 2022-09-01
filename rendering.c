/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:09:48 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/09/01 19:24:45 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rutine(t_data *data, t_complex vary)
{
	t_complex		z_o;
	t_complex		constant;

	if (data->type == MANDELBROT || data->type == SHIP)
	{
		z_o.im = 0.0;
		z_o.real = 0.0;
		constant = vary;
	}
	else
	{
		z_o = vary;
		constant = data->constant;
	}
	return (100 * data->rutine(z_o, constant, data->iterations) + 100);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_lenght + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	render(t_data *data)
{
	int				i;
	int				j;
	int				color;
	t_img			*img;

	data->rendering = 1;
	img = data->img;
	i = 0;
	while (i < XWINDOW)
	{
		j = 0;
		while (j < YWINDOW)
		{
			color = rutine(data, get_complex(i, j, data));
			my_pixel_put(img, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, img->img, 0, 0);
	data->rendering = 0;
}
