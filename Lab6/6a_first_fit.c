/* First fit allocation */

#include<stdio.h>

struct process
{
    int size, flag , holeid;
} p[10];

struct hole
{
    int size , actual;
} h[10];

main()
{
    int i, np, nh, j;
    printf("Enter the no. of holes : ");
    scanf("%d",&nh);
    for(i = 0 ;i < nh; ++i) {
        printf("\nEnter size for hole H%d : ",i);
        scanf("%d",&h[i].size);
        h[i].actual = h[i].size;
    }
    printf("\nEnter the no. of processes : ");
    scanf("%d",&np);
    for(i = 0 ;i < np; ++i) {
        printf("\nEnter size for Process P%d : ",i);
        scanf("%d",&p[i].size);
        p[i].flag = 0;
    }
    for(i = 0;i < np; ++i) {
        for(j = 0; j < nh; ++j) {
            if(!p[i].flag) {
                if(p[i].size <= h[j].size) {
                    p[i].flag = 1;
                    p[i].holeid = j;
                    h[j].size -= p[i].size;
                }
            }
        }
    }
    printf("\n\tFirst fit\n");
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
        printf("\nH%d\t%d\t%d", i , h[i].actual, h[i].size);
    }
    printf("\n");
}