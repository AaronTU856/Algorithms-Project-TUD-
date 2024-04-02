/*
Author:Aaron Baggot
Student number: C22716399
Creating a file with student records for module DT8900 with 6 Students*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME 15
#define SURNAME 15
#define COURSE 10
#define MODULE4 6

struct student{
         
        char name[NAME];
        char surname[SURNAME];
        int id;
        char course[COURSE];
};
int main()
{
int i;
struct student students[6] = {
    {"Tim","Kelly",123456,"Full_Time"},
    {"Patrick","Logan",123457,"Full_Time"},
    {"Anne","Roche",123458,"Full_Time"},
    {"Billy","Cunningham",123459,"Full_Time"},
    {"Paddy","Rogers",123460,"Full_Time"},
    {"John","Reynolds",123461,"Full_Time"}    
};
//open the file
FILE *DT8900_file = fopen("International_Masters_Qualifier.txt","w");
    if(DT8900_file == NULL)
    {
        printf("Error opening file \"International_Masters_Qualifier.txt\"\n");
        return 1;
    }
    //Writing the Students to the file
    for ( i = 0; i < MODULE4; i++)
    {
        fprintf(DT8900_file,"%s %s %d %s\n",students[i].name,students[i].surname,students[i].id,students[i].course);
    }
    
    fclose(DT8900_file);
return 0;
}