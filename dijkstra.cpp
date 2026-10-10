#include<bits/stdc++.h>
using namespace std;
#define A pair <int,int>
#define INF 999
vector<pair<int,int>>adj_list[100];

int cost[100];
int parent[100];

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

void dijkstra(int s)
{
    for(int i = 0; i < 100;i++)
    {
        cost[i] = INF;
    }

    cost[s] = 0;
    parent[s] = s;
    pq.push({cost[s],s});

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();


    for(int i = 0;i < adj_list[u].size();i++)
    {
        int v = adj_list[u][i].first;
        int weight = adj_list[u][i].second;

        if(cost[u] + weight < cost[v])
        {
            cost[v] = cost[u] + weight;
            parent[v] = u;
            pq.push ({cost[v],v});
        }

      }

   }

 }

main()
{
    int n,e;
    cin>>n>>e;
    for(int i = 0;i < e;i++);
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v,w});

        int source,dest;
        cin>>source>>dest;

        dijkstra(source);
        cout<<cost[dest]<<" ";

        vector<int>path;
        int now = dest;
        path.push_back(dest);

        while(parent[now] != now)
        {
            now = parent[now];
            path.push_back(now);
        }

        reverse(path.begin(),path.end());

            for(auto x : path)
            {
                cout<<x<<endl;
            }


        cout<<endl;

    }
}
































