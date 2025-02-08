#include "../includes/so_long.h"

void     free_matrix(t_root *root,char *file, int **map, int row);
void    map_parsing(t_root *root, char *file);

//__ Converts the raw map file into a structured 2D integer array.
//
//__ It will be just 0 and 1 values.
//   because the position of other elements will save;

void	map_parsing(t_root *root, char *file)
{
	int	row;
	int	col;
	int	point;

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
			if (file[point] == '1')
				root->game->map[row][col] = 1;
			else if (file[point] == '0' || file[point] == 'P' || file[point] == 'E' || file[point] == 'C')
				root->game->map[row][col] = 0;
			else
				root_destroy(root, "Invalid character in map", 1);
			col++;
			point++;
		}
		point++;
	}
}
