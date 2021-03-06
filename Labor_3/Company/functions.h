//
// Created by csill on 3/6/2021.
//

#ifndef COMPANY_FUNCTIONS_H
#define COMPANY_FUNCTIONS_H

enum Education {
    NO_EDUCATION    = 0,
    MIDDLE_SCHOOL   = 1,
    HIGH_SCHOOL     = 2,
    UNIVERSITY      = 3
};

typedef struct {
    char firstName[20];
    char lastName[20];
    char institute[40];

    enum Education education;

    double salary;
} Employee;

typedef struct {
    char organizationName[30];
    int employeeCount;
    Employee* employees;
} Organization;

Organization *read_from_file(char* file_name);
void print_organization(Organization* organization);

#endif //COMPANY_FUNCTIONS_H
