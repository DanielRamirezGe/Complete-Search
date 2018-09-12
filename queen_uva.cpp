#include <bits/stdc++.h>
#define maxtam 8

using namespace std;

int arr[maxtam];
int diagonal;
int contador;
int columna;
int reg,col;
int reves;

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

void funcion(int valor)
{
	if(valor == maxtam and arr[col] == reg)
	{
		printf("%2d      %d ",contador,arr[0]+1);
		for(int h = 1; h < maxtam; h++)
			if(h<maxtam-1)
			printf("%d ", arr[h]+1);
			else
				printf("%d", arr[h]+1);

		cout<<endl;
		contador++;
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
			arr[valor]=i;
			funcion(valor + 1);

			columna -= (1<<i);
			diagonal -= (1<<(i+valor));
			reves -= (1<<(i-valor+7));
		}

    }
}


int main()
{
	int casos;
	scanf("%i",&casos);

	for(int i=0; i < casos ; i++)
	{
		columna = diagonal = reves = 0;
		memset(arr,0,sizeof(arr));
		contador = 1;

		scanf("%d %d",&reg,&col);

		reg--; col--;
		//columna |= (1<<col);
		//diagonal |= (1<<(reg+col));
		//reves |= (1<<(reg - col + 7));
		cout<<"SOLN       COLUMN"<<endl;
		cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
		funcion(0);
		if(i<casos-1)
		cout<<endl;
	}
}