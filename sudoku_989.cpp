#include<bits/stdc++.h>
using namespace std;
int todo;
int num;
int i,j;
int mat[15][15];
int ban=0;
int ind=0;
bool s(int uno, int dos)
{
	if(~uno & (1<<(dos)))
        return true;
    return false;
}
bool ll(int n, int renglon,int columna,int cuadro)
{
	if( s(renglon,n) and s(columna,n) )
		return true;
	return false;
}
void llena(int n, int renglon, int columna, int cuadro)
{

	if(ban==1)
		return;
	if(mat[i-1][ind]!=0)
	{
		cout<<mat[i-1][ind]<<" indi: "<<ind<<" n: "<<n<<endl;
		for(; ind<num*num;)
		{
			cout<<mat[i-1][ind]<<" indi: "<<ind<<" n: "<<n<<endl;
			ind++;
			if(mat[i-1][ind]!=0)
				break;
		}
		cout<<endl;
	}
		if(ll(n,renglon,columna,cuadro))
		{
			for(int h=0; h<num*num; h++)
			{
				for(int g=0; g<num*num-1; g++)
					cout<<mat[h][g]<<" ";
				cout<<mat[h][num*num-1]<<endl;
			}
			cout<<"n "<<n<<" i: "<<i<<" j: "<<j<<" ind: "<<ind<<endl;
			renglon|=1<<n;
			columna|=1<<n;
			cuadro|=1<<n;
			mat[i-1][ind]=n;
			ind++;
			if(i==num*num)
			{

				if(renglon==todo-1 and columna==todo-1 and cuadro==todo-1)
					{
						for(int h=0; h<num; h++)
						{
							for(int g=0; g<num-1; g++)
								cout<<mat[h][g]<<" ";
							cout<<mat[h][num-1]<<endl;
						}
					ban=1;
					
					}
					renglon-=1<<n;
					columna-=1<<n;
					cuadro-=1<<n;
					mat[i-1][j-1]=0;
					ind--;
					return;
			}
			for(int h=1; h<=num*num; h++)
			{
				
				if(ll(h,renglon,columna,cuadro))
					llena(h,renglon,columna,cuadro);
			}
			renglon-=1<<n;
			columna-=1<<n;
			cuadro-=1<<n;
			mat[i-1][ind]=0;
			ind--;
		}
	
}
int main()
{

	cin>>num;
	int columna[num*num];
	int renglon[num*num];
	int cuadro[num*num];
	memset(mat,0,sizeof(mat));
	memset(columna,0,sizeof(columna));
	memset(columna,0,sizeof(columna));
	memset(renglon,0,sizeof(renglon));
	memset(cuadro,0,sizeof(cuadro));
	int dat;
	todo=0;
	todo|=(1<<(num+1))-1;
	
	for(i=1; i<=num*num; i++)
	{
		ind=0;
		for(j=1; j<=num*num; j++)
			{	
				scanf("%d",&dat);
				if(num!=0)
				{
					renglon[i]|=1<<dat;
					columna[j]|=1<<dat;
					cuadro[(i/num)+(j/num)]|=1<<dat;
					mat[i-1][j-1]=dat;
				}
			}

	}

	for(i=1; i<=num*num; i++)
	{
		
		for(j=1; j<=num*num; j++)
			if(ll(j,renglon[i],columna[j],cuadro[(i/num)+(j/num)]))
				{

					llena(j,renglon[i],columna[j],cuadro[(i/num)+(j/num)]);
				}
		
	}
	for(int h=0; h<num*num; h++)
	{
		for(int g=0; g<num*num-1; g++)
			cout<<mat[h][g]<<" ";
		cout<<mat[h][num*num-1]<<endl;
	}
}