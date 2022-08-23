/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:39:50 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/08/23 21:30:21 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	static t_data	data;
	static t_img	img;

	parse(&data, argc, argv);
	atributes_init(&data);
	image_mlx_init(&data, &img);
	return (0);
}
