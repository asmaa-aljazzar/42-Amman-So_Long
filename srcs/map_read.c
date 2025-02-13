#include "../includes/so_long.h"

static void	if_not_malloc(t_root *root, char *file, char *errmsg);
static char	**duplicate_map(char *file, int height, int width);
void		free_copy(char **copy, int height);

void	map_read(t_root *root, char *file)
{
	char	**char_map;
	int		size;

	map_width(root, file);
	map_height(root, file);
	map_isvalid(root, file);
	size = sizeof(t_coord) * root->game->count_coll;
	root->game->coll = (t_coord *)malloc(size);
	if (!root->game->coll)
		if_not_malloc(root, file, "map_read(): coll, malloc():");
	root->game->map = (int **)malloc(sizeof(int *) * root->game->height);
	if (!root->game->map)
		if_not_malloc(root, file, "map_read(): map, malloc():");
	char_map = duplicate_map(file, root->game->height, root->game->width);
	if (!char_map)
		root_destroy(root, "map_read(): Failed to duplicate map", 1);
	get_coord(root, file);
	map_parsing(root, file);
	if (!is_valid_path(root, char_map))
	{
		free_copy(char_map, root->game->height);
		root_destroy(root, "No valid path exists!", 1);
	}
	free_copy(char_map, root->game->height);
}

static void	if_not_malloc(t_root *root, char *file, char *errmsg)
{
	free (file);
	root_destroy (root, errmsg, errno);
}

// 📝 Duplicate the original character map before converting it to 0/1
static char	**duplicate_map(char *file, int height, int width)
{
	int		row;
	int		col;
	char	**copy;

	copy = (char **)malloc(sizeof(char *) * height);
	if (!copy)
		return (NULL);
	row = -1;
	while (++row < height)
	{
		copy[row] = (char *)malloc(sizeof(char) * (width + 1));
		if (!copy[row])
		{
			free_copy(copy, row);
			return (NULL);
		}
		col = 0;
		while (col < width)
		{
			copy[row][col] = file[row * (width + 1) + col];
			col++;
		}
		copy[row][col] = '\0';
	}
	return (copy);
}

// free rows
// free map
void	free_copy(char **copy, int height)
{
	int	i;

	if (!copy)
		return ;
	i = 0;
	while (i < height)
	{
		if (copy[i])
			free(copy[i]);
		i++;
	}
	free(copy);
}

// *******************Old version [ map_read ]*******************************

// void     map_read (t_root *root, char *file);

// //__ Read and process the map file [ array ].
// //
// //__ Allocate a memory for all collictable by 
// //   making it [ coll-size * coll numbers ].
// void	map_read(t_root *root, char *file)
// {
// 	map_width(root, file);
// 	map_height(root, file);
// 	map_isvalid(root, file);
// 	root->game->coll = 
// 	(t_coord *)malloc(sizeof(t_coord) * root->game->count_coll);
// 	if (!root->game->coll)
// 		if_not_malloc(root, file, "map_read(): coll, malloc():");
// 	root->game->map = (int **)malloc(sizeof(int *) * root->game->height);
// 	if (!root->game->map)
// 		if_not_malloc(root, file, "map_read(): map, malloc():");
// 	map_parsing(root, file);
// }
