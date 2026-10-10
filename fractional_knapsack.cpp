#include<bits/stdc++.h>
using namespace std;

struct product
{
    int profit;
    int weight;
    double u_profit;
};

bool cmp(product a,product b)
{
    return(a.u_profit > b.u_profit);
}

double fractional_knapsack(product prod[],int n,int w)
{
    sort(prod,prod + n,cmp);
    double profit = 0;

    for(int i = 0; i < n; i++)
    {
        if(w >= prod[i].weight)
        {
            w -= prod[i].weight;
            profit += prod[i].profit;
        }

        else
        {
            profit += (double(w) / prod[i].weight)*prod[i].profit;
            break;
        }
        return profit;
    }
}

int main()
{
    int W = 15;
    double p[] = {12,9,11,8,14};
    int w[] = {7,4,2,6,4};
    int n = sizeof(w)/sizeof(w[0]);

    product prod[n];
    for(int i = 0; i < n;i++)
    {
        prod[i].weight = w[i];
        prod[i].profit = p[i];
        prod[i].u_profit = (p[i]/w[i]);

    }

    double ans = fractional_knapsack(prod,n,W);
    cout<<ans<< " ";
}





