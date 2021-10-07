#include <string.h>
#include <stdlib.h>
#include "employee.h"


int main()
{
   PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
   PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
   PtrToEmployee searchEmployeeByPhone(const Employee table[], int tableSize, char *targetPhone);
   PtrToEmployee searchEmployeeBySalary(const Employee table[], int tableSize, double targetSalary);

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

   matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "908-555-2234");

   if (matchPtr != NULL)
   {
      printf("Employee phone number 909-555-1235 is in record %d\n\n", matchPtr - EmployeeTable);
   }
   else
   {
      printf("Employee phone number 909-555-1235 is NOT found in the record\n\n");
   }

   matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 7.80);

   if (matchPtr != NULL)
   {
      printf("Employee salary 7.80 is in record %d\n\n", matchPtr - EmployeeTable);
   }
   else
   {
      printf("Employee salary 7.80 is NOT found in the record\n\n");
   }

   return EXIT_SUCCESS;
}