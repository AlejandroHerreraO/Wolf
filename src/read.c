#include "libw3d.h"

static void	f_map(int fd, char **map)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	while (map[i])
	{
		get_next_line(fd, &line);
		ft_strcpy(map[i], line);
		ft_strdel(&line);
		i++;
	}
}

static void	i_map(int fd, t_map *map)
{
	char	*line;

	get_next_line(fd, &line);
	map->w = ft_atoi(line);
	map->h = ft_atoi(ft_strchr(line, 'x') + 1);
	ft_strdel(&line);
	get_next_line(fd, &line);
	map->p_x = ft_atoi(line);
	map->p_y = ft_atoi(ft_strchr(line, ',') + 1);
	ft_strdel(&line);
}

t_map		*r_map(char *s)
{
	int		fd;
	char	*line;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	line = NULL;
	fd = open(s, O_RDONLY);
	i_map(fd, map);
	map->map = ft_crt_map(map->w, map->h);
	f_map(fd, map->map);
	return (map);
}
