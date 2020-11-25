#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


enum Type {BSc, MSc, PhD}; 

const char* first_names[] = {"Gyenes", "Heck", "Hojek", "Nagy", "Rajki"};
const char* last_names[] = {"Zsolt", "Zsombor", "Soma", "Levente", "Anna", "Emese"};

typedef struct Impact {
    double published;
    int erdos;
} Impact;

typedef union Extra {
    int courses_completed;
    int credit_index;
    Impact phd_impact;
} Extra;

typedef struct Student { 
    int id, age;
    double avg;
    char* name;
    enum Type course; 
    Extra extras;
} Student;

Student* highest_avg(Student* a[], int size) {
    Student* highest = a[0];
    for (int i = 0; i < size; ++i) {
        if (a[i]->avg > highest->avg) {
            highest = a[i];
        }
    }
    return highest;
}

Student* student_init(enum Type a) {
    Student *s = malloc(sizeof(Student));
    // s->id, (*s).id
    s->id = rand();
    s->age = rand() % 8 + 18;
    s->avg = (rand() % 30) / 6.0;
    char* student_name = calloc(255, sizeof(char));
    strcat(student_name, first_names[rand() % 5]); 
    strcat(student_name, " ");
    strcat(student_name, last_names[rand() % 6]);
    char* tmp = realloc(student_name, strlen(student_name) + 1);
    if (tmp != NULL) student_name = tmp;
    s->name = student_name;
    s->course = a;
    switch (a) {
        case BSc:
            s->extras.courses_completed = rand() % 20;
            break;
        case MSc:
            s->extras.credit_index = rand() % 4 + 2;
            break;
        case PhD:
            s->extras.phd_impact.published = rand() % 5;
            s->extras.phd_impact.erdos = rand () % 10 + 2;
            break;
        default:
            printf("Wrong Type!\n");
            free(s->name);
            free(s);
            return 0;
    }
    return s;
}

int main() {
    srand(time(0));
    Student* a[5];
    for (int i = 0; i < 5; ++i) {
        a[i] = student_init(rand() % 3);
    }
    Student* highest = highest_avg(a, 5);
    printf("Student id: %d\nStudent name: %s\nStudent average: %f\nStudent type: %d\n", highest->id, highest->name, highest->avg, highest->course);
    for (int i = 0; i < 5; ++i) {
        free(a[i]->name);
        free(a[i]);
    }
}