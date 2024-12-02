#include <stdio.h>

int fibonacciIterative(int iterativeValue)
{
  int sumOfFibonacci = 0;
  int previousNum = 0;
  int currentNum = 1;
  for (size_t indexOfLoop = 0; indexOfLoop < iterativeValue; ++indexOfLoop)
  {
    if (indexOfLoop == 0)
    {
      continue;
    } // 0 does nothing
    sumOfFibonacci = previousNum + currentNum;
    previousNum = currentNum;
    currentNum = sumOfFibonacci;
  }
  return sumOfFibonacci;
}

int fibonacciRecursive(int recursionValue)
{
  if (recursionValue == 0 || recursionValue == 1)
  {
    return recursionValue;
  }
  return (fibonacciRecursive(recursionValue - 2) + fibonacciRecursive(recursionValue - 1));
}

int main(int argc, char *argv[])
{
  if (argc == 4)
  {
    printf("Usage: ./fib n i|f filename\n");
    return -1;
  }

  int firstHalfOfN = *argv[1] - '0'; // account for ascii from command line
  int secondHalfOfN = 0;
  char methodOfAddition = *argv[2];
  char *fileName = argv[3];

  FILE *fibonacciFile = fopen(fileName, "r");
  fscanf(fibonacciFile, "%d", &secondHalfOfN);
  fclose(fibonacciFile);
  int finalN = firstHalfOfN + secondHalfOfN - 1; // 1-based index

  if (methodOfAddition == 'i')
  { // iterative
    int sumOfFibonacci = fibonacciIterative(finalN);
    printf("%d", sumOfFibonacci);
    return 0;
  }
  else
  { // recursive
    int sumOfFibonacci = fibonacciRecursive(finalN);
    printf("%d", sumOfFibonacci);
    return 0;
  }
}
