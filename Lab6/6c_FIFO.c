/*  FIFO page replacement */

#include<stdio.h>

main() 
{
    int i,j=0,len,rs[50],frame[10],nf,k,avail,count = 0;
    printf("Enter length of ref. string : ");
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
                break;
            }
        }
        if(!avail) {
            frame[j] = rs[i];
            j = (j+1)%nf;
            ++count;
            for(k = 0; k < nf; ++k) {
                printf("%4d ",frame[k]);
            }
        }
    }
    printf("\n\nTotal no. of page faults : %d\n",count);
}