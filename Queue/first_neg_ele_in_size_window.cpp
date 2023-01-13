#include<iostream>
using namespace std;


void negative(int arr[],int n,int k)
{
    for(int i = 0; i < (n-k+1);i++)
    {
        bool flag=false;
        for(int j = 0 ; j < k ;j++)
        {
            if(arr[i +  j] < 0)
            {
                cout<<arr[i + j]<<" ";
                flag  =true;
                break;
            }
        }
        if(flag == false)
        {
            cout<<"0"<<" ";
        }
    }
}
int main()
{
    int arr[]={-8,2,3,-6,10};
    int n  = sizeof(arr)/sizeof(arr[0]);
    int k =2;
    negative(arr,n,k);
}