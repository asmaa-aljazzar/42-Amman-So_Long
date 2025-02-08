#include "../includes/so_long.h"

int     is_dot_ber_file(char *file);

//__ [ File + len - 4 ]----> go with pointer 
//    to the last 4 characters to compair
//__ The len should be at least 5 [a.ber]
//__ strcmp return 0 if equal
int	is_dot_ber_file(char *file)
{
	int len;
	if (!file)
		return (0);
	len = ft_strlen(file);
	if (len < 5)
		return (0);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	main (int argc, char **argv)
{
	t_root	*root;

	if (argc != 2)
		die ("Number of argument must be 2", 0);
	if (is_dot_ber_file(argv[1]) == 0)
		die ("Invalid Format: [ <example>.ber ]", 0);
	root = root_init(argv[1]);
	draw(root);

	mlx_hook (root->mlx_win, 2, 1L << 0, key_pressed, root);
	mlx_hook (root->mlx_win, 3, 1L << 1, key_released, root);
	mlx_hook (root->mlx_win, 17, 1L << 0, destroy_hook, root);
	mlx_loop(root->mlx_conn);
	return (0);
}
