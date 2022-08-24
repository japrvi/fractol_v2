/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:39:44 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/08/24 20:40:41 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define TEXTO_ERROR "Parameters:\nMandelbrot\nShip\nJulia (int)x int(y)\n"

static int	strcmp(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

void	display_error()
{
	printf(TEXTO_ERROR);
	exit(1);
}

int	ft_atoi(char *str)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] < 0 || str[i] > 9)
			display_error();
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

void	parse(t_data *data, int argc, char **argv)
{
	if (!strcmp("Mandelbrot", argv[1]) || !strcmp("Julia", argv[1]))
		data->rutine = m_j;
	else if (!strcmp("Ship", argv[1]))
		data->rutine = burning;
}
