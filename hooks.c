/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:47:55 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/09/01 20:34:35 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define I 105
#define G 103
#define B 98
#define R 114
#define U 117
#define S_UP 5
#define S_DN 4
#define DOWN 65362
#define UP 65364
#define RIGHT 65363
#define LEFT 65361

int		key_hook(int key_code, t_data *data)
{
	if (!data->rendering)
	{
		if (key_code == I)
			data->iterations *= 2;
		else if (key_code == U)
			data->iterations /= 2;
		else if (key_code == G)
			data->green = (data->green == 0);
		else if (key_code == B)
			data->blue = (data->blue == 0);
		else if (key_code == R)
			data->red = (data->red == 0);
		else if (key_code == RIGHT)
			change_size(&data->x_max, &data->x_min, data->move);
		else if (key_code == LEFT)
			change_size(&data->x_max, &data->x_min, (-1) * data->move);
		else if (key_code == UP)
			change_size(&data->y_max, &data->y_min, data->move);
		else if (key_code == DOWN)
			change_size(&data->y_max, &data->y_min, (-1) * data->move);
		render(data);
	}
	return(printf("%d %d real: %f im: %f move: %f\n", data->iterations, key_code, data->x_max, data->y_max, data->move));
}

int		mouse_hook(int key_code, int x, int y, t_data *data)
{
	if (!data->rendering)
	{
		if (key_code == S_UP)
			zoom_in(x, y, data);
		else if (key_code == S_DN)
			zoom_out(x, y, data);
		render(data);
	}
	return (1);
}

void	hooks_init(t_data *data)
{
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_mouse_hook(data->mlx_win, mouse_hook, data);
}	
