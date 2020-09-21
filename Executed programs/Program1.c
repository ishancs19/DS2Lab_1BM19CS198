/*
WAP for the below given scenario:
A university wants to automate their admission process. Students are admitted based on the marks scored in a qualifying exam.
A student is identified by student id, age and marks in qualifying exam. Data are valid, if:
●	Age is greater than 20
●	Marks is between 0 and 100 (both inclusive)
A student qualifies for admission, if
●	Age and marks are valid and
●	Marks is 65 or more
Write a program to represent the students seeking admission in the university.
*/

#include <stdio.h>
#define SIZE 100
struct student {
    
    int id;
    int age;
    int marks;
    
};

    
void input(struct student s1[]) {
    
    printf("\nEnter the id: ");
    scanf("%d", &s1->id);
    printf("\nEnter the age: ");
    scanf("%d", &s1->age);
    printf("\nEnter the marks: ");
    scanf("%d", &s1->marks);
    
}

int check(struct student s1[])   {
    if (s1->age > 20 && (s1->marks >=0 && s1->marks <= 100)) {
        if(s1->marks >= 65)
        return 1;
        else return 2;
    }
    else
    return 3;
}

void outcome(int flag, struct student s1[]) {
    
    if(flag == 1)
    printf("\n\tStudent information is valid and student is eligible for admission\n");
    else if(flag == 2)
    printf("\n\tStudent information is valid but student is not eligible for admission\n");
    else
    printf("\n\tStudent information is invalid\n");
    
}

int main()
{
    
    struct student s1[SIZE];
    int n, flag = 0;
    printf("\nEnter number of students: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
		printf("\nEnter information of student %d", i+1);
		input(s1);
		flag = check(s1);
		outcome(flag, s1);
	}
    return 0;
    
}
