#include "../includes/so_long.h"

void	map_isvalid (t_root *root, char *file);
static int	isborder (t_root *root, int i);
static void	isvalid_character (t_root *root, char *file, int i);
//__ Check if the map is surrounded by walls ('1').
//
//__ Check if the map contains exactly one player ('P')
//   one exit ('E'), and at least one collectible ('C').
//
//__ Is border here will check if the position of the 
//   the element is for the border or not.
//   	|----> if it is and not 1: map is invalid.
//   	|----> if not then check for 0, C, P, E.
//
//__ Then check the number of each element:
//	| --> C >= 1
//	| --> P = 1
//	| --> E = 1
void	map_isvalid(t_root *root, char *file)
{
	int	i;

	i = -1;
	while (file[++i])
	{
		if (file[i] == '\n')
			continue;
		if (isborder(root, i))
		{
			if (file[i] != '1')
			{
				free (file);
				root_destroy (root, "The map is not surrounded by walls", 0);
			}
		}
		else
		{
			isvalid_character (root, file, i);
		}
	}
	if (root->game->count_player !=1
		|| root->game->count_exit != 1
		|| root->game->count_coll < 1)
	{
		free (file);
		root_destroy (root, "map elements is invalid!", 0);
	}
	
}

// Welcome to the hardest section for me -_-
//
//	 0  1  2  3  4 first row < width [ i < 4]
//	 5  6  7  8  9 
//	10 11 12 13 14 
//
// __ First row 
// 	must be less than the width
// 	| example { width --> 4 } with [ \n ] all that
// 	| less than it is in first row.
//
// __ Last row 
// 	must bigger than [ (width + 1) * (height -1) ]
// 	| First element of the last row = 10 
// 	| If height = 3, width = 4 and [ 5 * 2 = 10 ]
// 	| Then the index is (width + 1) * (height - 1)
//
//__ First column
//	its the first element of each row
//	| the % with the width + 1 must be 0
//	| 0 % 5 = 0 | 5 % 5 = 0 | 10 % 5 = 0
//
//__ Last column
//	its the last element of each row
//	| the % with width + 1 must give exactly 
//	  the index of width - 1
//	| 3 % 5 = 3 | 8 % 5 = 3 | 13 % 5 = 3
//	| 4 , 9, 14 ==> for \n
//
// Return 1 if success and 0 if faild.
static int	isborder(t_root *root, int i)
{
	if (i < root->game->width || i > (root->game->width + 1) * (root->game->height - 1))
		return (1);
	if (i % (root->game->width + 1) == 0 || i % (root->game->width + 1) == (root->game->width - 1))
		return (1);
	return (0);
}

//__ This will check characters in the map 
//   and if the character is valid it will add 1 to its counter.
static void	isvalid_character(t_root *root, char *file, int i)
{
	if (file[i] == 'P')
		root->game->count_player++;
	else if (file[i] == 'E')
		root->game->count_exit++;
	else if (file[i] == 'C')
		root->game->count_coll++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
	{
		free (file);
		root_destroy (root, "Invalid character in the map", 0);
	}
}
