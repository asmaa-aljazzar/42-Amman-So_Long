#include "../includes/so_long.h"

static void	renderer_init(t_root *root);
static void	texture_init(t_root *root);
static void	texture_load(t_root *root, t_img **img, char *path);

///__ The function allocates memory for t_root ( initialize the struncture );
//   structure and initializes its members to NULL or 0.
//
//__ Initializes the game, renderer, and textures.
//
//__ Return the fully initialized root structure
t_root	*root_init(char *filename)
{
	t_root	*root;

	root = (t_root *)malloc(sizeof(t_root));
	if (!root)
		root_destroy(0, "root_init(): malloc() => ", errno);
	root->mlx_conn = 0;
	root->mlx_win = 0;
	root->mlx_img = 0;
	root->player = 0;
	root->exit = 0;
	root->collect = 0;
	root->wall = 0;
	root->floor = 0;
	root->game = 0;
	game_init(root, filename);
	renderer_init(root);
	texture_init(root);
	return (root);
}

//__ Create mlx connection, window and image.
//
//__ The grid will be 40*40 pixels in grid.
static	void	renderer_init(t_root *root)
{
	int	screen_width;
	int	screen_height;

	root->mlx_conn = mlx_init ();
	if (!root->mlx_conn)
		root_destroy (root, "mlx_init(): Connection failed", 0);
	mlx_get_screen_size(root->mlx_conn, &screen_width, &screen_height);
	if (root->game->width * 40 > screen_width
		|| root->game->height * 40 > screen_height)
	{
		ft_putstr_fd("Map is too big for the screen!\n", 2);
		exit(1);
	}
	root->mlx_win = mlx_new_window (root->mlx_conn,
			root->game->width * 40,
			root->game->height * 40,
			"so_long");
	if (!root->mlx_win)
		root_destroy (root, "mlx_new_window(): Can't create a window", 0);
	root->mlx_img = mlx_new_image (root->mlx_conn,
			root->game->width * 40,
			root->game->height * 40);
	if (!root->mlx_img)
		root_destroy (root, "mlx_new_image(): Can't create an image", 0);
}

//__ This function will load the xpm file into the img
//   the width and height will be known by the 
//   mlx_wpm_file_to_image function: it will extract them 
//   from the original xpm.
//
//__ It will write the value in the width and height variables.
//
//__ In destroy there is 0 instead of root:
// "There's nothing valid here to clean up" the root not fully initialize.
static void	texture_load(t_root *root, t_img **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image (root->mlx_conn, path, &width, &height);
	if (!*img)
		root_destroy (0, "texture_init(): Can't load a texture", 0);
	(*img)->width = width;
	(*img)->height = height;
}

// Send the texture data like the Element to fill and the path.
static void	texture_init(t_root *root)
{
	texture_load (root, &root->player, "./img/player.xpm");
	texture_load (root, &root->exit, "./img/door.xpm");
	texture_load (root, &root->collect, "./img/apple.xpm");
	texture_load (root, &root->wall, "./img/wall.xpm");
	texture_load (root, &root->floor, "./img/floor.xpm");
}
