#include "../includes/so_long.h"

//__ [ i ] start from the second row if { width = 5 },
//   it will be at char num { 6 } --> the char next to the 
//   [ \n ] or the second line
//
//__ [ i + j ]:
//	---> 6 + 0 = first char in row 2.
//	---> 6 + 1 = second char in row 2.
//
//__ We will not count the [ \n ].
//
//__ After each row check that the row is equal 
//   to the width or the map is not valid.
//
//__ [ i ] will go to the next row after each iteration.	
void	map_height(t_root *root, char *file)
{
	int	i;
	int	j;

	root->game->height = 1;
	i = root->game->width + 1;
	while (file[i])
	{
		j = 0;
		while (file[i + j] != 0 && file[i + j] != '\n')
			j++;
		if (root->game->width != j)
		{
			free (file);
			root_destroy(root, "The map is not valid", 0);
		}
		i += root->game->width + 1;
		root->game->height++;
	}
}
