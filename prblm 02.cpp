#include<bits/stdc++.h>
using namespace std;


int Partition (string arr[], int low, int high)
{
	string pivot = arr[high];
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


void quickSort(string arr[], int low, int high)
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
    cin>>n;
    string ara[n];
    for(i=0;i<n;i++)
        cin>>ara[i];

    quickSort(ara, 0, n-1);
    for(i=0;i<n;i++)
        cout<<ara[i]<<' ';

	printf("\n");
    return 0;
}

