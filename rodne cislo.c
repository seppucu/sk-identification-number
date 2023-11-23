#include "rodne cislo.h"

int main()
{
    char rc[11];

    // Enter ID number
    printf("Zadajte rodne cislo (RRMMDDXXXX): ");
    scanf("%s", rc);

    // Calculation of age, days, sex
    calculateAge(rc);

    return 0;
}
