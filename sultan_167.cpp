#include <bits/stdc++.h>
#define maxtam 8
using namespace std;
int mayor=0;
int mat [maxtam][maxtam];
int diagonal;
int contador;
int columna;
int reg,col;
int reves;
int resultado=0;
int arr[8];
bool storbo(int i, int valor)
{
    //printf("%i %i %i\n",columna,diagonal,reves);
    if(columna & (1<<i))
        return false;
    if(diagonal & (1<<(i+valor)))
        return false;
    if(reves & (1<<(i-valor+7)))
       return false;
    return true;
}

void funcion(int valor,int pos)
{

	if(valor == maxtam and arr[col] == reg)
	{
		//cout<<resultado<<endl;
		//cout<<" pos: "<<pos<<" valor: "<<valor<<endl;
		//cout<<mat[pos][valor]<<"  tot: "<<resultado<<endl;
		if(mayor<resultado)
			mayor=resultado;
		return;
	}
	for(int i = 0; i < maxtam; i++)
    {
		if(storbo(i,valor))
		{
		    //printf("algo\n");
			columna |= (1<<i);
			diagonal |= (1<<(i+valor));
			reves |= (1<<(i-valor+7));
			resultado+=mat[valor][i];
			arr[valor]=i;

			funcion(valor + 1,pos);
			resultado-=mat[valor][i];
			columna -= (1<<i);
			diagonal -= (1<<(i+valor));
			reves -= (1<<(i-valor+7));
		}

    }
}

int main()
{
	int casos;
	int num;
	cin>>casos;

	for(int e=0; e<casos; e++)
	{
		for(int i=0; i<8;i++ )
			for(int j=0; j< 8; j++)
			{
				scanf("%d",&num);
				//cout<<num<<" ";
				mat[i][j]=num;
			}
		for(int j=0; j<8; j++)
		{
			columna = diagonal = reves = 0;
			//resultado=0;
			//mayor=0;
			memset(arr,0,sizeof(arr));
			resultado=0;
			reg=j;
			col=0;
			funcion(0,j);

		}
		printf("%5d\n",mayor);
		mayor=0;
	}
}