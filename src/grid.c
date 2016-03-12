/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:36:17 by pdelefos          #+#    #+#             */
/*   Updated: 2016/03/12 18:38:19 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	draw_vertical_lines(t_mlx *mlx, t_map *map, t_img *img)
{
	t_coord ind;
	int		teal;

	teal = 0x008080;
	ind.y = 0;
	while (ind.y < map->lines - 1)
	{
		ind.x = 0;
		while (ind.x < map->columns - 1)
		{
			if (map->print[ind.y][ind.x].x < mlx->width &&
				map->print[ind.y][ind.x + 1].x < mlx->width &&
				map->print[ind.y][ind.x].y < mlx->height &&
				map->print[ind.y][ind.x + 1].y < mlx->height)
			{
				draw_lines(img, map->print[ind.y][ind.x],
						map->print[ind.y][ind.x + 1], teal);
			}
			ind.x++;
		}
		draw_lines(img, map->print[ind.y][map->columns - 1],
				map->print[ind.y + 1][map->columns - 1], teal);
		ind.y++;
	}
}

void	draw_horizontal_lines(t_mlx *mlx, t_map *map, t_img *img)
{
	t_coord ind;
	int		teal;

	teal = 0x008080;
	ind.x = 0;
	while (ind.x < map->columns - 1)
	{
		ind.y = 0;
		while (ind.y < map->lines - 1)
		{
			if (map->print[ind.y][ind.x].x < mlx->width &&
				map->print[ind.y + 1][ind.x].x < mlx->width &&
				map->print[ind.y][ind.x].y < mlx->height &&
				map->print[ind.y + 1][ind.x].y < mlx->height)
			{
				draw_lines(img, map->print[ind.y][ind.x],
						map->print[ind.y + 1][ind.x], teal);
			}
			ind.y++;
		}
		draw_lines(img, map->print[map->lines - 1][ind.x],
				map->print[map->lines - 1][ind.x + 1], teal);
		ind.x++;
	}
}

t_img	draw(t_mlx *mlx, t_map *map)
{
	t_img	img;

	(void)map;
	img.ptr = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	img.size_line = mlx->width;
	img.mlx_width = mlx->width;
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.end);
	draw_vertical_lines(mlx, map, &img);
	draw_horizontal_lines(mlx, map, &img);
	return (img);
}
