#include "libw3d.h"
#include "colors.h"

static int		get_c(int x, int y, t_mlx *mlx)
{
	if (mlx->m->map[x][y] == '1')
		return (0x262684);
	if (mlx->m->map[x][y] == '2')
		return (0x603d1c);
	return (0x5c6066);
}

static void		draw_inst(t_mlx *mlx)
{
	int		i;
	char	*word;

	i = 0;
	while (i < 190)
	{
		if (i < 145)
			mlx_pixel_put(mlx->mlx, mlx->win, 25, 25 + i, 0x666633);
		mlx_pixel_put(mlx->mlx, mlx->win, 25 + i, 25, 0x666633);
		if (i < 145)
			mlx_pixel_put(mlx->mlx, mlx->win, 215, 25 + i, 0x666633);
		mlx_pixel_put(mlx->mlx, mlx->win, 25 + i, 170, 0x666633);
		i++;
	}
	word = ft_strdup("nothing");
	mlx_string_put(mlx->mlx, mlx->win, 32, 25, 0x215277, "Arrows: move");
	mlx_string_put(mlx->mlx, mlx->win, 32, 55, 0x215277, word);
	mlx_string_put(mlx->mlx, mlx->win, 32, 70, 0x215277, "");
	mlx_string_put(mlx->mlx, mlx->win, 32, 85, 0x215277, "-,+ to zoom");
	mlx_string_put(mlx->mlx, mlx->win, 32, 100, 0x215277, "Space: toggle move");
	mlx_string_put(mlx->mlx, mlx->win, 32, 115, 0x215277, "Q, E: toggle color");
	mlx_string_put(mlx->mlx, mlx->win, 32, 130, 0x215277, "C, V: iterations");
	ft_strdel(&word);
}
/*
void			*draw_thread(void *arg)
{
	int		x;
	int		y;
	t_img	*f;
	t_mlx	*mlx;
	int		id;

	mlx = (t_mlx *)((t_th *)arg)->mlx;
	f = mlx->f;
	y = 0;
	id = ((t_th *)arg)->t_id;
	while (y < WIN_H)
	{
		x = id;
		while (x < WIN_W)
		{
			*(int *)&f->add[(x * f->bpp / 8) + (y * f->line_size)] =
			get_c(x, y, mlx);
			x += THREADS;
		}
		y++;
	}
	return (NULL);
}

void			draw_fract(t_mlx *mlx)
{
	int			i;
	pthread_t	t[THREADS];
	t_th		thread[THREADS];

	i = 0;
	while (i < THREADS)
	{
		thread[i].mlx = mlx;
		thread[i].t_id = i;
		pthread_create(&t[i], NULL, draw_thread, &thread[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(t[i], NULL);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->f->img, 0, 0);
//	draw_inst(mlx);
}
*/
static void	fill_img(t_img *img, int i, int j, t_mlx *mlx)
{
	int		x;
	int		y;
	int		ip;
	int		jp;
	int		color;

	ip = 0;
	x = i * SIDE;
	y = j * SIDE;
	while (ip < SIDE)
	{
		jp = 0;
		while (jp < SIDE)
		{
			if (i == mlx->m->p_x && j == mlx->m->p_y)
				color = 0x3a1408;
			else
				color = get_c(i, j, mlx);
			*(int *)&img->add[((jp + y)* img->bpp / 8) +
			((ip + x) * img->line_size)] = color;
			jp++;
		}
		ip++;
	}
}

void		draw_map(t_mlx *mlx)
{
	int		i;
	int		j;
	t_img	*img;

	i = 0;
	img = mlx->img;
	while (i < mlx->m->h)
	{
		j = 0;
		while (j < mlx->m->w)
		{
			fill_img(img, i, j, mlx);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 500, 500);
	draw_inst(mlx);
}
