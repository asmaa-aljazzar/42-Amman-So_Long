#include "../includes/so_long.h"

int	key_pressed(int keycode, t_root *root);
int	key_released(int keycode, t_root *root);
int	destroy_hook(int keycode, t_root *root);

// This will work when key is pressed 
// Update the value to 1 and will still update 
// the map until the key is released.
int	key_pressed(int keycode, t_root *root)
{
	if (keycode == 65307)
		root_destroy(root, 0, 0);
	if (keycode == 119)
		root->game->player_up = 1;
	if (keycode == 115)
		root->game->player_down = 1;
	if (keycode == 97)
		root->game->player_left = 1;
	if (keycode == 100)
		root->game->player_right = 1;
	update(root);
	return (0);
}

// This will work when keyis released
// Update the value to 0 and then update the map.
int	key_released(int keycode, t_root *root)
{
	if (keycode == 119)
		root->game->player_up = 0;
	if (keycode == 115)
		root->game->player_down = 0;
	if (keycode == 97)
		root->game->player_left = 0;
	if (keycode == 100)
		root->game->player_right = 0;
	update(root);
	return (0);
}

int	destroy_hook(int keycode, t_root *root)
{
	(void)keycode;
	(void)root;
	root_destroy (0, 0, 0);
	return (0);
}
