//Ted McNulty
//EX08
//4/10/17

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>


int main(int argc, char** argv) {
    
    //Create hash table to store values
    GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);    

    //Read the file from input
    char const* const fileName = argv[1]; 
    FILE* file = fopen(fileName, "r");
    FILE* f1 = fopen("temp.txt","w");
    char line[256];
    
    //Get each line
    while (fgets(line, sizeof(line), file)) {
        
        //Divide each line by special characters
        char * pch;
        pch = strtok(line," !@#$^&*()-_=+|\\[]{}':;/?.>,<`~\"\n");
        while(pch!=NULL){
            
           
            if(g_hash_table_lookup(hash, pch)==NULL){
                //If item isn't in hashtable add it with value 1
                g_hash_table_insert(hash, pch,"1");
                //Write unique keys to file 
                fprintf(f1,"%s\n",pch);
            }
            else{
                //Otherwise get the value
                char * count = g_hash_table_lookup(hash, pch);
                int i = atoi(count);
                i=i+1;
                //Add 1 and convert back into string
                char buffer[10];
                sprintf(buffer, "%d", i);
                //Replace old entry
                g_hash_table_replace(hash, pch, buffer);
            }
            //Printing and calling lookup works fine here
            printf("%s | ",pch);
            printf("%s",(char *)g_hash_table_lookup(hash, pch));
            printf("\n");
            
            //Get next word
            pch = strtok(NULL," !@#$^&*()-_=+|\\[]{}':;/?.>,<`~\"\n");
        }
    }
    
    fclose(f1);
    
    //Read the file to read each key/value
    FILE* f3 = fopen("temp.txt","r");
    //Make a buffer
    char line1[256];
    while(fgets(line1, sizeof(line1), f3)){
        char * sts;
        sts = strtok(line1, " \n");
        while(sts!=NULL){
            // printf("%s", sts);
            
            //For whatever, the lookup function doesn't return the same values here as it does above.
            //It also does not print all the correct keys when using g_hash_table_get_keys ()
            printf("The word %s appears %s times\n",sts, (char *)g_hash_table_lookup(hash, sts));
            sts = strtok(NULL, " \n");
        }
    }
    
    fclose(file);
    return 0;
}
