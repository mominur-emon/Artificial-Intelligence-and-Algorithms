#include<stdio.h>
#include<math.h>

struct myQueue{
    int x, y;
    double g, h, f ;
    bool flag ;
}Q[100], temp, par[100][100], dest;

bool w = false;
int grid[100][100];
double heuristicCost[100][100], dis[100][100] ;

void initialization(int n, int m, int stri, int strj)
{
    int k = 0 ;
    dis[stri][strj] = 0.0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            Q[k].x = i ;
            Q[k].y = j ;
            Q[k].g = dis[i][j] ;
            Q[k].h = heuristicCost[i][j] ;
            Q[k].f = Q[k].g + Q[k].h ;
            Q[k].flag = true ;
            k++ ;
        }
    }
}

bool isEmpty(int n, int m){
    for(int i = 0 ; i < n*m ; i++){
        if(Q[i].flag)
		return false ;
    }
    return true ;
}

int pop(int n, int m){
    int min = 1000000 ;
    int index ;
    for(int i = 0 ; i < n*m ; i++){
        if(Q[i].f < min && Q[i].flag == true){
            min = Q[i].f ;
            index = i ;
        }
    }

    Q[index].flag = false ;
    return index ;
}


void updateQueueCost(int i, int j, double cost, int n, int m){
    for(int k = 0 ; k < n*m ; k++){
        if(Q[k].x == i && Q[k].y == j){
            Q[k].g = cost ;
            Q[k].f = Q[k].g + Q[k].h ;
        }
    }
}


void aStarSearch(int n, int m){
    int drxi[] = {-1, 0, 0, 1};
    int drxj[] = {0, -1, 1, 0};



    while(!isEmpty(n, m)){
        int index = pop(n,m) ;
        temp = Q[index] ;
        int i = temp.x ;
        int j = temp.y ;
        int p = i;
        int q = j;
        for(int a=0;a<4;a++){
            p = i + drxi[a];
            q = j + drxj[a];
            if(grid[p][q] > -1){
            if(dis[p][q] > dis[i][j] + grid[p][q]){
                dis[p][q] = dis[i][j] + grid[p][q] ;
                updateQueueCost(p, q, dis[p][q], n, m) ;
                par[p][q]=temp;
             if(p==dest.x && q== dest.y){
                        w = true;
                        break;
                    }
                }

            }
        }

    }
}


  void pathPrint(int src1,int src2, int dest1, int dest2){
    if(src1==dest1 && src2==dest2){
        printf("\n(%d,%d) ",dest1, dest2);
        return;
    }
    pathPrint(src1 ,src2, par[dest1][dest2].x, par[dest1][dest2].y);
    printf("(%d,%d)  ",dest1, dest2);
    return;
}


int main()
{
    int n, m, i , j ,stri, strj;

    scanf("%d %d", &n, &m) ;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            scanf("%d", &grid[i][j]) ;
        }
    }

    scanf("%d %d", &stri, &strj) ;
    scanf("%d %d",&dest.x,&dest.y);

    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            heuristicCost[i][j] = sqrt(pow((1.00*dest.x-i),2)+pow((1.00*dest.y-j),2)) ;
            dis[i][j] = 99999.00 ;
        }
    }
    /*for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            printf("%.2lf ", heuristicCost[i][j]) ;
        }
        printf("\n") ;
    }*/
    initialization(n, m, stri, strj) ;
    aStarSearch(n, m) ;
    if(w == false)
        printf("not found");
    else{
        printf("\nPath : ");
        pathPrint(stri, strj, dest.x, dest.y);
    }

}



/*

6
6

10  4   -1  5   5   6
1   20  -1  6   6   6
7   18  -1  12  12  7
28  7   -1  8   10  27
30  5    5  7   7   10
25  25  -1  8   8   8

0 0 5 5

*/
