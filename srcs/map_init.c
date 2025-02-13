#include "../includes/so_long.h"

void		map_init(t_root *root, char *file_name);
static void	if_not_file(char *file, t_root *root, int fd, char *errmsg);

//__ Initialize the map by reading it usign gnl.
//
//__use temp pointers.
//
//__ If any fail free and/ or destroy the root.
void	map_init(t_root *root, char *file_name)
{
	char	*line;
	char	*file;
	char	*temp;
	int		fd;

	temp = NULL;
	fd = open (file_name, O_RDONLY);
	if (fd == -1)
		root_destroy (root, file_name, errno);
	file = ft_calloc (1, 1);
	if_not_file (file, root, fd, "map_init(): ft_calloc():");
	line = get_next_line (fd);
	while (line != NULL)
	{
		temp = ft_strjoin (file, line);
		free (file);
		free (line);
		file = temp;
		if_not_file (file, root, fd, "map_init(), ft_strjoin():");
		line = get_next_line (fd);
	}
	close (fd);
	map_read (root, file);
	free (file);
}

static void	if_not_file(char *file, t_root *root, int fd, char *errmsg)
{
	if (!file)
	{
		close (fd);
		root_destroy (root, errmsg, errno);
	}
}
