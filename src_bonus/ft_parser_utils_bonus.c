/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 00:40:36 by agigi             #+#    #+#             */
/*   Updated: 2021/03/10 00:40:42 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_rgb_range(t_all *all, char *rgb)
{
	int c;

	c = ft_atoi(rgb);
	if (c == -1 || c > 255)
		ft_print_error(all, "Color value out of range [0.255]", 32);
	return (c);
}

int		ft_check_duplicate(t_all *all, char *path)
{
	if (path)
		ft_print_error(all, "Texture parameter is duplicated", 31);
	return (1);
}

char	ft_map_char(t_all *all, size_t xx, size_t yy)
{
	if ((xx < all->map.width && xx >= 0) && (yy < all->map.height && yy >= 0))
	{
		return (all->map.array[yy * all->map.width + xx]);
	}
	return (-1);
}

void	ft_check_screen_size(t_all *all)
{
	int width;
	int height;

	mlx_get_screen_size(&width, &height);
	if (all->conf.res_x < 0 || all->conf.res_x > width)
		all->conf.res_x = width;
	if (all->conf.res_y < 0 || all->conf.res_y > height)
		all->conf.res_y = height;
}
