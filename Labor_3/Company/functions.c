//
// Created by csill on 3/6/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

Organization *read_from_file(char* file_name) {
    FILE* fin = fopen(file_name, "r");

    Organization *organization = (Organization*)malloc(sizeof(Organization));

    fscanf(fin, "%i", &organization->employeeCount);
    fscanf(fin, "%s", organization->organizationName);

    organization->employees = (Employee*)malloc(organization->employeeCount * sizeof(Employee));

    for(int i = 0; i < organization->employeeCount; i++) {
        fscanf(fin, "%s", organization->employees[i].firstName);
        fscanf(fin, "%s", organization->employees[i].lastName);
        fscanf(fin, "%s", organization->employees[i].institute);
        fscanf(fin, "%i", &organization->employees[i].education);
        fscanf(fin, "%lf", &organization->employees[i].salary);
    }

    return organization;
}

void print_organization(Organization* organization) {
    printf("Organization name: %s\n", organization->organizationName);
    printf("Total employees: %i\n", organization->employeeCount);

    printf("Employees: \n");

    for(int i = 0; i < organization->employeeCount; i++) {
        printf("- %s %s, %s (",
               organization->employees[i].firstName,
               organization->employees[i].firstName,
               organization->employees[i].institute);

        switch (organization->employees[i].education) {
            case NO_EDUCATION:
                printf("NO_EDUCATION");
                break;
            case MIDDLE_SCHOOL:
                printf("MIDDLE_SCHOOL");
                break;
            case HIGH_SCHOOL:
                printf("HIGH_SCHOOL");
                break;
            case UNIVERSITY:
                printf("UNIVERSITY");
                break;
        }
        printf("), EUR%.2f", organization->employees[i].salary);

        printf("\n");

    }
}