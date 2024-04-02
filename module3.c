/*
Author:Aaron Baggot
Student number: C22716399
Creating a file with student records for module DT265B with 14 Students*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME 15
#define SURNAME 15
#define COURSE 10
#define MODULE3 14


struct student{
         
        char name[NAME];
        char surname[SURNAME];
        int id;
        char course[COURSE];
};

int main()
{

int i;

struct student students[14] = {
    {"Pat","Finn",123456,"Full_Time"},
    {"Cathy","Connors",123457,"Full_Time"},
    {"Fred","Fitzpatrick",123458,"Full_Time"},
    {"Karen","Lamb",123459,"Full_Time"},
    {"Mary","Godfrey",123460,"Full_Time"},
    {"Julie","Collins",123461,"Full_Time"},
    {"Thomas","Yeats",123462,"Full_Time"},
    {"John","O'Sullivan",123464,"Full_Time"},
    {"Cathy","Mcguire",123465,"Full_Time"},
    {"Frank","Ryan",123467,"Full_Time"},
    {"Billy","Fleming",123468,"Full_Time"},
    {"Owen","Reid",123469,"Full_Time"},
    {"Don","O'Neill",123468,"Full_Time"},
    {"Caroline","Peters",123469,"Full_Time"}
};




//open the file
FILE *DT265B_file = fopen("Masters_Qualifier_FT.txt","w");

    if(DT265B_file == NULL)
    {
        printf("Error opening file \"Masters_Qualifier_FT.txt\"\n");
        return 1;
    }

    //Writing the Students to the file
    for ( i = 0; i < MODULE3; i++)
    {
        fprintf(DT265B_file,"%s %s %d %s\n",students[i].name,students[i].surname,students[i].id,students[i].course);
    }
    
    fclose(DT265B_file);


return 0;

}