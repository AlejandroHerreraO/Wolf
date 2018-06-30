#include "libw3d.h"

static t_img		*create_img(t_mlx *mlx)
{
	t_img	*f;

	f = (t_img *)malloc(sizeof(t_img));
	f->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	f->bpp = 0;
	f->line_size = 0;
	f->endian = 0;
	f->add = mlx_get_data_addr(f->img, &f->bpp, &f->line_size, &f->endian);
	return (f);
}

static t_view		*new_view(void)
{

}

void				dst_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	exit(0);
}

void				reset_mlx(t_mlx *mlx)
{
	mlx->scale = 1;
	mlx->off_x = 0;
	mlx->off_y = 0;
	mlx->mou_x = 0;
	mlx->mou_y = 0;
	mlx->mode = 0;
	mlx->mode_c = 0;
}

t_mlx				*create_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "FdF");
	mlx->scale = 1;
	mlx->off_x = 0;
	mlx->off_y = 0;
	mlx->mou_x = 0;
	mlx->mou_y = 0;
	mlx->mode = 0;
	mlx->mode_c = 0;
	mlx->m = r_map("rsc/map0");
	mlx->v = new_view();
	mlx->img = create_img(mlx);
	return (mlx);
}
