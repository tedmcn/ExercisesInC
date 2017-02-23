/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>


#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
    	if (strstr(tracks[i], search_for)) {
    	    printf("Track %i: '%s'\n", i, tracks[i]);
    	}
    }
}

//
//                      EDITED HERE
//
// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(char pattern[])
{
    regex_t re;         //Regex object the expression will compile into
    int t;              //Save the compiled regex into here
    char buffer[512];   //Create a buffer in case of error
    
    //Compile the regex and if there is an error do the following
    if((t=regcomp(&re, pattern, REG_NOSUB))!=0){
        //Write the error to the buffer
        regerror(t, &re, buffer, 512);
        //Print the buffer
        fprintf(stderr,"grep: %s (%s)\n", buffer, pattern);
        //Escape the program
        exit(1);
    }
    
    //Save a variable to count through our senetences
    int i;
    //For each track
    for (i=0; i<NUM_TRACKS; i++) {
        //If the compiled regular expression matches the track
    	if(regexec(&re, tracks[i], 0, NULL, 0)==0){
    	    //Print the track number and the track
    	    printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
    //Close the regex object to conserve memory
    regfree(&re);
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
	*ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    //printf("Search for: ");
    //fgets(search_for, 80, stdin);
    
    strcpy(search_for, "[ha]");
    printf("First Test: %s \n\n", search_for);
    
    rstrip(search_for);
    find_track(search_for);
    find_track_regex(search_for);

    strcpy(search_for, "[W-Z]");
    printf("\nNext Test: %s \n\n", search_for);
   
    
    rstrip(search_for);
    find_track(search_for);
    find_track_regex(search_for);

    strcpy(search_for, ".");
    printf("\nNext Test: %s \n\n", search_for);
   
    rstrip(search_for);
    find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
