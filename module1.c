/*
Author:Aaron Baggot
Student number: C22716399
Creating a file with student records for module DT265A with 13 Students*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME 15
#define SURNAME 15
#define COURSE 10
#define MODULE1 13

//Structure for Student record
struct student{
         
        char name[NAME];
        char surname[SURNAME];
        int id;
        char course[COURSE];
};
int main()
{
int i;
//Details of each student name, surname and ID 
struct student students[13] = {
    {"Aaron","Baggot",123456,"Part_Time"},
    {"John","Mulligan",123457,"Part_Time"},
    {"Patrick","Kelly",123458,"Part_Time"},
    {"Helen","OReilly",123459,"Part_Time"},
    {"Mary","Ford",123460,"Part_Time"},
    {"Julie","Henry",123461,"Part_Time"},
    {"Thomas","Ennis",123462,"Part_Time"},
    {"Kate","Roche",123464,"Part_Time"},
    {"Cathy","Thomson",123465,"Part_Time"},
    {"Frank","OShea",123467,"Part_Time"},
    {"Billy","Bracken",123468,"Part_Time"},
    {"Owen","Walker",123469,"Part_Time"},
    {"Shane","Lowry",123470,"Part_Time"}
};
//open the file for inserting details
FILE *DT265A_file = fopen("Higher_Diploma.txt","w");
    if(DT265A_file == NULL)
    {
        printf("Error opening file \"Higher_Diploma.txt\"\n");
        return 1;
    }//end if
    //Writing the Students to the file
    for ( i = 0; i < MODULE1; i++)
    {
        fprintf(DT265A_file,"%s %s %d %s\n",students[i].name,students[i].surname,students[i].id,students[i].course);
    }   
    fclose(DT265A_file);
return 0;
}//end main