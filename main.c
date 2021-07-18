#include <stdio.h>

/*
 * Name     : Ramindu Walgama
 * TempID   : 201177
 * Email    : raminduw200@gmail.com
 */

struct employee createEmp();
void coinAnalysis(int salary, char * emp_name);
void printSummary();

// Data structure to save employee data
struct employee{
    char name[50];
    int salary;
};

// Notes 2d array keep track of number of notes that required to pay total salaries.
int len_notes = 10;
int notes[10][2] = {{5000, 0}, {1000, 0}, {500, 0}, {100, 0}, {50, 0}, {20, 0}, {10, 0}, {5, 0}, {2, 0}, {1, 0}};
long total_salary = 0;

int main() {
    // emp refers to employee
    int emp_count = 1;
    printf("\n+-------------------------------------------------------------+\n");
    printf("+---------------Laara International (Pvt.) Ltd.---------------+\n");
    printf("+------------------------Coin Analyser------------------------+\n");
    printf("+-------------------------------------------------------------+\n\n");
    printf("\tEnter No of employees:\t");
    scanf("%d", &emp_count);
    printf("\n\n");

    // Array to keep track of all the employee details as a employee data structure array.
    struct employee emp_arr[emp_count];

    // Input and process each employee data
    for (int i = 0; i < emp_count; ++i) {
        emp_arr[i] = createEmp();
        coinAnalysis(emp_arr[i].salary, emp_arr[i].name);
        total_salary += emp_arr[i].salary;
        printf("+-------------------------------------------------------------+\n\n");
    }

    printSummary();
    printf("\t+---------------------------------------+\n");

    return 0;
}

/*
 * @function: collect employee data
 * @return: employee data struct
 * @params: no parameters. take user inputs within the function
 */
struct employee createEmp(){
    struct employee emp_;

    printf("\tEmployee name:\t\t");
    scanf("%s", emp_.name);
    printf("\tSalary of %s:\t", emp_.name);
    scanf("%d", &emp_.salary);

    return emp_;
}

/*
 * @function: calculate the number of notes required to pay a salary for
 *            a given employee and update the total required notes.
 * @return: void : prints the summary
 * @params: salary and name of employee
 */
void coinAnalysis(int salary, char * emp_name){
    int noteNeed[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    printf("\t------------ %s ------------\n", emp_name);

    for (int i = 0; i < len_notes; ++i) {
        if(salary / notes[i][0]) {
            noteNeed[i] = salary / notes[i][0];
            notes[i][1] += noteNeed[i];
            printf("\t\tRs %d\t: \t%d\n", notes[i][0], salary / notes[i][0]);
            salary -= notes[i][0] * noteNeed[i];
            if(salary < 1) break;
        }
    }
    printf("\t-------------------------------\n");
    printf("\n\n");
}

/*
 * @function: print the summary: total salary of all employees and number
 *            of notes required to pay the total salary
 * @return: void : prints the summary
 * @params: -
 */
void printSummary(){
    printf("+-------------------------------------------------------------+\n");
    printf("+---Laara International (Pvt.) Ltd. (raminduw200@gmail.com)---+\n");
    printf("+-------------------------------------------------------------+\n");
    printf("\t\tTotal Salary\t : \t%ld\t\t\n", total_salary);
    printf("+-------------------------------------------------------------+\n");

    for (int i = 0; i < 10; ++i) {
        if(notes[i][1])
        printf("\t|\tTotal %ds\t| \t%d\t|\n", notes[i][0], notes[i][1]);
    }
}
