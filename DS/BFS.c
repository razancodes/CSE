#include <stdio.h>

int bfs(int a[20][20], int n, int src, int t[20][2], int s[]){
    int q[20], f=0,r=0,k=0,u,v;
    q[r]=src;
    s[src]=1;
    while (f<=r){
        u=q[f++];
        for (v=0;v<n;v++){
            if (a[u][v]==1 && s[v]!=1){
                s[v]=1;
                q[++r]=v;
                t[k][0]=u;
                t[k][1]=v;
                k++;
            }
        }
    }
    return k;
}

int main(){
    int a[20][20]={{1,1,1},
                    {1,0,0},
                    {0,1,0}};
    int a1[20][20] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 1},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0}
    };
    int n=5,src=2;
    int t[20][2]={0};
    int s[20]={0};
    int k=bfs(a1,n,src,t,s);
    // for (int i=0;i<n;i++){
    //     if (s[i]==0){
    //         printf("%d is not reachable.\n", i);
    //     }else{
    //         printf("%d is reachable. \n",i);
    //     }
    // }
    printf("bfs traversal\n");
    for (int i=0;i<k;i++){
        printf(" %d -> %d ",t[i][0],t[i][1]);
    }
    printf("done");
    return 0;
}
