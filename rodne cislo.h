#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function for ID number validity check
int isValidRC(char *rc)
{
    int len = strlen(rc);

    // Check the length of the ID number
    if (len != 10)
    {
        return 0;
    }

    // Check that the ID number consists of digits
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(rc[i]))
        {
            return 0;
        }
    }

    return 1;
}

// Function for solving the equation
void calculateAge(char *rc)
{
    if (!isValidRC(rc))
    {
        printf("Nespravne rodne cislo.\n");
        return;
    }

    int year, month, day;
    sscanf(rc, "%2d%2d%2d", &year, &month, &day);

    // tm structure
    if (year < 24)
    {
        year += 2000;
    }
    else
    {
        year += 1900;
    }

    struct tm birthDate = {0};
    birthDate.tm_year = year - 1900;
    birthDate.tm_mon = month - 1;
    birthDate.tm_mday = day;

    // Get the current date
    time_t currentTime = time(NULL);
    struct tm *currentDate = localtime(&currentTime);

    // Calculation of age in yeas
    int age = currentDate->tm_year - birthDate.tm_year;

    // Calculation of age in days
    time_t birthTime = mktime(&birthDate);
    int daysDifference = (currentTime - birthTime) / (60 * 60 * 24);

    // Output results
    printf("Pohlavie: %c\n", (rc[2] == '0' || rc[2] == '1') ? 'M' : 'F');
    printf("Vek: %d\n", age);
    printf("Od datumu narodenia preslo dni: %d\n", daysDifference);
}

