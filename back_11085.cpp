#include <bits/stdc++.h>
#define maxtam 8
int con=0;
using namespace std;
int posicion[8];
int arr[maxtam];
int diagonal;
int contador;
int columna;
int reg,col;
int reves;
vector<int> vec;

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
		int p=0;
		for(int h = 0; h < maxtam; h++)			
		{
			if(arr[h] != posicion[h])
				p++;
		}
		vec.push_back(p);
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
	int uno;
	while(cin>>uno)
	{
	con++;
	uno--;
	posicion[0]=uno;

	for(int i=1; i<8; i++)
	{
		cin>>uno;
		uno--;
		posicion[i]=uno;
	}


	for(int i=0; i<8; i++)
	{
		columna = diagonal = reves = 0;
		memset(arr,0,sizeof(arr));
		reg=posicion[i];
		col=i;
		funcion(0);
		

	}
	int may=vec[0];
	for(int i=0; i<vec.size(); i++)
	{
		//cout<<vec[i]<<endl;
		if(vec[i]<may)
			may=vec[i];
	}
	//cout<<endl;
	cout<<"Case "<<con<<": "<<may<<endl;
	vec.clear();
		
		//columna |= (1<<col);
		//diagonal |= (1<<(reg+col));
		//reves |= (1<<(reg - col + 7));
	
}
}


			/*renglon=diagonal=reves=0;
			renglon |= (1<<posi[i]);
			diagonal |= (1<<(i+posi[i]));
			reves |= (1<<(posi[i]-i+7));*/