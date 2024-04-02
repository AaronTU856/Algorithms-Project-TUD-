/*
Author:Aaron Baggot
Student number: C22716399
Creating a file with student records for module DT265C with 9 Students*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME 15
#define SURNAME 15
#define COURSE 10
#define MODULE2 9

struct student{
         
        char name[NAME];
        char surname[SURNAME];
        int id;
        char course[COURSE];
};

int main()
{

int i;


struct student students[9] = {
    {"Caitlin","Ronald",123456,"Part_Time"},
    {"Jimmy","Dunne",123457,"Part_Time"},
    {"Mary","Kelly",123458,"Part_Time"},
    {"Joan","Donovan",123459,"Part_Time"},
    {"Colin","Buckley",123460,"Part_Time"},
    {"Mathew","Thomas",123461,"Part_Time"},
    {"Kelly","Wright",123462,"Part_Time"},
    {"Cecil","Cox",123464,"Part_Time"},
    {"Jack","Ryan",123465,"Part_Time"}
};

//open the file
FILE *DT265C_file = fopen("Masters_Qualifier.txt","w");

    if(DT265C_file == NULL)
    {
        printf("Error opening file \"Masters_Qualifier.txt\"\n");
        return 1;
    }

    //Writing the Students to the file
    for ( i = 0; i < MODULE2; i++)
    {
        fprintf(DT265C_file,"%s %s %d %s\n",students[i].name,students[i].surname,students[i].id,students[i].course);
    }
    
    fclose(DT265C_file);

return 0;

}