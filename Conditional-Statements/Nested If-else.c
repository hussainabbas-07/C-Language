// EXAMPLE 1:
#include <stdio.h>
int main() 
{
    int score;
    char passed_subjects;

    printf("Enter your score (0-100): ");
    scanf("%d", &score);

    if(score >= 0 && score <= 100) {
        if(score >= 90) {
            printf("Grade: A\n");
            printf("Did you pass all subjects? (Y/N): ");
            scanf(" %c", &passed_subjects);
            if(passed_subjects == 'Y' || passed_subjects == 'y') {
                printf("Excellent! You passed with distinction.\n");
            } else {
                printf("Good, but you need to pass all subjects for distinction.\n");
            }
        } else if(score >= 75) {
            printf("Grade: B\n");
        } else if(score >= 60) {
            printf("Grade: C\n");
        } else if(score >= 50) {
            printf("Grade: D\n");
        } else {
            printf("Grade: F\n");
        }
    } else {
        printf("Invalid score!\n");
    }

    return 0;
}