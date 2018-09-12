#include <bits/stdc++.h>
using namespace std;
int num;
int con,m;

void fun(int arr[]);
int main()
{
	int aca[51];
	memset(aca,-1,sizeof(aca));
	int casos;
	scanf("%d",&casos);
	for(int i=0; i<casos; i++)
	{
		cin>>num;
		m=0;
		con=0;
		int arr[num];
		memset(arr,-1,sizeof(arr));
		if(aca[num]==-1)
		{
			fun(arr);
			aca[num]=m-1;
			cout<<aca[num]<<endl;
		}
		else
			cout<<aca[num]<<endl;

		
	}
}

void fun(int arr[])
{
	con++;
	if(con>m)
		m=con;
	for(int i=0; i<num; i++)
	{
		if(arr[i]==-1)
		{
			int a=arr[i];
			arr[i]=con;
			fun(arr);
			arr[i]=a;
			break;	
		}
		else
		{
			double d=sqrt(arr[i]+con	);
			if(d-(int)sqrt(arr[i]+con)==0)
				{
					int a=arr[i];
					arr[i]=con;
					fun(arr);
					arr[i]=a;
					break;
				}

		}
	}
	con--;
}