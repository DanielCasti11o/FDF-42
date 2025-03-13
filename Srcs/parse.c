/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:35:54 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/13 19:29:56 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

char	**read_map(int fd, t_ejes *eje, char *argv)
{
	char	**lines;
	int		j;

	j = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (free(eje->len_x), close(fd), NULL);
	lines = malloc((eje->len_y + 1) * sizeof(char *));
	if (!lines)
		return (free(eje->len_x), close(fd), NULL);
	while (j < eje->len_y || get_next_line(fd) != NULL)
	{
		lines[j] = get_next_line(fd);
		if (!lines[j])
			return (fr_words(lines), free(eje->len_x), close(fd), NULL);
		j++;
	}
	lines[j] = NULL;
	close (fd);
	return (lines);
}

int	count_lines(int fd, char *argv, t_ejes *eje)
{
	int		i;
	char	*line;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		free(eje);
		ft_error("Invalid Argument\n", 1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (i);
}

int	*lengs(int i, int fd, char *argv)
{
	int		*len;
	int		j;
	char	*str;

	j = 0;
	len = malloc((i + 1) * sizeof(int));
	if (!len)
		return (NULL);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (free(len), NULL);
	str = get_next_line(fd);
	while (str != NULL && j < i)
	{
		len[j] = ft_strlen(str) - 1;
		j++;
		free(str);
		str = get_next_line(fd);
	}
	len[j] = 0;
	free(str);
	return (close(fd), len);
}

int	*rest_len(int *len, char **lines)
{
	int	i;
	int	*res;

	i = 0;
	res = len;
	while (lines[i])
	{
		res[i] = ft_countsubstr(lines[i], ' ');
		i++;
	}
	return (res);
}

int	**matx_to_arr(int i, t_ejes *eje)
{
	int	**matx_arr;
	int	j;

	j = 0;
	matx_arr = (int **)malloc((i + 1) * sizeof(int *));
	while (j < i)
	{
		matx_arr[j] = atoi_ptr(eje->lines[j], eje->len_x[j]);
		if (!matx_arr[j])
			return (free(eje->len_x), fr_words(eje->lines), NULL);
		printf("\n");
		j++;
	}
	fr_words(eje->lines);
	matx_arr[j] = NULL;
	return (matx_arr);
}
