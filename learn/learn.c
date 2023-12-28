#include <stdio.h>

int main()
{
    int x; // declaration
    x = 3; // assignment
    int y = 321; // declaration and initialization

    int age = 25;
    float gpa = 2.05;
    char grade = 'C'; // single quotes for single character
    char name[] = "Bro"; // double quotes for string, array of characters

    printf("Hello %s\n", name);
    printf("You are %d age years old\n", age);
    printf("you have a %f gpa of grade in class\n", gpa);
    printf("you have a %c grade in class\n", grade);


}