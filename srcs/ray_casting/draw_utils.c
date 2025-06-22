/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:33:39 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/22 03:25:31 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_texture_color(t_texture *tex, int x, int y);
static void	draw_wall_strip(t_mlx_data *mlx_data, int x,
				struct s_wall_params *params);

void	draw_ceiling(t_mlx_data *mlx_data, int x, int draw_start)
{
	int	y;
	int	ceiling_color;

	ceiling_color = ((mlx_data->map_data->ceiling->red << 16)
			| (mlx_data->map_data->ceiling->green << 8)
			| mlx_data->map_data->ceiling->blue);
	y = 0;
	while (y < draw_start)
	{
		my_mlx_pixel_put(&mlx_data->img, x, y, ceiling_color);
		y++;
	}
}

void	draw_floor(t_mlx_data *mlx_data, int x, int draw_end)
{
	int	y;
	int	floor_color;

	floor_color = ((mlx_data->map_data->floor->red << 16)
			| (mlx_data->map_data->floor->green << 8)
			| mlx_data->map_data->floor->blue);
	y = draw_end;
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(&mlx_data->img, x, y, floor_color);
		y++;
	}
}

void	draw_wall(t_mlx_data *mlx_data, int x, int draw_start, int draw_end)
{
	double					wall_x;
	struct s_wall_params	params;

	if (mlx_data->ray->side == NORTH)
		params.tex = &mlx_data->north_tex;
	else if (mlx_data->ray->side == SOUTH)
		params.tex = &mlx_data->south_tex;
	else if (mlx_data->ray->side == WEST)
		params.tex = &mlx_data->west_tex;
	else
		params.tex = &mlx_data->east_tex;
	if (mlx_data->ray->side == NORTH || mlx_data->ray->side == SOUTH)
		wall_x = mlx_data->ray->pos.x
			+ mlx_data->ray->wall_dist * mlx_data->ray->ray_dir.x;
	else
		wall_x = mlx_data->ray->pos.y
			+ mlx_data->ray->wall_dist * mlx_data->ray->ray_dir.y;
	wall_x -= floor(wall_x);
	params.tex_x = (int)(wall_x * (double)params.tex->width);
	if (mlx_data->ray->side == NORTH || mlx_data->ray->side == EAST)
		params.tex_x = params.tex->width - params.tex_x - 1;
	params.draw_start = draw_start;
	params.draw_end = draw_end;
	draw_wall_strip(mlx_data, x, &params);
}

static void	draw_wall_strip(t_mlx_data *mlx_data, int x,
	struct s_wall_params *params)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;

	step = 1.0 * params->tex->height / (params->draw_end - params->draw_start);
	tex_pos = 0;
	y = params->draw_start;
	while (y < params->draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y >= params->tex->height)
			tex_y = params->tex->height - 1;
		tex_pos += step;
		color = get_texture_color(params->tex, params->tex_x, tex_y);
		my_mlx_pixel_put(&mlx_data->img, x, y, color);
		y++;
	}
}

static int	get_texture_color(t_texture *tex, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	dst = tex->img.addr
		+ (y * tex->img.line_length + x * (tex->img.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
