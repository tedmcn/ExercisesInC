//Ted McNulty
//EX08
//4/10/17

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>

//Used for sorting arrays of strings
gint my_comparator(gconstpointer item1, gconstpointer item2) {
 return atoi(item1)- atoi(item2);
}
int main(int argc, char** argv) {
    
    //Create hash table to store values
    GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);    

    //Read the file from input
    char const* const fileName = argv[1]; 
    FILE* file = fopen(fileName, "r");
    char line[256];
    
    //Get each line
    while (fgets(line, sizeof(line), file)) {
        
        //Divide each line by special characters
        char * pch;
        pch = strtok(line," !@#$^&*()-_=+|\\[]{}':;/?.>,<`~\"\n");
        //For each word in the file
        while(pch!=NULL){
            
            //If this is a new word
            if(g_hash_table_lookup(hash, pch)==NULL){
                //Allocate space for the key and value
                GString *k= g_string_new(pch);
                GString *v= g_string_new("1");
                //Create a new entry
                g_hash_table_insert(hash, k->str,v->str);

            }
            //Otherwise
            else{
                // get the value
                char * count = g_hash_table_lookup(hash, pch);
                int i = atoi(count);
                i=i+1;
                //Add 1 and convert back into string
                char buffer[10];
                sprintf(buffer, "%d", i);
                //Allocate space for the key and values
                GString *k= g_string_new(pch);
                GString *v= g_string_new(buffer);
                //Replace old entry
                g_hash_table_insert(hash, k->str, v->str);
            }
            //Printing and calling lookup works fine here
            // printf("%s | ",pch);
            // printf("%s",(char *)g_hash_table_lookup(hash, pch));
            // printf("\n");
            
            //Get next word
            pch = strtok(NULL," !@#$^&*()-_=+|\\[]{}':;/?.>,<`~\"\n");
        }
    }

    //Create a new hash to inverse to map the frequency to the name    
    GHashTable* r_hash = g_hash_table_new(g_str_hash, g_str_equal);    
    
    //For each word key in our map
    GList* all_words=NULL, *iterator=NULL;
    all_words= g_hash_table_get_keys(hash);
    for(iterator=all_words;iterator;iterator=iterator->next){
        char* temp =(char *)(iterator->data);
        char* temp1 =(char *)g_hash_table_lookup(hash,temp);
        //Allocate space for the key and value
        GString *k= g_string_new(temp);
        GString *v= g_string_new(temp1);
        //Create a new entry in the inverse hash map
        g_hash_table_insert(r_hash, v->str,g_slist_append(g_hash_table_lookup(r_hash, v->str),k->str));
        // printf("'%s' was used %s times\n", temp,temp1 );
    }
    
    //For each key in the inverse hash map
    GList* all_keys=NULL, *iterator1=NULL;
    all_keys=g_hash_table_get_keys(r_hash);
    
    //Sort the list of values
    all_keys=g_slist_sort(all_keys, (GCompareFunc)my_comparator);
    
    for(iterator1=all_keys;iterator1;iterator1=iterator1->next){
        char* temp = (char *)(iterator1->data);
        char* temp1 = (char *)g_hash_table_lookup(r_hash, temp);
        GList* words2=NULL, *iterator2=NULL;
        words2=g_hash_table_get_keys(hash);
        
        //Look at each key in the regular hashmap and if the values match
        //Print it.
        for(iterator2=words2;iterator2;iterator2=iterator2->next){
            char* temp10 =(char *)(iterator2->data);
            char* temp11 =(char *)g_hash_table_lookup(hash,temp10);
            if(strcmp(temp,temp11)==0){
                 printf("%s - %s\n",(char *)temp10, (char *)temp);
            }else{
            }
        }
        
    }
    
    
        
    fclose(file);
    return 0;
}
