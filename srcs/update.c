#include "../includes/so_long.h"

static void	print_if_moved(t_root *root, int x, int y);
static void	is_collectable(t_root *root);

//__ If player_[ direction ] != 0 
//   this is mean the player has been moved [ key pressed ].
//   //
//__ Then move the player to that direction.
//
//__ Print the number of moves.
//
//__ If the new place contain a collectable then remove it.
//
//__ Re-draw the image.
//
//__ If the new place contain the exit 
//   then check if all collectable are 
//   collected and then end the game if it is true.
void	update(t_root *root)
{
	int	x;
	int	y;

	x = root->game->player.x;
	y = root->game->player.y;
	if (root->game->player_up != 0)
		move_up (root, x, y);
	else if (root->game->player_down != 0)
		move_down (root, x, y);
	else if (root->game->player_left != 0)
		move_left (root, x, y);
	else if (root->game->player_right != 0)
		move_right (root, x, y);
	print_if_moved (root, x, y);
	is_collectable (root);
	draw (root);
	if (root->game->player.x == root->game->exit.x
		&& root->game->player.y == root->game->exit.y)
		if (root->game->count_coll == root->game->player_coll)
			root_destroy (root, 0, 0);
}

// If the player moved then print the number of move in terminal.
static void	print_if_moved(t_root *root, int x, int y)
{
	if (root->game->player.x != x || root->game->player.y != y)
	{
		root->game->player_move++;
		ft_putnbr_fd (root->game->player_move, 1);
		ft_putendl_fd ("", 1);
	}
}

// Loop until reach count of collectable.
//
//__ When player and collectable is on the same position.
//   delete the collectable,
//   and increase the number of collected elements: 
//	|make it = (-1, -1).
static void	is_collectable(t_root *root)
{
	int	i;

	i = 0;
	while (i < root->game->count_coll)
	{
		if (root->game->coll[i].x == root->game->player.x
			&& root->game->coll[i].y == root->game->player.y)
		{
			root->game->coll[i].x = -1;
			root->game->coll[i].y = -1;
			root->game->player_coll++;
		}
		i++;
	}
}
