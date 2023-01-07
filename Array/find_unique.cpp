#include<iostream>
#include<vector>
using namespace std;
void find_unique(int arr[],int n)
{
    vector<int>result;
    for(int i=0;i<n;i++)
    {
        int count = 0;
        for(int j = 0; j < n;j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }
        if(count == 1){
            result.push_back(arr[i]);
        }
    }

cout<<"size="<<result.size()<<endl;
    for(int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
}
int main()
{
    int arr[]={1,1,2,3,2,4,5,4,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    find_unique(arr,size);
}