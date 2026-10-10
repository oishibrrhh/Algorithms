#include<bits/stdc++.h>
using namespace std;
vector<int>v;

double knapsack(int k,int n,int p[],int w[])
{
    int mat[n + 1][k + 1] ={0};
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k ; j++)
        {
            if(i == 0 || j == 0)
            {
                mat[i][j] = 0;
            }

            else if(j >= w[i - 1])
            {
               mat[i][j] = max(p[i - 1] + mat[i - 1][j - w [i - 1]],mat[i - 1][j]);

            }

            else
            {
                mat[i][j] = mat[i - 1][j];
            }
        }
    }

    int i = n,j = k;

    while(i > 0 && j > 0)
    {
        if(mat[i][j] = mat[i -1][j])
        {
            v.push_back(i - 1);

            j -= w[i -1];

        }
    }

        i--;
        return mat[n][k];

}

int main()
{

int w[] = {3,5,9,6,2};
int p[] = {14,7,9,11,5};
int n = sizeof(w)/sizeof(w[0]);
int W = 15;

double maxprofit = knapsack(n,W,w,p);
cout<<maxprofit<<"\n";

for(int x : v)
{
    cout<<x<<endl;
}

}

