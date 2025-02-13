#include "../includes/so_long.h"

void		get_coord(t_root *root, char *file);
static void	set_coord(t_root *root, char *file, int k, int *obj);
void		free_matrix(t_root *root, char *file, int **map, int row);

void	get_coord(t_root *root, char *file)
{
	int	row;
	int	col;
	int	point;
	int	obj;

	obj = 0;
	point = 0;
	row = -1;
	while (++row < root->game->height)
	{
		root->game->map[row] = (int *)malloc(sizeof(int) * root->game->width);
		if (!root->game->map[row])
			free_matrix(root, file, root->game->map, row);
		col = 0;
		while (col < root->game->width)
		{
			set_coord(root, file, point, &obj);
			col++;
			point++;
		}
		point++;
	}
}

// Check the current character
// Save its [ x, y ] position
//	|👉 k / (width + 1) gives the row (Y-coordinate).
//	|👉 k % (width + 1) gives the column (x-coordinate).
// change the value to 0 make it a normal floor
static void	set_coord(t_root *root, char *file, int k, int *obj)
{
	if (file[k] == 'P')
	{
		root->game->player.x = k % (root->game->width + 1);
		root->game->player.y = k / (root->game->width + 1);
	}
	if (file[k] == 'E')
	{
		root->game->exit.x = k % (root->game->width + 1);
		root->game->exit.y = k / (root->game->width + 1);
	}
	if (file[k] == 'C')
	{
		root->game->coll[*obj].x = k % (root->game->width + 1);
		root->game->coll[*obj].y = k / (root->game->width + 1);
		(*obj)++;
	}
}

// Loop over the 2D array and free each element [ row ]
// then free the matrix,
// set the map = 0,
// free the file,
// destroy the connection.
void	free_matrix(t_root *root, char *file, int **map, int row)
{
	int	i;

	i = 0;
	while (i < row)
		free (map[i++]);
	free (map);
	root->game->map = 0;
	free (file);
	root_destroy (root, "map_parsing: malloc(): ", errno);
}
