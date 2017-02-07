#include <stdio.h>
int main()
{
    int x=5;
    int y= x+1;
    printf(y);
}

/*

Looks like when I add x=5 the assembly code adds:

subq	$16, %rsp
movl	$5, -4(%rbp)
movl	$.LC0, %edi


When I compile with -O2, the code looks a lot more readable and is shorter.

The most meaningful thing I noticed after doing these experiments were that 
when using optimization on the final version of the code, the assembly code was
able to reference the value of y(6) without referencing the value of x (5). 
It think this is because when optimizing it noticed x isn't used except to 
compute y, so it computes y in advance, and disposes of x because it isn't 
relevant anymore.
*/
