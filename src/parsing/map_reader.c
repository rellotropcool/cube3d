/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:16:47 by aule-bre          #+#    #+#             */
/*   Updated: 2025/04/15 15:49:36 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*gnl_no_newline(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (ft_strncmp(line, "\n", 2) == 0)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_map(int fd)
{
	char	*line;
	char	*map_content;
	char	*new_map_content;

	line = gnl_no_newline(fd);
	if (!line)
		return (close(fd), printf(EMPTY_MAP_FILE), NULL);
	map_content = NULL;
	while (line)
	{
		new_map_content = ft_strjoin(map_content, line);
		free(map_content);
		if (!new_map_content)
			return (close(fd), printf(ERROR_MALLOC), NULL);
		map_content = new_map_content;
		free(line);
		line = gnl_no_newline(fd);
	}
	close(fd);
	return (map_content);
}

char	*open_map(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (printf(ERROR_OPEN), NULL);
	return (get_map(fd));
}

bool	check_map_format(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (len > 4)
		if (ft_strncmp(&map_file[len - 4], ".cub", 5) == 0)
			return (true);
	return (false);
}
