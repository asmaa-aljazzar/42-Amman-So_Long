#include "../includes/so_long.h"

void    root_destroy (t_root *root, char *errmsg, int errnum);

//__ This function will check every value in the root
//   and game if anyone is exist it will destroy it and 
//   free the root then will display the error message
void	root_destroy (t_root *root, char *errmsg, int errnum)
{
	if (root != 0)
	{
		if (root->player != 0)
			mlx_destroy_image (root->mlx_conn, root->player);
		if (root->exit != 0)
			mlx_destroy_image (root->mlx_conn, root->exit);
		if (root->collect != 0)
			mlx_destroy_image (root->mlx_conn, root->collect);
		if (root->wall != 0)
			mlx_destroy_image (root->mlx_conn, root->wall);
		if (root->floor != 0)
			mlx_destroy_image (root->mlx_conn, root->floor);
		if (root->mlx_img != 0)
			mlx_destroy_image (root->mlx_conn, root->mlx_img);
		if (root->mlx_win != 0)
			mlx_destroy_window (root->mlx_conn, root->mlx_win);
		if (root->mlx_conn != 0)
			mlx_destroy_display (root->mlx_conn);
		if (root->game != 0)
			game_destroy (root->game);
		free (root);
	}
	die (errmsg, errnum);
}
