/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
	printf("%d\n", array[i]);
    }

    return 0;
}

/*

1. Read stack.c, which should be in this directory. What is it intended to do? 
What would the output be if the program worked as expected?

The code is meant to create an array of size 5 initalized all to 42. It then
goes through the array again and sets each value as its index in the array.
It then prints the values of the array.

2. Compile it. Do you get a warning? What does it mean?

Yes there is a warning which is saying that foo is returning the address of
the array local to foo()

3. Run it. What happens? Can you explain it? 
You might find it helpful to draw a stack diagram.

It outputs the following:

0
0
-628932992
32617
-628845264

I think what is happening is that the memory of the array is being deallocated
once the program exits the foo function. Because of this, when the 2nd function
is attempting to do it's job it can only modify the first element of the array
because it no longer sees the memory as an array (since it was deallocated).

4. Comment out the print statements in foo() and bar() and run it again. 
What happens now?

When we do that, we get the following output:

0x7fff1ace5530
0x7fff1ace5530
0
1
2
3
4

which is the output we expect. The first two lines are references to the 
same place in memory and the 5 following are our expected output - which is 
weird because you might expect the program to crash since it will be trying to
access the deallocated space in memory. However, I think the compiler is 
being clever here and giving a static memory location to the array since
we invoked it's value.


*/
