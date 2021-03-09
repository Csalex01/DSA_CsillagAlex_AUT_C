#include <stdlib.h>
#include "functions.h"

int main() {
    Organization* organization = read_from_file("input.txt");

    print_organization(organization);

    free(organization);

    return 0;
}
