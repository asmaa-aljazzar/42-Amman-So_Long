#include "../includes/so_long.h"
static void	flood_fill(char **map, int x, int y, t_root *root, int *collectibles_found, int *exit_found);

int	is_valid_path(t_root *root, char **map)
{
	// Step 1: Use the existing duplicated map
    int collectibles_found = 0;
    int exit_found = 0;
	// Step 2: Start flood-fill from the player's position
	flood_fill(map, root->game->player.x, root->game->player.y, root, &collectibles_found, &exit_found);
	// Step 3: Check if all collectibles & exit were reached
    return (collectibles_found == root->game->count_coll && exit_found);

}

static void	flood_fill(char **map, int x, int y, t_root *root, int *collectibles_found, int *exit_found)
{
	// Bounds check
	if (x < 0 || y < 0 || x >= root->game->width || y >= root->game->height)
	    return;
	// Stop if it's a wall ('1') or already visited ('V')
	if (map[y][x] == '1' || map[y][x] == 'V')
	    return;
     // Check for collectibles
    if (map[y][x] == 'C')
        (*collectibles_found)++;

    // Check for exit
    if (map[y][x] == 'E')
        (*exit_found) = 1;
	
    // Mark as visited
	map[y][x] = 'V';

	// Recursive calls in four directions
	flood_fill(map, x + 1, y, root, collectibles_found, exit_found); // Right
	flood_fill(map, x - 1, y, root, collectibles_found, exit_found); // Left
	flood_fill(map, x, y + 1, root, collectibles_found, exit_found); // Down
	flood_fill(map, x, y - 1, root, collectibles_found, exit_found); // Up
}