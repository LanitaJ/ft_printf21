#include <stdio.h>
#include "includes/ft_printf.h"
int main(void)
{
	/****************Integer****************/

	/* printf("%+d.\n", 1234567);
	printf("%-d.\n", 1234567);
	printf("% d.\n", 1234567);
	printf("%0d.\n", 1234567);
	//printf("%#d.\n", 1234567);
	printf("%+012d.\n", 1234567);
	printf("%12.15d.\n", 1234567);
	printf("%d.\n", 1234567);
	printf("%d.\n", 1234567); */

	//ft_printf("%5d", 10);
    /* printf("%d", +0);
    ft_printf("%d", -0);
    printf("%d", -0); */
    /* 
    without equal
    pwl-pd
    plw-pd

    wpl-wpd
    wlp-wd

    lwp-d
    lpw-d

    ***********************
    with minus

    pwl-pd
    plw-pd

    wpl-pdw
    wlp-dw

    lwp-d
    lpw-d
    ***********************
    with equal


    ***********************
    with equal with minus

    
    */
	printf("**********without equal*********\n");
    printf("%10.12d.\n", 1234567);//pwl
    printf("%5.12d.\n", 1234567);//plw

    printf("%10.8d.\n", 1234567);//wpl
    printf("%10.2d.\n", 1234567);//wlp
    
    printf("%5.2d.\n", 1234567);//lwp
    printf("%2.5d.\n", 1234567);//lpw

    printf("**********without equal, with minus*********\n");

    printf("%-10.12d.\n", 1234567);//pwl
    printf("%-5.12d.\n", 1234567);//plw

    printf("%-10.8d.\n", 1234567);//wpl
    printf("%-10.2d.\n", 1234567);//wlp
    
    printf("%-5.2d.\n", 1234567);//lwp
    printf("%-2.5d.\n", 1234567);//lpw

    printf("**********with equal************\n");

    printf("%8.8d.\n", 1234567);//w=p l 
    printf("%7.2d.\n", 1234567);//w=l p
    printf("%7.7d.\n", 1234567);//w=p=l
    printf("%8.7d.\n", 1234567);//w p=l
    printf("%2.7d.\n", 1234567);//p=l w
    printf("%7.8d.\n", 1234567);//p w=l
    printf("%6.6d.\n", 1234567);//l w=p

	printf("**********with equal, with minus************\n");
    
	printf("%8.8d.\n", 1234567);//w=p l 
    printf("%7.2d.\n", 1234567);//w=l p
    printf("%7.7d.\n", 1234567);//w=p=l
    printf("%8.7d.\n", 1234567);//w p=l
    printf("%2.7d.\n", 1234567);//p=l w
    printf("%7.8d.\n", 1234567);//p w=l
    printf("%6.6d.\n", 1234567);//l w=p

	/* TEST!!!!!!!!!!!!

ft_printf("**********without equal*********\n");
    ft_printf("%10.12d.\n", 1234567);//pwl
    ft_printf("%5.12d.\n", 1234567);//plw

    ft_printf("%10.8d.\n", 1234567);//wpl
    ft_printf("%10.2d.\n", 1234567);//wlp
    
    ft_printf("%5.2d.\n", 1234567);//lwp
    ft_printf("%2.5d.\n", 1234567);//lpw

    ft_printf("**********without equal, with minus*********\n");

    ft_printf("%-10.12d.\n", 1234567);//pwl
    ft_printf("%-5.12d.\n", 1234567);//plw

    ft_printf("%-10.8d.\n", 1234567);//wpl
    ft_printf("%-10.2d.\n", 1234567);//wlp
    
    ft_printf("%-5.2d.\n", 1234567);//lwp
    ft_printf("%-2.5d.\n", 1234567);//lpw

    printf("**********with equal************\n");

    ft_printf("%8.8d.\n", 1234567);//w=p l 
    ft_printf("%7.2d.\n", 1234567);//w=l p
    ft_printf("%7.7d.\n", 1234567);//w=p=l
    ft_printf("%8.7d.\n", 1234567);//w p=l
    ft_printf("%2.7d.\n", 1234567);//p=l w
    ft_printf("%7.8d.\n", 1234567);//p w=l
    ft_printf("%6.6d.\n", 1234567);//l w=p

	printf("**********with equal, with minus************\n");
    
	ft_printf("%8.8d.\n", 1234567);//w=p l 
    ft_printf("%7.2d.\n", 1234567);//w=l p
    ft_printf("%7.7d.\n", 1234567);//w=p=l
    ft_printf("%8.7d.\n", 1234567);//w p=l
    ft_printf("%2.7d.\n", 1234567);//p=l w
    ft_printf("%7.8d.\n", 1234567);//p w=l
    ft_printf("%6.6d.\n", 1234567);//l w=p
	 */


	/*****************Строки****************/

	/*ft_printf("%1.25hs\n", 12);
    ft_printf("%1.25hhs\n", 12);
    ft_printf("%1.25ls\n", 12);
    ft_printf("%1.25lls\n", 12);
    ft_printlf("%1.25Ls\n", 12); 
    printf("%+4c", 'c');
    printf("%-4c",33);
    ft_printf("j%4lcaasd%1cx", 'w','a');
    printf("%d", printf("j%4lcaasd%1cx", 'w','a'));*/

	//printf("%+10s\n", "this");
	//printf("%s\n", "");   
	//printf("% 10s\n", "this");    
	//printf("%010s\n", "this");    
	//printf("%d", printf("%023.3s\n", "1asd"));
	//ft_printf("%-12.6s1\n", "this is sparta");
	
	/****************Smile****************/
	/*ft_printf("%1337q");
	ft_printf("%42q");
	ft_printf("%2q", 1);
	ft_printf("%2q", 2);
	ft_printf("%2q", 3); */

	
    return (0);
}