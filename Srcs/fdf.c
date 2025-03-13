/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:55:43 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/13 19:28:44 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_ejes	*eje;

	fd = 0;
	if (argc != 2 || control_param(argv[1]))
		ft_error("Invalid arguments\n", 1);
	eje = init_ejes(fd, argv[1]);
	ft_events(eje);
}
