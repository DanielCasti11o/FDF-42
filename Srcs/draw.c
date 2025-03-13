/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:20:38 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/13 19:27:43 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

void	draw(t_ejes *eje)
{
	int		y;
	int		x;

	y = 0;
	eje->pos_y = 0;
	while (y < eje->len_y)
	{
		x = 0;
		eje->pos_x = 0;
		while (x < (eje->len_x[0]))
		{
			slopes(eje, x, y);
			x++;
			eje->pos_x++;
		}
		eje->pos_y++;
		y++;
	}
}

void	slopes(t_ejes *eje, int x, int y)
{
	eje->pos_y1 = eje->pos_y;
	if (x < eje->len_x[0] - 1)
	{
		eje->pos_x1 = eje->pos_x + 1;
		alg_bressenham(eje);
	}
	eje->pos_x1 = eje->pos_x;
	if (y < eje->len_y - 1)
	{
		eje->pos_y1 = eje->pos_y + 1;
		alg_bressenham(eje);
	}
}

void	ft_color(t_ejes *eje)
{
	if (eje->z > 0 || eje->z < 0)
	{
		if (eje->color > 0xFFFF00)
			eje->color -= 0x05;
		if (eje->color < 0xFFFF00)
			eje->color += 0x05;
		if (eje->color == 0xFFFF00)
			return ;
	}
	else
		eje->color = 0xFFFFFF;
}

int	control_pixel_put(t_bress *bress, t_ejes *eje)
{
	if ((bress->dif_x > 0 && (int)(eje->pos_x - eje->pos_x1) > 0) ||
			(bress->dif_x < 0 && (int)(eje->pos_x - eje->pos_x1) < 0) ||
			(bress->dif_y > 0 && (int)(eje->pos_y - eje->pos_y1) > 0) ||
			(bress->dif_y < 0 && (int)(eje->pos_y - eje->pos_y1) < 0))
		return (1);
	else
		return (0);
}

void	alg_bressenham(t_ejes *eje)
{
	t_bress	*bress;
	float	temp;
	float	temp2;

	temp = eje->pos_x;
	temp2 = eje->pos_y;
	ft_isometric(eje);
	bress = init_bress(eje->pos_x, eje->pos_y, eje->pos_x1, eje->pos_y1);
	while ((int)(eje->pos_x - eje->pos_x1) || (int)(eje->pos_y - eje->pos_y1))
	{
		if (1 == control_pixel_put(bress, eje))
			break ;
		ft_color(eje);
		if (eje->pos_x >= 0 || eje->pos_y >= 0 || (eje->pos_x + POS_INIT_X)
			<= EJE_X_W || (eje->pos_y + POS_INIT_Y) <= EJE_Y_W)
			mlx_pixel_put(eje->mlx, eje->win, eje->pos_x,
				eje->pos_y, eje->color);
		eje->pos_x += bress->dif_x;
		eje->pos_y += bress->dif_y;
	}
	free(bress);
	eje->pos_x = temp;
	eje->pos_y = temp2;
}
