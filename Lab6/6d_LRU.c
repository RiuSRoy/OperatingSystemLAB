// LRU

#include<stdio.h>

int getMin(int a[],int n)
{
    int i,min = a[0] ,pos = 0;
    for(i = 1; i < n ; ++i) {
        if(min > a[i]) {
            min = a[i];
            pos = i;
        }
    }
    return pos;
}

main()
{
    int i,j = 0,len,rs[50],frame[10],nf,k,avail,count = 0;
    int access[10] , freq = 0 , dm;
    printf("Length of Reference String : ");
    scanf("%d",&len);
    printf("Enter reference string : \n");
    for(i = 1; i <= len; ++i) {
        scanf("%d",&rs[i]);
    }
    printf("Enter no. of frames : ");
    scanf("%d",&nf);
    for(i = 0; i < nf ;++i) {
        frame[i] = -1;
    }
    printf("\nRef. str\t Page frames\n");
    for(i = 1; i<= len ;++i) {
        printf("\n%d\t\t",rs[i]);
        avail = 0;
        for(k = 0; k < nf; ++k) {
            if(frame[k] == rs[i]) {
                avail = 1;
                access[k] = ++freq;
                break;
            }
        }
        if(!avail) {
            dm = 0;
            for(k = 0; k < nf; ++k) {
                if(frame[k] == -1) {
                    dm = 1;
                    break;
                }
            }
            if(dm) {
                frame[k] = rs[i];
                access[k] = ++freq;
                ++count;
            }
            else {
                j = getMin(access,nf);
                frame[j] = rs[i];
                access[j] = ++freq;
                ++count;
            }
            for(k = 0; k < nf; ++k) {
                printf("%4d ",frame[k]);
            }
        }
    }
    printf("\n\nTotal no. of page faults : %d\n",count);
}