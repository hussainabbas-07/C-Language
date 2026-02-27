/*#include <stdio.h>

    struct student
    {
        /* data */
        // char name[10];
        // int rollNo;
        // float gpa; 
    // };
    

/*int main()
{
    struct student hussain;
    strcpy(hussain.name, "Hussain");
    hussain . rollNo = 1234; 
    hussain . gpa = 3.6;
    
    printf("%s\n", hussain . name);
    printf("%d\n", hussain . rollNo);
    printf("%.2f", hussain . gpa);
    
    getchar();
    return 0;
}*/

/*#include <stdio.h>
#include <string.h>

struct student
{
    char name[20];
    int rollNo;
    float GPA;
    char grade[1];
};

int main()
{
    struct student hussain;
    strcpy(hussain . name , "Hussain");
    hussain . rollNo = 251334;
    hussain . GPA = 3.673;
    strcpy(hussain . grade , "A");

    struct student jaun;
    strcpy(jaun . name , "Jaun");
    jaun . rollNo = 251335;
    jaun . GPA = 3.5;
    strcpy(jaun . grade , "B");

    printf("Name: %s\n", hussain.name);
    printf("Roll No: %d\n", hussain.rollNo);
    printf("GPA: %.2f\n", hussain.GPA);
    printf("Grade: %s\n", hussain.grade);

    printf("\nName: %s\n", jaun.name);
    printf("Roll No: %d\n", jaun.rollNo);
    printf("GPA: %.2f\n", jaun.GPA);
    printf("Grade: %s\n", jaun.grade);

    getchar();
    return 0;
}*/

#include <stdio.h>
#include <string.h>

struct CS1A
{
    int sNo;
    char name[15];
    int rollNo;
    float GPA;
    char Grade[1];
};

int main()
{
    struct CS1A stu[3];
    stu[0] . sNo = 1;
    strcpy(stu[0] . name , "Hussain");
    stu[0] . rollNo = 251334;
    stu[0] . GPA = 3.890;
    strcpy(stu[0] . Grade , "A");

    stu[1] . sNo = 2;
    strcpy(stu[1] . name , "Huzaifa");
    stu[1] . rollNo = 251331;
    stu[1] . GPA = 3.70;
    strcpy(stu[1] . Grade , "B");

    stu[2] . sNo = 3;
    strcpy(stu[2] . name , "Anumta");
    stu[2] . rollNo = 251004;
    stu[2] . GPA = 3.50;
    strcpy(stu[2] . Grade , "B");

    for(int i=0; i<3; i++) 
    {
        printf("S.No:%d\n Name:%s\n Roll No;%d\n GPA:%.2f\n Grade:%s\n", stu[i].sNo, stu[i].name, stu[i].rollNo, stu[i].GPA, stu[i].Grade);
    }

    getchar();
    return 0;
}