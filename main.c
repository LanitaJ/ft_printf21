#include <stdio.h>
#include "includes/ft_printf.h"
int main(void)
{
	char c = 's';
	//printf("%11.15s\n", "hello");
	
	ft_printf("%10s is a string", "this");
	//printf("%d\n", ft_printf("%-31c", 'c'));
	//ft_printf("%.5s", "hiq   ");
    /* ft_printf("%+-3.5hf\n");.
	ft_printf("%+-3.5hhf\n");
    	ft_printf("%+-3.5lf\n");
	ft_printf("%+-3.5llf\n");
	ft_printf("%+-3.5Lf\n"); */
    return (0);
}