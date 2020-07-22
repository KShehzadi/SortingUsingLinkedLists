#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
using namespace std;
int arr[20000];
int temp[20000];
void print(int* arr,int length);
void MergeSort(int* arr, int low, int high);
int* BubbleSort(int* A, int length);
int* InsertionSort(int* A, int length);
int* SelectionSort(int* A, int length);
void MergeSort(int *a, int low, int high);
void Merge(int *a, int low, int high, int mid);
int main()
{
  ifstream infile, infile2;
  infile.open("data10Ka.txt");
  infile2.open("data20Ka.txt");
  char c;
  int i = 0;
  int j, k = 0, p = 0;
  int h = 0;
  infile.get(c);
  while(!infile.eof())
  {
    if(c == '\n')
    {
      arr[i] = k;
      h++;
      k = 0;
      i++;
    }
    else
    {
      p++;
      j = (int)c;
      j = j - 48;
      k = k*10 + j;
    }
    infile.get(c);
  }
int clo = clock();
//time_t t1, t2;
//t1 = time(NULL);
BubbleSort(arr, h);
//t2 = time(NULL);
//cout<< t2-t1;
cout<< (clock() - clo);
}
void print(int* arr,int length)
{
  for(int i = 0; i < length; i++)
  {
    cout<<arr[i];
    cout<<' ';
  }
  cout<<endl;
}
void Merge(int *a, int low, int high, int mid)
{
	int i, j, k;
	i = low;
	k = 0;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}


void MergeSort(int *a, int low, int high)
{
	int mid;
  mid=(low+high)/2;
	if (low < high)
	{

		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low, high, mid);
	}
}
int* BubbleSort(int* A, int length)
{
  for(int i = length - 1; i > 0; i--)
  {
    for(int j = 0; j < i; j++)
    {
      if(A[j] > A[j + 1])
      {
        int temp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = temp;
      }
    }
  }
  return A;
}
int* InsertionSort(int* A, int length)
{
  for(int i = 1; i < length; i++)
  {
    int item = A[i];
    int j = i - 1;
    while(A[j] > item)
    {
      A[j + 1] = A[j];
      j--;
      if(j < 0)
      {
        break;
      }
    }
    A[j + 1] = item;
  }
  return A;
}
int* SelectionSort(int* A, int length)
{
  int i;
  int j;
  int k;
  int n1 = length - 1;
  int smallest;

  for(i = 0; i < n1; i++)
  {
    k = i;
    smallest = A[i];
    for(j = i + 1; j < length; j++)
    {
      if(smallest > A[j])
      {
        k = j;
        smallest = A[k];
      }
    }
    A[k] = A[i];
    A[i] = smallest;
  }
  return A;
}
