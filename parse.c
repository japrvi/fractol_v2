/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:39:44 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/08/25 19:48:03 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define TEXTO_ERROR "Parameters:\nMandelbrot.\nShip.\nJulia -> (int)x int(y)\n"

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

void	display_error(void)
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
		if (str[i] < '0' || str[i] > '9')
			display_error();
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

void	parse(t_data *data, int argc, char **argv)
{
	if (argc == 2 || argc == 4)
	{
		if (!strcmp(argv[1], "Mandelbrot") && argc == 2)
		{
			data->type = MANDELBROT;
			data->rutine = m_j;
		}
		else if (!strcmp(argv[1], "Julia") && argc == 4)
		{
			data->type = JULIA;
			data->rutine = m_j;
			data->constant = get_complex(ft_atoi(argv[2]), ft_atoi(argv[3]), data);
		}
		else if (!strcmp(argv[1], "Ship") && argc == 2)
		{
			data->type = SHIP;
			data->rutine = burning;
		}
		else
			display_error();
	}
	else
		display_error();
}
