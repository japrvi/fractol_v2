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

int	render_next_frame(t_data *data)
{
	if (!data->rendering)
		render(data);
	return (1);
}

int		key_hook(int key_code, t_data *data)
{
	if (key_code == 124)
		change_size(&data->x_max, &data->x_min, data->move);
	else if (key_code == 123)
		change_size(&data->x_max, &data->x_min, -1 * data->move);
	else if (key_code == 126)
		change_size(&data->y_max, &data->y_min, -1 * data->move);
	else if (key_code == 125)
		change_size(&data->x_max, &data->x_min, 1 * data->move);
	else if (key_code == 46)
		change_size(NULL, &data->move, data->move);
	else if (key_code == 69)
		key_zoom();
	else if (key_code == 78)
		key_zoom();
	else if (key_code == 32)
		data->iterations -= 10;
	else if (key_code == 34)
		data->iterations += 10;
	else if (key_code == 9 || key_code == 15 || key_code == 5 || key_code == 8)
		colors(key_code, data);
	return (1);
}

int		mouse_hook(int key_code, int x, int y, t_data *data)
{
	if (key_code == 4 && x && y && data)
		mouse_zoom();
	else if (key_code == 5 && x && y && data)
		mouse_zoom();
	return (1);
}

void	hooks_init(t_data *data)
{
	mlx_loop_hook(data->mlx, render_next_frame, data);
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_mouse_hook(data->mlx, mouse_hook, data);
}	
