#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h> //yes


int MAXSIZE;

int largestValue(int arr[MAXSIZE]);
int smallestValue(int arr[MAXSIZE], int largPos);
void permcreator(int arr[MAXSIZE], int largPos, int smallVal, int arr2[MAXSIZE]);
void sort(int arr[MAXSIZE], int size);
int factorial(int x);

int main()
{
    printf("Enter the size of the tuple: ");
    scanf("%d", &MAXSIZE);
    int arr[MAXSIZE];
    int arr2[MAXSIZE];
    int largPos, smallVal;

    for (int i = 0; i < MAXSIZE; i++)
    {
        printf("Enter an integer for the tuple: ");
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < MAXSIZE; i++)
    {
        arr2[i] = arr[i];
    }

    sort(arr, MAXSIZE);
    sort(arr2, MAXSIZE);

    for (int i = 0; i < factorial(MAXSIZE); i++)
    {


        for (int j = 0; j < MAXSIZE; j++)
        {
            arr[j] = arr2[j];
        }
        largPos = 0;
        smallVal = 0;


        for (int j = 0; j < MAXSIZE; j++)
        {
            printf("%d", arr2[j]);
        }
        printf("\n");

        largPos = largestValue(arr);               // find "i"
        smallVal = smallestValue(arr, largPos);    // find "aj"
        permcreator(arr, largPos, smallVal, arr2); // create new permutation


    }
return 0;
}

int largestValue(int arr[MAXSIZE])
{
    for (int i = MAXSIZE - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            return i;
        }
    }
    return -1;
}

int smallestValue(int arr[MAXSIZE], int largPos)
{
    int smallVal = 10000;
    for (int i = largPos + 1; i < MAXSIZE; i++)
    {
        if (arr[i] > arr[largPos] && smallVal > arr[i])
        {
            smallVal = arr[i];
        }
    }
    return smallVal;
}

void permcreator(int arr[MAXSIZE], int largPos, int smallVal, int arr2[MAXSIZE])
{
    int stop = 0;
    int holder = arr[largPos];
    int arr3[MAXSIZE - largPos - 1];
    arr2[largPos] = smallVal;
    for (int i = largPos + 1; i < MAXSIZE; i++)
    {
        if (arr2[i] == smallVal && stop == 0)
        {
            arr2[i] = holder;
            stop++;
        }
    }
    for (int i = 0; i < MAXSIZE - largPos - 1; i++)
    {
        arr3[i] = arr2[largPos + i + 1];
    }
    sort(arr3, MAXSIZE - largPos - 1);
    for (int i = 0; i < MAXSIZE - largPos - 1; i++)
    {
        arr2[largPos + i + 1] = arr3[i];
    }
}

void sort(int arr[MAXSIZE], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int factorial(int x)
{
    int result = 1;
    if(x==0){
        return 1;
    }
    else{
        for(int i = 2; i<=x; i++){
            result *= i;
        }
        return result;
    }
}