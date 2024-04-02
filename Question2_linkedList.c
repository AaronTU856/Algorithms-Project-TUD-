#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char last_name[15];
    struct student *next;
};

typedef struct student Student;

// function prototypes
void merge_sort(Student **head_ref);
void merge(Student **head_ref);

int main() 
{
    // open the four text files and read in their contents
    FILE *DT265A_file = fopen("Higher_Diploma.txt", "r");
    FILE *DT265C_file = fopen("International_Masters_Qualifier.txt", "r");
    FILE *DT265B_file = fopen("Masters_Qualifier_FT.txt", "r");
    FILE *DT8900_file = fopen("Masters_Qualifier.txt", "r");

    if (!DT265B_file || !DT8900_file) 
    {
        printf("Error: unable to open input files.\n");
        return 1;
    }

    // create a linked list to store the Full Time Students
    Student *head = NULL;
    Student *tail = NULL;
    char first_name[15], last_name[15], id[15], course_type[10];

    // read in the data from each file and add them to the linked list
    while (fscanf(DT265A_file, "%s %s %s %s", first_name, last_name, id, course_type) == 4) 
    {
        // This conditional statement checks if the student is a full-time student by comparing 
        // the course type string with "Full_Time".
        if (strcmp(course_type, "Full_Time") == 0) 
        {
            // If the student is a full-time student, a new Student struct is allocated in memory using malloc
            Student *new_student = (Student *) malloc(sizeof(Student));

            // If the allocation fails, execution breaks out of the loop and any previously allocated memory is not freed
            if (new_student == NULL) 
            {
                // handle allocation failure here
                break;
            }
            // The last name of the new student is copied from the corresponding variable to the new Student struct
            strcpy(new_student->last_name, last_name);
            // The next pointer of the new student is set to NULL
            new_student->next = NULL;
            // If head is NULL, the new student becomes the head and tail of the list
            if (head == NULL) 
            {
                head = new_student;
                tail = new_student;
            } 
            // If head is not NULL, the new student is added to the end of the list

            else 
            {
                tail->next = new_student;
                tail = new_student;
            }
        }
    }
     // read in the data from each file and add them to the linked list
    while (fscanf(DT265C_file, "%s %s %s %s", first_name, last_name, id, course_type) == 4) 
    {
        if (strcmp(course_type, "Full_Time") == 0) 
        {
            Student *new_student = (Student *) malloc(sizeof(Student));
            if (new_student == NULL) 
            {
                // handle allocation failure here
                break;
            }

            strcpy(new_student->last_name, last_name);
            new_student->next = NULL;

            if (head == NULL) 
            {
                head = new_student;
                tail = new_student;
            } 
            else 
            {
                tail->next = new_student;
                tail = new_student;
            }
        }
    }
     // read in the data from each file and add them to the linked list
    while (fscanf(DT265B_file, "%s %s %s %s", first_name, last_name, id, course_type) == 4) {
        if (strcmp(course_type, "Full_Time") == 0) 
        {
            Student *new_student = (Student *) malloc(sizeof(Student));
            if (new_student == NULL) 
            {
                // handle allocation failure here
                break;
            }

            strcpy(new_student->last_name, last_name);
            new_student->next = NULL;

            if (head == NULL) 
            {
                head = new_student;
                tail = new_student;
            } 
            else 
            {
                tail->next = new_student;
                tail = new_student;
            }
        }
    }
     // read in the data from each file and add them to the linked list
    while (fscanf(DT8900_file, "%s %s %s %s", first_name, last_name, id, course_type) == 4) 
    {
        if (strcmp(course_type, "Full_Time") == 0) 
        {
            Student *new_student = (Student *) malloc(sizeof(Student));
            if(head == NULL)
            {
                head = new_student;
                tail = new_student;
            }
            else
            {
                tail->next = new_student;
                tail = new_student;
            }
        }
    }


printf("Full Time Students, sorted by last name:\n");
Student *curr = head;
while (curr != NULL) 
{
    printf("%s\n", curr->last_name);
    curr = curr->next;
}


    return 0;
}

// function to merge two sorted linked lists
void merge(Student **head_ref)
{
    Student *head1 = *head_ref;
    Student *head2 = (*head_ref)->next;
    Student *prev = *head_ref;
    Student *tmp = NULL;

    while (head1 != NULL && head2 != NULL) 
    {
        if (strcmp(head1->last_name, head2->last_name) <= 0) 
        {
            prev = head1;
            head1 = head1->next;
        } 
        else 
        {
            tmp = head2->next;
            head2->next = head1;
            if (head1 == *head_ref) 
            {
                *head_ref = head2;
            } 
            else 
            {
                prev->next = head2;
            }
            prev = head2;
            head2 = tmp;
        }
    }

    if (head1 == NULL) 
    {
        prev->next = head2;
    }
}

void merge_sort(Student **head_ref)
{
    Student *head = *head_ref;
    Student *head1 = NULL;
    Student *head2 = NULL;

    if (head == NULL || head->next == NULL) 
    {
        return;
    }
    // split the list into two halves
    head1 = head;
    head2 = head->next;
    while (head2 != NULL) 
    {
        head2 = head2->next;
        if (head2 != NULL) 
        {
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    head2 = head1->next;
    head1->next = NULL;
    head1 = head;

    // recursively sort the two halves
    merge_sort(&head1);
    merge_sort(&head2);

    // merge the sorted halves
    merge(&head);
}