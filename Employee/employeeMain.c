#include <string.h>
#include <stdlib.h>
#include "employee.h"


// gcc employeeMain.c employeeTable.c employeeOne.c
// gcc employeeMain.c employeeTable.c employeeTwo.c

int main()
{
   PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
   PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);

   extern Employee EmployeeTable[];
   extern const int EmployeeTableEntries;

   PtrToEmployee matchPtr;
   matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

   if (matchPtr != NULL)
   {
      printf("Employee ID 1045 is in record %d\n\n", matchPtr - EmployeeTable);
   }
   else
   {
      printf("Employee ID 1045 is NOT found in the record\n\n");
   }

   matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");

   if (matchPtr != NULL)
   {
      printf("Employee Tony Bobcat is in record %d\n\n", matchPtr - EmployeeTable);
   }
   else
   {
      printf("Employee Tony Bobcat is NOT found in the record\n\n");
   }

   return EXIT_SUCCESS;
}