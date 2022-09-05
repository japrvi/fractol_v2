/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:37:02 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/09/01 20:38:03 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_zoom(int x, int y, double factor, t_data *data)
{
	t_complex			z;

	z = get_complex(x, y, data);
	change_size(&data->x_max, &data->x_min, z.real);
	change_size(&data->y_max, &data->y_min, z.im);
	//change_factor(&data->factor_x, &data->factor_y, factor);
	//change_factor(&data->x_max, &data->x_min, factor);
	//change_factor(&data->y_max, &data->y_min, factor);
	//data->move *= factor;
	printf("x: %f y: %f %f\n", data->x_max, data->y_max, factor);
}
