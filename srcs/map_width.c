#include "../includes/so_long.h"

void	map_width (t_root *root, char *file)
{
	root->game->width = 0;
	while (file[root->game->width] && file[root->game->width] != '\n')
		root->game->width++;
	if (root->game->width == 0 || !file[root->game->width])
	{
		free (file);
		root_destroy (root, "map_width(): map is not valid", 0);

	}
}
