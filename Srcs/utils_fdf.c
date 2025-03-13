/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:36:02 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/13 19:30:07 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

void	ft_error(char *msg, int n)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(1, &msg[i], 1);
		i++;
	}
	exit(n);
}

void	fr_ints(t_ejes *eje)
{
	int	i;

	i = 0;
	free(eje->len_x);
	while (i < eje->len_y)
	{
		free(eje->matx_z[i]);
		i++;
	}
	free(eje->matx_z);
}

int	control_param(char *argv)
{
	int		i;
	int		j;
	char	*format;

	format = ".fdf";
	i = ft_strlen(argv);
	j = ft_strlen(format);
	while (format[--j])
	{
		i--;
		if (argv[i] != format[j])
			return (1);
	}
	return (0);
}

void	fr_words(char **wds)
{
	int	i;

	i = 0;
	while (wds[i])
	{
		free(wds[i]);
		i++;
	}
	free(wds);
}

int	*atoi_ptr(char *str, int len)
{
	int		i;
	int		*new_ptr;
	char	**wd;

	new_ptr = malloc((len + 1) * sizeof(int));
	if (!new_ptr)
		return (NULL);
	wd = ft_split(str, ' ');
	if (!wd)
		return (free(new_ptr), NULL);
	i = 0;
	while (wd[i] != NULL && i < len)
	{
		new_ptr[i] = ft_atoi(wd[i]);
		i++;
	}
	new_ptr[i] = 0;
	fr_words(wd);
	return (new_ptr);
}
