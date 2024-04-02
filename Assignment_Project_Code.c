

/*This is a program to arrange the files created for different Computer courses including Part time, Full time and International modules each with a limited number of places. The program is menu driven provided with options for sorting the list of students, displaying a list of full time students and search for a student by their surname. The option of exiting gracefully. 
Student Name: Aaron Baggot
Student Number: C22716399
TU856 Year 1
Date: 6th April 2023 
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define LONG 30//Long array
#define SHORT 10//Short array
#define ARRAY 4//Number of files you want to import
#define TOTAL 42//Total number of students


//Structures
 struct student
 {
     char name[LONG];
     char surname[LONG];
     int ID;
     char course[SHORT];
 };



//Function prototype or signature
void files_struct(FILE*[], struct student[]);
void print_list(struct student [], int);
void insertion_sort(struct student [], int , int);
void merge(struct student [], int , int , int );
void merge_sort(struct student [], int , int );
void insert(struct student DT[], int);
int binary_search(struct student [], int, int, char []);
void linear_search(struct student DT[], int, const char* student_type);
 



int main()
{

    //Declare variables
    int size_array, menu, exit, search, condition;
    char search_key[LONG];
    struct student DT_combined[TOTAL];
    exit=1;
    condition=1;

    //Declare file pointer
     FILE *file_array[ARRAY];

     //initialising file pointer inside the array. Read the files
     file_array[0] = fopen("Higher_Diploma.txt", "r");
     file_array[1] = fopen("International_Masters_Qualifier.txt", "r");
     file_array[2] = fopen("Masters_Qualifier_FT.txt", "r");
     file_array[3] = fopen("Masters_Qualifier.txt", "r");

    //dynamically change size of array by changing the #define
     size_array=sizeof(DT_combined)/sizeof(DT_combined[0]);

     files_struct(file_array, DT_combined);
     //call functions

    while(exit == 1)
    {
        printf("\n ********** Menu ********** \n");
        printf("1. Sort the list.\n");
        printf("2. Sorted list of Students.\n");         
        printf("3. Display Full-Time students.\n");
        printf("4. Search for a Surname.\n");
        printf("0. Exit \n");
        printf("\nChoose an option from the menu:\n");
        scanf("%d", &menu);
        fflush(stdin);
        

        switch (menu)
        {   
            //Sort the List of Students 
            case 1:
            {
                insert(DT_combined, size_array);                 
                printf("\n\t*** The List is Sorted ***\n");
                condition = 0;
                break;
            }

            //Print the list of all Students
            case 2:
            {
                print_list(DT_combined, size_array);
                break;
            }

            //Display Full Time Students
            case 3:
            {
                linear_search(DT_combined, size_array, "Full_Time");                
                break;
            }

            //Search for Surname
            case 4:
            {
                if(condition == 1)
                {
                    printf("\nThe List needs to be sorted.....\n");
                    break;
                }

                    printf("\nEnter the Surname: \n");
                    scanf("%s", search_key);
                 

                    search = binary_search(DT_combined, 0, size_array-1, search_key);

                //Search whether in the list or not
                if(search == -1)
                {
                    printf("Could not find Surname\n");
                }
                else
                {

                    printf("\n  **** Student number: %d ****", search + 1);
                    printf("\nName: %s\n Surname: %s\nID: %d\n Course: %s\n", DT_combined[search].name,
                    DT_combined[search].surname, DT_combined[search].ID, DT_combined[search].course);

                }//end if else

                break;
            }

            //Exit
            case 0:
            {
                exit = 0;
                printf("\nYou choose to Exit the program....\n");
                printf("\nGoodbye........\n");
                break;
            }

            default:
            {
                printf("\n!!!Wrong input!!!\n");
                break;
            }
        }//end switch
    }//end while

     getchar();

     return 0;
}//end main

//function used to fill the array with the .txt files of students from each module and assign values
void files_struct(FILE* file_array[], struct student DT[])
{
    int i, j;

    j = 0;

    //using fscanf the program scans a string or numerical value and inserts it into struct until the End Of File
    for (i = 0; i < ARRAY; i++)
    {
        while (fscanf(file_array[i], "%s%s%d%s", DT[j].name, DT[j].surname, &DT[j].ID, DT[j].course) != EOF)
        {
            j++;
             
        }//end while

     }//end for

    for (int k = 0; k < ARRAY; k++)
    {
        fclose(file_array[k]);
    }//end for
}//end function

 //function used to print the list of students
void print_list(struct student DT[], int size_array)
{
     for (int i = 0; i < size_array; i++)
     {
        printf("\n****** Student Number: %d ******", i+1);
        printf("\nName: %s\nSurname: %s\nID: %d\nCourse: %s\n", DT[i].name, DT[i].surname,
        DT[i].ID, DT[i].course);
     }//end for
 }//end function


  //Modified insertion sort in order to receive 3 parameters instead of 2
void insertion_sort(struct student array[], int left, int right)
{
    struct student temp;
    for (int i = left + 1; i <= right; i++)
    {
        int j;

        temp=array[i];
        j = i - 1;

        while (strcmp(array[j].surname, temp.surname)>0 && j >= left)
        {
            array[j+1] = array[j];
            j--;
        }//end while

            array[j+1] = temp;
     }//end for
}//end function

 //modified merge in order to accommodate for the left and right side
void merge(struct student array[], int l, int mid, int r)
{
     //Original array separated into two parts left and right array
     int n1, n2;
    
     n1 = mid - l + 1;
     n2 = r - mid;

     //Store array of structs
     struct student left[n1], right[n2];

     for (int i = 0; i < n1; i++)
     {
        left[i] = array[l + i];
     }//end for

     for (int i = 0; i < n2; i++)
     {
        right[i] = array[mid + 1 + i];
     }//end for

     int i = 0;
     int j = 0;
     int k = l;

     //When Finished comparing then merge the two arrays in a larger sub array
     while (i < n1 && j < n2)
     {
         if ((strcmp(left[i].surname, right[j].surname)) < 0||(strcmp(left[i].surname, right[j].surname))==0)
         {
            array[k] = left[i];
            i++;
         }
         else
         {
            array[k] = right[j];
            j++;
         }//end else
            k++;
     } //end while

     // copy remaining elements of left array
     while (i < n1)
     {
        array[k] = left[i];
        k++;
        i++;
     }//end while

     // copy remaining element of right array
     while (j < n2)
     {
        array[k] = right[j];
        k++;
        j++;
     }//end while
}//end function

void merge_sort(struct student DT[], int left, int right)
{
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    merge_sort(DT, left, mid);
    merge_sort(DT, mid + 1, right);
    merge(DT, left, mid, right);
}

 //Binary search using divide and conquer technique to find a surname in an already sorted list
int binary_search(struct student DT[], int low, int high, char key[])
{
    while(low <= high)
    {
        int middle;

        middle=(low + high)/2;

        if(strcmp(key, DT[middle].surname) == 0)
        {
             return middle;
        }
        else
        {
            if(strcmp(key, DT[middle].surname)<0)
            {
                high = middle -1;
            }
            if(strcmp(key, DT[middle].surname)>0)
            {
                low = middle+1;
            }
        }//end if else
    }//end while

     //If case the element is not present
    return -1;
}



//linear search is used because the list is already sorted and match the Full_Time students
void linear_search(struct student DT[], int size, const char* student_type)
{
    // Search for Full time student
    char course[SHORT] = {"Full_Time"};

    // loop through the array of students
    for (int i = 0; i < size; i++)
    {
        // check if the current student's course matches the specified student_type
        if (strcmp(DT[i].course, student_type) == 0)
        {
            //if there is a match, print out the student's details
            printf("\n***** Student number: %d **** ", i + 1);
            printf("\nName: %s\nSurname: %s\nID: %d\nCourse: %s\n", DT[i].name, DT[i].surname,
                   DT[i].ID, DT[i].course);
        }
    }
}

void insert(struct student DT[], int size_array)
{
    int i, j;

    //Sort the list using merge sort
    merge_sort(DT, 0, size_array - 1);

    //Assign the ID values
    for (i = 0; i < size_array; i++)
    {
        DT[i].ID = i + 1;
    }
}


//Insertion sort to sort the array one element at a time used as a test case
/*
void insert(struct student DT[], int size)
{
     // Declare a struct to hold the current element being sorted
    struct student current;
    // Iterate through each element in the array starting at the second element
    for(int i = 1; i < size; i++)
    {
        // Store the current element being sorted
        current = DT[i];

        // Set the index of the current element being sorted
        int j=i;

        while(((strcmp(DT[j-1].surname, current.surname))>0) && j>0)
        {
            // Move the elements to the right if they are greater than the current element
            DT[j] = DT[j-1];
            // Decrement j to continue checking elements to the left
            j= j - 1;
        }//end while
        if(j != i)
        {
            // insert the current element in its correct position
            DT[j] = current;
        }
        
    }//end for
}//end function
*/