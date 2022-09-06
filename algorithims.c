/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithims.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:45:36 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/08/25 20:08:24 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	set_color(unsigned int it, t_data *data)
{
	unsigned int	aux;

	if (it == data->iterations)
		return (0);
	else
	{
		aux = (it % 225) + 30;
		return ((aux * data->blue) + (aux * data->green * 256)
				+ (data->red * aux * 256 * 256));
	}
}

void	square(double *x, double *y, double vx, double vy)
{
	*x = vx * vx;
	*y = vy * vy;
}

unsigned int	m_j(t_complex z, t_complex c, unsigned int it)
{
	double			x;
	double			y;
	double			power_x;
	double			power_y;
	unsigned int	i;

	i = 0;
	x = z.real;
	y = z.im;
	square(&power_x, &power_y, x, y);
	while (((power_x + power_y) < 4) && (i < it))
	{
		y = 2 * x * y + c.im;
		x = power_x - power_y + c.real;
		square(&power_x, &power_y, x, y);
		i++;
	}
	return (i);
}

unsigned int	burning(t_complex z, t_complex c, unsigned int it)
{
	double			x;
	double			y;
	double			power_x;
	double			power_y;
	unsigned int	i;

	i = 0;
	x = fabs(z.real);
	y = fabs(z.im);
	square(&power_x, &power_y, x, y);
	while (((power_x + power_y) < 4) && (i < it))
	{
		y = fabs(2 * x * y) + c.im;
		x = power_x - power_y + c.real;
		square(&power_x, &power_y, x, y);
		i++;
	}
	return (i);
}
