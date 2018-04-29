#include<bits/stdc++.h>
using namespace std;
struct process
{
	int arr,bur,turn,wait,id,com,temp,prior;
};
bool comparator(process p1,process p2)
{
	if(p1.prior == p2.prior)
		return p1.arr < p2.arr;
	return p1.prior < p2.prior;
}
int main()
{
    int n;
    printf("Enter the no of processes in the ready queue : ");
    scanf("%d",&n);
    std::vector<process> p(n);
    for(int i = 0 ;i < n ; ++i) {
        printf("Enter the priority , arrival time and burst time of process %d : \n",i+1);
        scanf("%d%d%d",&p[i].prior,&p[i].arr,&p[i].bur);
        p[i].id = i+1;
        p[i].temp = p[i].bur;
    }
    sort(p.begin(), p.end(),comparator);
    /*for(int i = 0 ;i < n ; ++i) {
        cout << p[i].arr << " " << p[i].bur << " " << p[i].id << endl; 
    }*/
    int cur = 0 , left = n , i = 0;
    while(left > 0) 
    {
    	int i = 0;
    	for(; i < n ; ++i) 
    	{
    		if(p[i].arr <= cur && p[i].bur > 0)
    		{
    			cur++;
    			p[i].bur--;
    			if(p[i].bur == 0)
    			{
    				p[i].com = cur;
    				left--;
    			}
    			break;
    		}
    	}
    	if(i == n && left > 0)
    	{
    		++cur;
    	}
    }
    for(int i = 0;i<n;++i)
    {
    	p[i].turn = p[i].com - p[i].arr;
    	p[i].wait = p[i].turn - p[i].temp;
    }
    printf("P_NO.\tPri\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0 ; i < n ; ++i)
    {
    	cout << p[i].id << "\t" << " " << p[i].prior  << "\t" << p[i].arr << "\t" << p[i].temp << "\t" << p[i].com << "\t" << p[i].turn << "\t" << p[i].wait << endl;
    }
    cout << endl;
}