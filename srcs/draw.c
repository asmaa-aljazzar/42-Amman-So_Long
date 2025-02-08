#include "../includes/so_long.h"

static void	draw_square (t_root *root, t_img *img, int x, int y);
static void	draw_elements (t_root *root, int col, int row);
static void	draw_map (t_root *root);
void	draw	(t_root *root);

// Draw the map and then put the image in window
void    draw(t_root *root)
{
	draw_map (root);
	mlx_put_image_to_window (root->mlx_conn,		
		root->mlx_win,
		root->mlx_img, 
		0, 
		0);
}

//__ Loop over rows [ height ] and Loop over cols [ width ]
//
//__ Then set walls and floor if the position 
//   contain 1 or 0.
//
//__ Finaly by the (x, y) choose what the element to set 
//   in this position: P, C, E.
static void	draw_map(t_root *root)
{
	int	row;
	int	col;

	row = 0;
	while (row < root->game->height)
	{
		col = 0;
		while (col < root->game->width)
		{
			if (root->game->map[row][col] == 1)
				draw_square (root, 
						root->wall, 
						col * 40, 
						row * 40);
			else
				draw_square (root, root->floor, col * 40, row * 40);
			draw_elements (root, col, row);
			col++;
		}
		row++;
	}
}

//__ Every section in the grid will be with [ 40 x 40 ] size.
//
//__ The color (rgb) will extract from the image.
//   from every pixel.
//
//__ If the color of the pixel is not transparent
//   	==> draw it, on the mlx_img.
static void draw_square(t_root *root, t_img *img, int x, int y)
{
	unsigned int	color;
	int	row;
	int	col;

	row = 0;
	while (row < 40)
	{
		col = 0;
		while (col < 40)
		{
			color = mlx_get_pixel (img, col, row);
			if (color != mlx_rgb_to_int (0, 255, 255, 255))
				mlx_draw_pixel (root->mlx_img, x + col, y + row, color);
		col++;
		}
	row++;
	}
}

//__ This will draw element when the [ col ] and [ row ] 
//   = specific element coordinate.
static void	draw_elements (t_root *root, int col, int row)
{
	int	collectable;

	if (root->game->exit.x == col && root->game->exit.y == row)
		draw_square (root, root->exit, col * 40, row * 40);
	collectable = -1;
	while (++collectable < root->game->count_coll)
		if (root->game->coll[collectable].x == col && root->game->coll[collectable].y == row)
			draw_square (root, root->collect, col * 40, row * 40);
	if  (root->game->player.x == col && root->game->player.y == row)
		draw_square (root, root->player, col * 40, row * 40);
}
