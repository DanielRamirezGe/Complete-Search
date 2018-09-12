#include<bits/stdc++.h>
using namespace std;
int main()
{
	int casos;
	cin>>casos;
	for(int i=0; i<casos; i++)
	{
		int partes;
		string nombre;
		int bajo,alto;
		vector<pair<int,pair<int,string>>> menor;
		//vector<pair<int,string>> mayor;
		pair<int,pair<int,string>> aux;
		cin>>partes;
		for(int h=0; h<partes; h++)
		{
			cin>>nombre;
			cin>>bajo;
			aux.first=bajo;
			aux.second.second=nombre;
			
			cin>>alto;
			aux.second.first=alto;
			menor.push_back(aux);
			

		}
		int consultas;
		cin>>consultas;
		sort(menor.begin(),menor.end());
		//sort(mayor.begin(),mayor.end());

		int pres;
		for(int k=0; k<consultas; k++)
		{
			cin>>pres;
			/*if(pres>mayor[mayor.size()-1].first || pres<menor[0].first)
				cout<<"UNDETERMINED   doooo"<<endl;
			else
				{*/
					int ban=0;
					string pal;
					for(int m=0; m<partes; m++)
					{
						//cout<<menor[m].second<<" "<<menor[m].first<<" "<<mayor[m].first<<endl;
						if(pres>=menor[m].first and pres<=menor[m].second.first)
							{
								pal=menor[m].second.second;
								ban++;
							}
						else
							{
								/*if(pres>mayor[m].first||pres<menor[m].first)
									break;*/
							}
					}
					if(ban==0|| ban>1)
					{
						cout<<"UNDETERMINED"<<endl;
					}
					else
					{
						
						cout<<pal<<endl;
					}
				//}
		}
		if(i!=casos-1)
		cout<<endl;
	}
}