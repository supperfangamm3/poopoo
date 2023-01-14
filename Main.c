#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    char name[50];
    int age;
    char address[100];
    float marks;
};

void input(struct Student* s, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Enter name: ");
        scanf("%s", s[i].name);
        printf("Enter age: ");
        scanf("%d", &s[i].age);
        printf("Enter address: ");
        scanf("%s", s[i].address);
        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
    }
}

void display(struct Student* s, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Name: %s\n", s[i].name);
        printf("Age: %d\n", s[i].age);
        printf("Address: %s\n", s[i].address);
        printf("Marks: %.2f\n", s[i].marks);
    }
}

void saveToFile(struct Student* s, int n){
    int i;
    FILE* fp = fopen("students.txt", "w");
    if(fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    for(i = 0; i < n; i++){
        fprintf(fp, "Name: %s\n", s[i].name);
        fprintf(fp, "Age: %d\n", s[i].age);
        fprintf(fp, "Address: %s\n", s[i].address);
        fprintf(fp, "Marks: %.2f\n", s[i].marks);
    }
    fclose(fp);
    printf("Data saved to file successfully!\n");
}

int main(){
    int n, i;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student* s = (struct Student*)malloc(n * sizeof(struct Student));
    input(s, n);
    display(s, n);
    saveToFile(s, n);
    free(s);
    return 0;
}
