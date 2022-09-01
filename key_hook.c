/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:43:57 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/09/01 20:36:04 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_size(double *v_max, double *v_min, double increase)
{
	if (v_max)
		*v_max += increase;
	if (v_min)
		*v_min += increase;
}

void	colors(int key_code, t_data *data)
{
	if (key_code == 9)
		data->blue += 5;
}

void	key_zoom()
{
}
