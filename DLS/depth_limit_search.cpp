#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;

int source, destination,L;
int depth[100];
vector<int>G[100];
bool visited[100];
bool found = false;

void DFS(int source )
{
    visited[source]=true;

    if(source==destination&&depth[source]==L){
        found=true;
        return ;

    }
    for(int v:G[source]){
        if(!visited[v]&&!found){
            depth[v]=depth[source]+1;
            DFS[v];
        }
    }
}




int main()
{
    int node,edges,i,x,y;
    printf("Enter the number of Node: ");
    scanf("%d",&node);
    printf("Enter the number of edge : ");
    scanf("%d",&edges);

    printf("Enter edge formate 'X'  'Y' \n");
    for(i=0;i<edges;i++){
     cin>>x>>y;
     G[x].push_back(y);
     G[y].push_back(x);
    }

    printf("enter the source : ");
    scanf("%d",&source);
    printf("Enter the destination :");
    scanf("%d",&destination);

    printf("Enter the limit : ");
    scanf("%d",&L);

    DFS(source);

    if(!found){

    printf("The destination node is not found .\n ");
    }
    else
        printf("The destination node is found .\n ");

}


