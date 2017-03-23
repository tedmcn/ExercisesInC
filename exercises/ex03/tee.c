// Ted McNulty
// 3/10/17

//Answer to #3
// I found that I had a hard time getting the correct method of reading from stdin,
// there are a lot of different ways to do it, many of which are deprecated and don't
// give helpful error messages.

// Answer to #4
// My code is rather simple, one of the things that are missing is the ability to 
// pass flags and more control to tee. You also can write the stdin to multiple file
// with the real tee. My code also is going to assume the user is using the 
// tool correctly, so it avoids any error checking.


//This is a command line tool which takes piped input and redirects it
// to both stdout as well as a file that the user specifies
#include <stdio.h>
int main (int argc, char *argv[])
{
    
    //Start by printing a new line to make the output in terminal clean
    printf("\n");
    
    //Create a char variable to hold each char from the stdin
    char str;
    
    //Create the file pointer
    FILE *fp;
    //Open the file from the arguments with appending privledges
    fp=fopen(argv[1],"a");
    
    //Grab the first character
    str = fgetc(stdin);
    
    //Check to make sure the char isn't End OF File special char
    while(str!=EOF){
        //print to stdout
        printf("%c", str);
        //print to file
        fprintf(fp, "%c",str);
        //grab the next character
        str = fgetc(stdin);
    }
    
    //Extra lines for closing
    printf("\n");
    //Close the file
    fclose(fp);
    //Exit the function
    return 0;
}
