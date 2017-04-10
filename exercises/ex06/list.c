/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
 * 
 * val: value to store in the node.
 * next: pointer to the next node
 *
 * returns: pointer to a new node
 */
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
 * 
 * list: pointer to pointer to Node
 */
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
 * 
 * list: pointer to pointer to Node
 *
 * returns: int or -1 if the list is empty
 */
int pop(Node **list) {
    //Grab the first node
    Node *current = *list;
    
    //Check to see if the list is empty
    if(current==NULL){
        return -1;
    }
    
    //Save the value to be returned
    int v = current->val;
    
    //re-assign the list to be a pointer to the new current
    *list = current->next;
    
    //Return the removed value
    return v;
}


/* Adds a new element to the beginning of the list.
 * 

 * list: pointer to pointer to Node
 * val: value to add
 */
void push(Node **list, int val) {
    Node *current = *list;
    *list = make_node(val, current);
}


/* Removes the first element with the given value
 * 
 * Frees the removed node.
 *
 * list: pointer to pointer to Node
 * val: value to remove
 *
 * returns: number of nodes removed
 */
int remove_by_value(Node **list, int val) {

    //Create counter variable to store number of nodes removed
    int count = 0;
    
    //Create a placeholder node
    Node *current = *list;
    
    //Check if the first node exists
    if(current!=NULL){
        //If so and it's value is the val we are looking for
        if(current->val==val){
            //Pop and increment count
            *list = current->next;
            count = count+1;
        }
    }
    
    //While the following node isn't null
    while(current != NULL && current->next !=NULL){
        //If the following node holds the value we are looking for
       if(current->next->val==val){
           //Skip the next node and increment
           current->next = current->next->next;
           count=count+1;
       }
       //Check the next node
       current = current->next;
    }
    
    return count;
}


/* Reverses the elements of the list.
 *
 * Does not allocate or free nodes.
 * 
 * list: pointer to pointer to Node
 */
void reverse(Node **list) {
    //Grab the first node
    Node *current = *list;
   
    
    //An empty list or list of one item is the same when reversed
    if(current==NULL || current->next==NULL){
        return;
    }
    
    Node *next = current->next;
    Node *prev = NULL;
    
    //Then for every pointer which links two nodes, reverse its order
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *list = prev;
}


int main() {
    
//Regular Tests
    Node *head = make_node(0,NULL);
    Node **list = &head;
    int i;
    for(i=1;i<30;i++){
        push(list,i);
        print_list(list);
    }
    
    remove_by_value(list,0);
    print_list(list);
    
    remove_by_value(list,29);
    print_list(list);
    
    reverse(list);
    print_list(list);

//Null Tests

    Node *head2 = NULL;
    Node **list2 = &head2;
    
    print_list(list2);
    
    pop(list2);
    print_list(list2);
    
    reverse(list2);
    print_list(list2);

    
    // Node *head = make_node(1, NULL);
    // head->next = make_node(2, NULL);
    // head->next->next = make_node(3, NULL);
    // head->next->next->next = make_node(4, NULL);

    // Node **list = &head;
    // print_list(list);

    // int retval = pop(list);
    // print_list(list);
    
    // push(list, retval+10);
    // print_list(list);

    // remove_by_value(list, 3);
    // print_list(list);

    // remove_by_value(list, 7);
    // print_list(list);

    // reverse(list);
    // print_list(list);
}

