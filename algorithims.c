/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithims.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:45:36 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/07/14 21:04:53 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	square(double *x, double *y, double vx, double vy)
{
	*x = vx * vx;
	*y = vy * vy;
}

unsigned int	 m_j(t_complex z, t_complex c, unsigned int it)
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
	while (power_x + power_y > 4)
	{
		if (i == it)
			break;
		else
		{
			x = power_x - power_y + c.real;
			y = 2 * x * y + c.im;
			square(&power_x, &power_y, x, y);
			i++;
		}
	}
	return (i);
}
