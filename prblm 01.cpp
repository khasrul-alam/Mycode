#include <stdio.h>
#include <stdlib.h>
void Merge(char arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    char L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(char arr[], int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        Merge(arr, l, m, r);
    }
}
void printArray(char A[], int Size)
{
    int i;
    for (i = 0; i < Size; i++)
        printf("%c ", A[i]);
    printf("\n");
}

void Swap(char* a, char* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int Partition (char arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++)
	{

		if (arr[j] < pivot)
		{
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}
	Swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quickSort(char arr[], int low, int high)
{
	if (low < high)
	{

		int pi = Partition(arr, low, high);


		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main()
{
    int n,i=0;
    char ch;
    scanf("%d",&n);
    getchar();
    char quickChar[n],mergeChar[n];
    for(i=0; i<n; i++)
    {
        scanf("%c",&ch);
        mergeChar[i]=ch;
        quickChar[i]=ch;
        getchar();
    }
    quickSort(quickChar, 0, n-1);
	printf("\nQuick sort=");
	printArray(quickChar, n);
    mergeSort(mergeChar, 0, n- 1);
    printf("\nMerge sort=");
    printArray(mergeChar,n);

	printf("\n");
    return 0;
}

