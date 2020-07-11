#include <stdio.h>
#include "includes/ft_printf.h"
int main(void)
{
	char c = 's';
	
	ft_printf("%1.25hs\n", 12);
	ft_printf("%1.25hhs\n", 12);
	ft_printf("%1.25ls\n", 12);
	ft_printf("%1.25lls\n", 12);
	ft_printf("%1.25Ls\n", 12);

	//ft_printf("%10s is a string\n", "this");
	//ft_printf("%10s is a string\n", "this");	
	//printf("%d\n", ft_printf("%-31c", 'c'));
	//ft_printf("%.5s", "hiq   ");
	//printf("%.5s", "hiq   ");
    /* ft_printf("%+-3.5hf\n");.
	ft_printf("%+-3.5hhf\n");
    	ft_printf("%+-3.5lf\n");
	ft_printf("%+-3.5llf\n");
	ft_printf("%+-3.5Lf\n"); */
    return (0);
}