#include <stdio.h>

#include "036_mutual_struct.h"

employee_t create_employee(int id, char *name) {
    employee_t emp = {
        .id = id,
        .name = name,
        .department = NULL
    };

    return emp;
}

department_t create_department(char *name) {
    department_t dept = {
        .name = name,
        .manager = NULL
    };

    return dept;
}

void assign_employee(employee_t *emp, department_t *department) {
    emp->department = department;
}

void assign_manager(department_t *dept, employee_t *manager) {
    dept->manager = manager;
}

int main() {
    employee_t employee = create_employee(1, "alice");
    department_t department = create_department("human resources");

    assign_employee(&employee, &department);
    assign_manager(&department, &employee);

    printf("employee: %s\ndepartment: %s\nmanager: %s\n",
           employee.name,
           employee.department->name,
           department.manager->name);

    return 0;
}