/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 13: Basic Data Structures
 * Filename : lab13_practice6_payroll.c
 * Description: Reads 5 employees (name, salary) into an array of
 *              structs, sorts them ascending by salary using bubble
 *              sort, prints the sorted list, and reports total payroll.
 */

#include <stdio.h>

#define NUM_EMPLOYEES 5
#define NAME_LEN 20

typedef struct {
    char name[NAME_LEN];
    double salary;
} Employee;

void read_employees(Employee employees[], int count);
void sort_by_salary(Employee employees[], int count);
void print_employees(const Employee employees[], int count);
double total_payroll(const Employee employees[], int count);

/*
 * main: reads NUM_EMPLOYEES employees, sorts them ascending by salary,
 * prints the sorted list, and prints the total payroll.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    Employee employees[NUM_EMPLOYEES];

    read_employees(employees, NUM_EMPLOYEES);

    sort_by_salary(employees, NUM_EMPLOYEES);

    printf("\nSorted by salary (ascending):\n");
    print_employees(employees, NUM_EMPLOYEES);

    printf("Total payroll: %.2f\n", total_payroll(employees, NUM_EMPLOYEES));

    return 0;
}

/*
 * read_employees: reads a name and salary for each employee.
 * Parameters: employees - destination array of Employee, count - how
 *             many employees to read
 * Returns: nothing
 */
void read_employees(Employee employees[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Employee %d name: ", i + 1);
        scanf("%19s", employees[i].name);
        printf("Salary: ");
        scanf("%lf", &employees[i].salary);
    }
}

/*
 * sort_by_salary: sorts employees in ascending order of salary using a
 * bubble sort with whole-struct assignment for swaps.
 * Parameters: employees - array of Employee to sort in place, count -
 *             number of employees
 * Returns: nothing
 */
void sort_by_salary(Employee employees[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (employees[j].salary > employees[j + 1].salary) {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

/*
 * print_employees: prints each employee's name and salary, one per
 * line.
 * Parameters: employees - array of Employee, count - number of entries
 * Returns: nothing
 */
void print_employees(const Employee employees[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%-15s %10.2f\n", employees[i].name, employees[i].salary);
    }
}

/*
 * total_payroll: sums the salary field over all employees.
 * Parameters: employees - array of Employee, count - number of entries
 * Returns: the total payroll as a double
 */
double total_payroll(const Employee employees[], int count) {
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += employees[i].salary;
    }
    return total;
}
