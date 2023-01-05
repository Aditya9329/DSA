#include<iostream>
using namespace std;
void left_rotate(int arr[],int n,int d)
{
    int new_arr[n];
    int k=0;
    for(int i=d;i<n;i++)
    {
        new_arr[k]=arr[i];
        k++;
    }
    

    for(int i=0;i<d;i++)
    {
        new_arr[k] = arr[i];
        k++;
    }

    cout<<"rotated array:"<<endl;
    for(int p = 0 ;p<n;p++)
    {
        cout<<new_arr[p]<<" ";
    }

   
}
int main()
{
    int arr[5]={1,2,3,4,5};
    int d=2;
    int size = sizeof(arr)/sizeof(arr[0]);
    left_rotate(arr,size,d);
}