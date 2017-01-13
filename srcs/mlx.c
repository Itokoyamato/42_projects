#include "mlx.h"
#include <stdio.h>

int		hook_keydown(int keycode, void *param)
{
	(void)param;
	printf("%d\n", keycode);
	return (0);
}

int		main()
{
	void	*mlx;
	void	*window;
	int		x;
	int		y;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 400, 400, "mlx 42");
	y = 50;
	while (++y < 200)
	{
		x = 50;
		while (++x < 200)
			mlx_pixel_put(mlx, window, x, y, 0x00FFFFFF);
	}
	mlx_key_hook(window, hook_keydown, 0);
	mlx_loop(mlx);
	return (0);
}