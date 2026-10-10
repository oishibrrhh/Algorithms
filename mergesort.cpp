#include<bits/stdc++.h>
using namespace std;

int arr[] = {8,5,2,9,1,3,7,4,6};
int n = sizeof(arr)/sizeof (arr[0]);
int ans[100];

void merge(int L,int mid,int H)
{
    int L1 = L;
    int L2 = mid + 1;
    int i = L;

    while(L1 <= mid && L2 <= H)
    {
        if(arr[L1] < arr[L2])
        {
            ans[i] = arr[L1];
            L1++;
            i++;
        }

        else
        {
            ans[i] = arr[L2];
            L2++;
            i++;
        }
    }

    while(L1 <= mid)
    {
        ans[i] = arr[L1];
        L1++;
        i++;
    }

    while(L2 <= H)
    {
        ans[i] = arr[L2];
        L2++;
        i++;
    }

    for(int i = L;i <= H;i++)
    {
        arr[i] = ans[i];
    }
    }

    void mergesort(int L,int H)
    {
        if(L <H)
        {

        int mid = (L + H)/2;
        mergesort(L,mid);
        mergesort(mid + 1,H);
        merge(L,mid,H);

        }
    else return;
    }

    int main()
    {
        mergesort(0, n - 1);

        for(int x : arr) cout<<x<<" ";
    }

