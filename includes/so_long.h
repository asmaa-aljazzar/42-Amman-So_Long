#ifndef SO_LONG_H
# define SO_LONG_H

//*****[ Libraries ]*****
#include "../libft/includes/gnl.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
// 	fnctl.h		-->	for gnl
//	string.h	-->	for strerror
//	errno.h:	-->	for errno
//		ENOMEM: Out of memory
// 		EACCES: Permission denied
//		ENOENT: No such file or directory
//		EINVAL: Invalid argument

// 	Coordinate
typedef struct	s_coord
{
	int	x;
	int	y;
}	t_coord;

// 	Game structure and all movement
typedef struct s_game
{
	int	**map;
	int	width;
	int	height;
	t_coord	player;
	int	player_up;
	int	player_down;
	int	player_left;
	int	player_right;
	int	player_move;
	int	player_coll;
	t_coord	exit;
	t_coord	*coll;
	int	count_exit;
	int	count_coll;
	int	count_player;
	int coll_found;
	int exit_found;
}	t_game;


//*****[ Structure ]*****
// 	all elements
// 	t_img structure is in <mlx_int.h>
typedef	struct s_root
{
	void	*mlx_conn;
	void	*mlx_win;
	t_img	*mlx_img;
	t_img	*player;
	t_img	*exit;
	t_img	*collect;
	t_img	*wall;
	t_img	*floor;
	t_game	*game;
}	t_root;

//*****[ Functions Prototype ]*****
void	die (char *errmsg, int errnum);
t_root	*root_init (char *filename);
void	root_destroy (t_root *root, char *errmsg, int errnum);
void	game_init (t_root *root, char *file_name);
void	game_destroy (t_game *game);
void	map_init(t_root *root, char *file_name);
void	map_read (t_root *root, char *file);
void	map_width(t_root *root, char *file);
void	map_height(t_root *root, char *file);
void	map_isvalid(t_root *root, char *file);
void	map_parsing(t_root *root, char *file);
void	draw (t_root *root);
unsigned int	mlx_get_pixel (t_img *img, int x, int y);
unsigned int	mlx_rgb_to_int (int a, int r, int g, int b);
void	mlx_draw_pixel (t_img *img, int x, int y, int color);
int	key_released(int keycode, t_root *root);
int	key_pressed(int keycode, t_root *root);
int	destroy_hook(int keycode, t_root *root);
void	update (t_root *root);
void	move_up (t_root *root, int x, int y);
void	move_down (t_root *root, int x, int y);
void	move_right (t_root *root, int x, int y);
void	move_left (t_root *root, int x, int y);
void    get_coord (t_root *root, char *file);
int	is_valid_path(t_root *root, char **map);
void	free_copy(char **copy, int height);
#endif
