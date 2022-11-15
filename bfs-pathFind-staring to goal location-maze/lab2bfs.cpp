/*Take a maze using 2D array as input. Each cell of the maze will fill up with either 0 or 1.
  1 means you can go that cell and 0 means block cell, you can not go there.
  While in a cell you can move up, down, right and left by 1 cell. take starting and goal location
  as input from user and find path from staring to goal location using BFS.
  for example starting location is 0,1 and end location in 3,3. your answer may like (0,1) -> (1,1)-> (2,2)->(3,3)*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

long mz[100][100];
int dir[4][4] = {{1,0},{-1,0},{0,1},{0,-1}};


struct node
{
    int x,y;
};
struct node queue[100], par[100][100];

bool bfs(int N, int M, int startx, int starty, int endx, int endy)
{
    int a=0, b=0, i;
    struct node cur, next;
    //pop
    cur.x = queue[b].x;
    cur.y = queue[b].y;
    b++;
    while(a < b)
    {
        cur = queue[a++];
        for(i = 0; i < 4; i++)
        {
            next.x = cur.x+dir[i][0];
            next.y = cur.y+dir[i][1];
            if(next.x>=0 && next.y>=0 && next.x<N && next.y<M && mz[next.x][next.y] == 1)
            {
                par[next.x][next.y].x = cur.x;
                par[next.x][next.y].y = cur.y;
                if(next.x == endx && next.y == endy)
                    return true;
                else
                {
                    mz[next.x][next.y] = 0;
                    queue[b++] = next;
                }
            }
        }
    }
    return false;
}

int main()
{
    int  N,M,i, j,startx,starty,endx, endy;

        cout<<" Please enter the ' N and M' : ";
        cin>>N>>M;
        printf("Enter table of maze : \n");
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < M; j++)
            {
                cin>>mz[i][j];

            }
        }
        cout<<"Enter starting Cell : ";
        scanf("%d%d", &startx, &starty);
        cout<<"Enter  Ending  Cell : ";
        scanf("%d%d", &endx, &endy);


        if(mz[startx][starty] == 0)
        {
            printf("no path found.\n");
        }
        else
        {
            if(bfs(N, M, startx, starty, endx, endy)==0){
               printf("no path found.\n");
             }
            else
            {
                int k = 0;
                queue[k].x = endx;
                queue[k++].y = endy;
                i = endx;
                j = endy;
                while(i!=startx || j!=starty)
                {
                    i = i;
                    j = j;
                    i = par[i][j].x;
                    j = par[i][j].y;
                    queue[k].x = i;
                    queue[k++].y = j;
                }
                    printf ("\n path is : ");
                    for(i = k-1; i >= 0; i--)
                    printf("(%d, %d)",queue[i].x,queue[i].y);
                    printf("\n");
                return 0;

            }

       }
}
