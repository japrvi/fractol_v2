/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:39:50 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/08/25 19:47:43 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	static t_data	data;
	static t_img	img;

	atributes_init(&data);
	image_mlx_init(&data, &img);
	parse(&data, argc, argv);
	render(&img, &data);
	mlx_loop(data.mlx);
	return (0);
}
