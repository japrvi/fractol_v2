/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uils.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:44:36 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/09/07 21:44:38 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_size(double *v_max, double *v_min, double increase)
{
	*v_max += increase;
	*v_min += increase;
}

void	change_factor(double *v_max, double *v_min, double increase)
{
	*v_max = *v_max * increase;
	*v_min = *v_min * increase;
}
