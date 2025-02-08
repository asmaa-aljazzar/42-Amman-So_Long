#include "../includes/so_long.h"

// Function prototype:
void	die(char *errmsg, int errnum);

// Function to print a Custom error message
// 	1. If error message or error num exist 	  --> Error.
// 	2. If error message exist 		  --> print it. 
// 	3. If error message and error num exist   --> :.
// 	4. If error num exist 			  --> print the 
// 	   error message that describe the error number.
// 	5. If error message or error number exist --> \n and exit.

void	die(char *errmsg, int errnum)
{
	if (errmsg != 0 || errnum != 0)
		ft_putendl_fd("Error", 2);
	if (errmsg != 0)
		ft_putstr_fd(errmsg, 2);
	if (errmsg != 0 && errnum != 0)
		ft_putstr_fd(": ", 2);
	if (errnum != 0)
		ft_putstr_fd(strerror(errnum), 2);
	if (errmsg != 0 || errnum != 0)
	{
		ft_putendl_fd("", 2);
		exit (1);
	}
	exit (0);
}
// exit 0 ---> Success.
// exit 1 ---> faluar/ error.
