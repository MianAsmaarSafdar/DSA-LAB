#include <iostream>
using namespace std;
int main() {
	int arr[3][3];
	int sum=0;
	cout<<"Enter elements in 2D-array :";
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cin>>arr[i][j];
		}
	}
	cout<<endl;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			sum+=arr[i][j];
		}
	}
	cout<<"Sum ="<<sum<<endl;
	return 0;
}
