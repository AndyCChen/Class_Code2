#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define R 3
#define C 3

int checkLuShu(int square[R][C]);

int main()
{
   srand(time(NULL));
   const int SIZE = 9;
   int number[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   int magicSquare[R][C];
   int flag = 0, count = 0;

   do
   {
      // shuffle number
      for (int i = 0; i < SIZE; i++)
      {
         int temp = number[i];
         int randIndex = rand() % 9;

         // do swap with element and random index
         number[i] =  number[randIndex];
         number[randIndex] = temp;
      }

      // populate magic square
      int index = 0;
      for (int row = 0; row < R; row++)
      {
         for (int col = 0; col < C; col++)
         {
            magicSquare[row][col] = number[index];
            index++;
         }
      }

      count++;
      // do check on magic square
      if (checkLuShu(magicSquare) == 1)
      {
         printf("Lu Shu square found after %d squares generated!\n", count);
         flag = 1;
      }
   }
   while(flag != 1);

   for (int row = 0; row < R; row++)
   {
      printf("[");
      for (int col = 0; col < C; col++)
      {
         printf("%d ", magicSquare[row][col]);
      }
      printf("\b]\n");
   }

   return 0;
}

int checkLuShu(int square[R][C])
{
   // check sum of each row
   int sum = 0;
   for (int row = 0; row < R; row++)
   {
      for (int col = 0; col < C; col++)
      {
         sum += square[row][col];
      }

      if (sum != 15)
      {
         return 0; // return 0 for false if not equal to 15
      }
      sum = 0;
   }
   
   // check sum of each column
   sum = 0;
   for (int col = 0; col < C; col++)
   {
      for (int row = 0; row < R; row++)
      {
         sum += square[row][col];
      }

      if (sum != 15)
      {
         return 0;
      }
      sum = 0;
   }

   // check sum of left to right diagonal
   sum = 0;
   for(int row = 0, col = 0; row < R && col < C; row++, col++)
   {
      sum += square[row][col];
   }

   if (sum != 15)
   {
      return 0;
   }

   // check sum of right to left diagonal
   sum = 0;
   for(int row = 0, col = C - 1; row < R && col >= 0; row++, col--)
   {
      sum += square[row][col];
   }

   if (sum != 15)
   {
      return 0;
   }

   return 1; // all rows, cols, and diagonal must sum to 15 if this line is reached
}