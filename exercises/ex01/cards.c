#include <stdio.h>
#include <stdlib.h>

//Global variable
char card_name[3];

int main()
{
    int count = 0;
    while (card_name[0]!='x' ) {
        
        askCard();
        
        int val = evalCard(card_name);
        
        count=count+incCount(val);
        
        printf("Current count: %i\n", count);
        }
    return 0;
}


/*
Evaluates the card value the user entered to determine if it should increase
or decrease count.

val: int which holds the card value the user selected

out: value by which count needs to be changed
*/
int incCount(int val){
    
    //If val is between 2 and 7
    if ((val > 2) && (val < 7)) {
        return 1;   //Return 1 to add 1 to count

    //If val is 10
    } else if (val == 10) {
        return -1;  //Return -1 to subtract 1 from count
    
    //Otherwise
    } else{
        return 0;   //Return 0 to do nothing to count
    }
    
}


/*
Evaluates the user input to determin the value of the card.

card: a string which holds the user input.

out: value of the playing card
*/
int evalCard(char* card){
      int val;
      
      //Look at the first value in the array
      switch(card[0]) {
        case 'K':
        case 'Q':
        case 'J':
            return 10;  //If its K,Q, or J return 10
        case 'A':
            return 11;  //If its an Ace, return 11
        case 'X':
            return 0;   //Return 0 for X (escape)
        default:        //For everything else...
            val = atoi(card);   //Convert the string into an int
            if((val <1)||(val>10)){ //If it's not between 1 and 10
                puts("I don't understand that value");
               return 0;    //return 0 since its invalid
            }
        }
}


/*
Asks the user for what card they choose

Accesses global card_name variable.
*/
void askCard(){
    puts("Enter the card_name: ");  //Asks the user for their card
    scanf("%2s", card_name);        //Saves the result
}