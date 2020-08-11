#include <bits/stdc++.h>
using namespace std;


int binarySearch(char arr[], int l, int r, char x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;


        if (arr[m] == x)
            return m;


        if (arr[m] < x)
            l = m + 1;


        else
            r = m - 1;
    }


    return -1;
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
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
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

int main(void)
{
    int n,i=0;
    char ch;
    scanf("%d",&n);
    getchar();
    char arr[n];
    for(i=0; i<n; i++)
    {
        scanf("%c",&ch);
        arr[i]=ch;
        getchar();
    }
    quickSort(arr, 0, n-1);
    cout<<"Input keys:";
    cin>>ch;
    int result = binarySearch(arr, 0, n - 1, ch);
    (result == -1) ? cout <<ch<<" is not found int the array"<<endl
                          : cout <<ch<<" is found int the array"<<endl;
    return 0;
}
