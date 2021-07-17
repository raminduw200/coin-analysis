#include <stdio.h>

/*
 * Name     : Ramindu Walgama
 * TempID   : 201177
 * Email    : raminduw200@gmail.com
 */

struct employee createEmp();
void coinAnalysis(int salary);
void printSummary();

struct employee{
    char name[50];
    int salary;
};

int len_notes = 10;
int notes[10][2] = {{5000, 0}, {1000, 0}, {500, 0}, {100, 0}, {50, 0}, {20, 0}, {10, 0}, {5, 0}, {2, 0}, {1, 0}};
long total_salary = 0;

int main() {
    // emp refers to employee
    int emp_count = 1;
    printf("No of employees: ");
    scanf("%d", &emp_count);
    printf("\n\n");

    struct employee emp_arr[2];

    for (int i = 0; i < emp_count; ++i) {
        emp_arr[i] = createEmp();
        coinAnalysis(emp_arr[i].salary);
        total_salary += emp_arr[i].salary;
    }

    printSummary();

    return 0;
}


struct employee createEmp(){
    struct employee emp_;

    printf("Give employee name: ");
    scanf("%s", &emp_.name);
    printf("Give the salary of %s: ", emp_.name);
    scanf("%d", &emp_.salary);

    return emp_;
}

void coinAnalysis(int salary){
    int noteNeed[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    printf("Coin analysis:\n");

    for (int i = 0; i < len_notes; ++i) {
        if(salary / notes[i][0]) {
            noteNeed[i] = salary / notes[i][0];
            notes[i][1] += noteNeed[i];
            printf("Rs %d: %d\n", notes[i][0], salary / notes[i][0]);
            salary -= notes[i][0] * noteNeed[i];
            if(salary < 1) break;
        }
    }
    printf("\n\n");
}

void printSummary(){
    printf("Laara International (Pvt.) Ltd. (raminduw200@gmail.com)\n");
    printf("Total Salary: %ld\n", total_salary);
    for (int i = 0; i < 10; ++i) {
        if(notes[i][1])
        printf("Total %ds: %d\n", notes[i][0], notes[i][1]);
    }
}
