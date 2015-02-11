#include <stdlib.h>
#include <stdio.h>

int num[10] = {
    1, 3, 6, 5, 8, 7, 9, 6, 2, 0
  };

int comp(const void *, const void *);

int main(void)
{
    int i;

    printf("Original array: ");
    for(i=0; i<10; i++) printf("%d ", num[i]);


    // add the invocation for qsort
    qsort(&num[0], 10, sizeof(int), &comp);



    printf("\nSorted array: ");
    for(i=0; i<10; i++) printf("%d ", num[i]);
    printf("\n");
    return 0;
}

  /* compare the integers */
int comp(const void *i, const void *j)
{
    printf("\n compare %d, %d", *((int *) i), *(int *)j);
    return *(int *)i - *(int *)j;
}


/*
-----------------------------------------------------------------------

NOTES

NAME
       qsort - sorts an array

SYNOPSIS
       #include <stdlib.h>

       void qsort(void *base, size_t nmemb, size_t size,
                  int(*compar)(const void *, const void *));

DESCRIPTION
       The  qsort() function sorts an array with nmemb elements of size size.
       The base argument points to the start of the array.

       The contents of the array are sorted in ascending order according to a
       comparison  function  pointed  to  by compar, which is called with two
       arguments that point to the objects being compared.

       The comparison function must return an integer less than, equal to, or
       greater  than  zero  if the first argument is considered to be respec-
       tively less than, equal to, or greater than the second.  If  two  mem-
       bers compare as equal, their order in the sorted array is undefined.

RETURN VALUE
       The qsort() function returns no value.

-----------------------------------------------------------------------
*/
