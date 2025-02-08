#include "so_long.h"

unsigned int	mlx_get_pixel (t_img *img, int x, int y);
unsigned int	mlx_rgb_to_int (int a, int r, int g, int b);
void	mlx_draw_pixel (t_img *mlx_img, int x, int y, int color);

//__ Return 32-bit integers represent in ARGB format.
//
//__ Go to specific pixel:
// 	| x to go to the right column.
// 	: img->bpp / 8 to know byte per pixel the * x, byte ber col.
// 	| y to go to the right row.
// 	: img->size_line number of byte on one row.
//
//__ The * dereferences the pointer, meaning it fetches the actual value
//   stored at that memory address.
//
//   The function returns this value, which is the color of the pixel.
unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));	
}

// Shifting colors to get the final color value.
unsigned int	mlx_rgb_to_int(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

// Reverse the get_pixel it will set the pixel in mlx_img.
// first go to the spisific pixel 
// casting the target into *(unsigned int *) to set actual color.
void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char	*target;
	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)target = color; 
}
