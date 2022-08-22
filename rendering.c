/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:09:48 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/08/22 18:45:17 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rutine(t_data *data, int x, int y)
{
	return (0);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_lenght + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	render(t_img *img, t_data *data)
{
	int	i;
	int j;
	int	color;

	i = 0;
	while (i < XWINDOW)
	{
		j = 0;
		while (j < YWINDOW)
		{
			color = rutine(data, i, j);
			my_pixel_put(img, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, img->img, 0, 0);
}
