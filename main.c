/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:39:50 by jpozuelo          #+#    #+#             */
/*   Updated: 2022/09/01 20:41:11 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	static t_data	data;
	static t_img	img;

	image_mlx_init(&data, &img);
	atributes_init(&data, &img);
	parse(&data, argc, argv);
	render(&data);
	hooks_init(&data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.mlx_win);
	return (0);
}
