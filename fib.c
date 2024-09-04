#include <stdio.h>

int fibonacciRecursive(int recursionValue) {
   if (recursionValue == 0 || recursionValue == 1) {
      return recursionValue;
   }
   return (fibonacciRecursive(recursionValue - 2) + fibonacciRecursive(recursionValue - 1));
}

int main(int argc, char *argv[]) {
   int firstHalfOfN = *argv[1];
   int secondHalfOfN;
   char methodOfAddition = *argv[2];
   char *fileName = argv[3];

   FILE * fibonacciFile = fopen(fileName, "r");
   fscanf(fibonacciFile, "%u", &secondHalfOfN);
   
   int finalN = firstHalfOfN + secondHalfOfN;
   if (methodOfAddition == 'i') { // iterative
      int sumOfFibonacci = 0;
      int previousNum = 0;
      int currentNum = 1;
      for (int indexOfLoop = 0; indexOfLoop < finalN; ++indexOfLoop) {
         sumOfFibonacci += previousNum + currentNum;
         previousNum = currentNum;
         currentNum = sumOfFibonacci;
      }
      return sumOfFibonacci;
   } else { // recursive
      return fibonacciRecursive(finalN);
   }
}