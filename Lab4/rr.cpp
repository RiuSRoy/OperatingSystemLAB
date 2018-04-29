#include<bits/stdc++.h>
#define tq 2
using namespace std;
struct process
{
	int arr,bur,turn,wait,id,com,temp;
};
bool comparator(process p1,process p2)
{
	return p1.arr < p2.arr;
}
int main()
{
    int n;
    printf("Enter the no of processes in the ready queue : ");
    scanf("%d",&n);
    std::vector<process> p(n);
    for(int i = 0 ;i < n ; ++i) {
        printf("Enter the arrival time and burst time of process %d : \n",i+1);
        scanf("%d%d",&p[i].arr,&p[i].bur);
        p[i].id = i+1;
        p[i].temp = p[i].bur;
    }
    sort(p.begin(), p.end(),comparator);
    /*for(int i = 0 ;i < n ; ++i) {
        cout << p[i].arr << " " << p[i].bur << " " << p[i].id << endl; 
    }*/
    int cur = 0 , left = n , i = 0 , not_getting_chance = 0;
    while(left > 0) 
    {
    	if(cur >= p[i].arr)
    	{
    		if(p[i].bur > 0)
    		{
    			if(p[i].bur >= tq)
    			{
    				p[i].bur -= tq;
    				cur += tq;
    				if(p[i].bur == 0)
    				{
    					p[i].com = cur;
    					p[i].bur = -1;
    					--left;
    				}
    			}
    			else
    			{
    				cur += p[i].bur;
    				p[i].bur = -1;
    				p[i].com = cur;
    				--left;
    			}
    		}
    	}
    	else
    	{
    		++not_getting_chance;
    	}
    	i = (i+1)%n;
    	if(not_getting_chance == left)
    	{
    		not_getting_chance = 0;
    		++cur;
    	}
    }
    for(int i = 0;i<n;++i)
    {
    	p[i].turn = p[i].com - p[i].arr;
    	p[i].wait = p[i].turn - p[i].temp;
    }
    printf("P_NO.\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0 ; i < n ; ++i)
    {
    	cout << p[i].id << "\t" << p[i].arr << "\t" << p[i].temp << "\t" << p[i].com << "\t" << p[i].turn << "\t" << p[i].wait << endl;
    }
    cout << endl;
}