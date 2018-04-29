/* Best fit */

#include<stdio.h>

struct process
{
    int size, flag , holeid;
} p[10];

struct hole
{
    int size , actual , hid;
} h[10];

void bsort(struct hole bh[] , int n)
{
    struct hole temp;
    int i,j;
    for(i=0;i<n-1;++i) {
        for(j = i+1 ; j < n ;++j) {
            if(bh[i].size > bh[j].size) {
                temp = bh[i];
                bh[i] = bh[j];
                bh[j] = temp;
            }
        }
    }
}

main()
{
    int i,np,nh,j;
    printf("Enter the no. of holes : ");
    scanf("%d",&nh);
    for(i = 0 ;i < nh; ++i) {
        printf("\nEnter size for hole H%d : ",i);
        scanf("%d",&h[i].size);
        h[i].actual = h[i].size;
        h[i].hid = i;
    }
    printf("\nEnter the no. of processes : ");
    scanf("%d",&np);
    for(i = 0 ;i < np; ++i) {
        printf("\nEnter size for Process P%d : ",i);
        scanf("%d",&p[i].size);
        p[i].flag = 0;
    }
    for(i = 0;i < np; ++i)   {
        bsort(h,nh);
        for(j = 0; j < nh ; ++j) {
            if(!p[i].flag) {
                if(p[i].size <= h[j].size) {
                    p[i].flag = 1;
                    p[i].holeid = h[j].hid;
                    h[j].size -= p[i].size;
                }
            }
        }
    } 
    printf("\n\tBest fit\n");
    printf("\nProcess\tPSize\tHole");
    for(i = 0; i<np; ++i) {
        if(!p[i].flag) {
            printf("\nP%d\t%d\tNot allocated",i,p[i].size);
        }
        else {
            printf("\nP%d\t%d\tH%d",i , p[i].size,p[i].holeid);
        }
    } 
    printf("\n\nHole\tActual\tAvailable");
    for(i = 0; i < nh ; ++i) {
        printf("\nH%d\t%d\t%d", h[i].hid , h[i].actual, h[i].size);
    }
    printf("\n");
}