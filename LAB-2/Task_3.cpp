#include <iostream>
using namespace std;
void sort(int arr[],int size)
{
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size-i-1; j++)
		{
			if(arr[j]<arr[j+1]) {
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int secLargest(int arr[],int size)
{
	sort(arr,size);
	for (int i = 1; i < size; i++)
	{
		if (arr[i] != arr[0])
		{
			return arr[i];
		}
	}
	return -1;
}
int main() {
	int arr[5]= {1,6,36,7,56};
	cout<<"Original Array : ";
	for(int i=0; i<5; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int sec=secLargest(arr,5);
	if (sec != -1)
	{
		cout << "The Second Largest in Array is: " << sec << endl;
	}
	else
	{
		cout << "There is no distinct second largest element!" << endl;
	}

	return 0;
}
