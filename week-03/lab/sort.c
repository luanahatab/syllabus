#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>


void selection(int numbers[], int size);
void bubble(int numbers[], int size);

void print_array(int numbers[], int size)
{
  for(int i = 0; i < size; i++)
  {
    printf("%d\n", numbers[i]);
  }
}

void usage(string error)
{
  printf("\n\tUsage ./sort [b|s] FILE\n\n\tError: %s\n\n", error);
}

int main(int argc, char* argv[])
{

  if(argc < 3)
  {
    usage("wrong number of arguments");
    return 1;
  }

  if(strcmp(argv[1],"b") != 0 && strcmp(argv[1],"s") != 0)
  {
    usage("second argument need to be 'b' or 's'");
    return 1;
  }

  FILE* fp = NULL;
  fp = fopen(argv[2], "r");
  if (fp == NULL)
    {
      printf("Erro ao abrir o arquivo %s.\n", argv[2]);
      return 1;
    }

  // getting the number of elements from the first line
  char *line = NULL;
  size_t len = 0;
  getline(&line, &len, fp);
  int N = atoi(line);

  // creating the array and reading the file
  int numbers[N];

  for(int i = 0; i < N; i++)
  {
    int r = getline(&line, &len, fp);
    if(r == -1)
    {
      printf("Error, missing numbers according to the header!");
      return 1;
    }
    numbers[i] = atoi(line);
  }

  /* testing, next line will be replaced by a code that, given the
     second parameter, choose the right sort function to execute. */
  print_array(numbers, N);

  fclose(fp);
  return 0;
}
