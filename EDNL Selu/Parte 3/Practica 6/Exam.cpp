#include<iostream>
#include"alg_grafoPMC.h"

using namespace std;

template <typename tCoste>
void Opciona(const vector<bool>& Ciu,const matriz<bool>& Carr,const GrafoP<tCoste>& G);
template <typename tCoste>
void Opcionb(const vector<bool>& Ciu,const matriz<bool>& Carr,const typename GrafoP<tCoste>::vertice Capital,const GrafoP<tCoste>& G);

int main()
{
	string a="Zuelandia.txt";
	GrafoP<int> G(a);

	//Ciudades ocupadas:
	vector<bool> Ciu(G.numVert(),false);
	Ciu[6]=true;	//Ciudad 6 ocupada.
	//Carreteras ocupadas.
	matriz<bool> Carr(G.numVert(),false);
    Carr[0][4]=true;
    Carr[1][4]=true;
    Carr[0][1]=true;

	cout << "El grafo es: " << endl;
	cout << G << endl;
    typedef typename GrafoP<int>::vertice vertice;
    vertice Capital=0;

	//Opciona(Ciu,Carr,G);
    Opcionb(Ciu,Carr,Capital,G);
	return 0;
}

template <typename tCoste>
void Opciona(const vector<bool>& Ciu,const matriz<bool>& Carr,const GrafoP<tCoste>& G)
{
	GrafoP<tCoste> M(G);
	for(size_t i=0;i<G.numVert();i++)
	{
		for(size_t j=0;j<G.numVert();j++)
		{
			if(Ciu[i]==true)
			{
				M[i][j]=GrafoP<tCoste>::INFINITO;
				M[j][i]=GrafoP<tCoste>::INFINITO;
			}
			if(Carr[i][j]==true || Carr[i][j]==true)
			{
				M[i][j]=GrafoP<tCoste>::INFINITO;
				M[j][i]=GrafoP<tCoste>::INFINITO;
			}
		}
	}
	cout << "El Grafo queda: " << endl;
	cout << M << endl;

	cout << "Calculamos la distancia de todos a todos (Floyd): " << endl;
	typedef typename GrafoP<tCoste>::vertice vertices;
	matriz<vertices> X(G.numVert());
	matriz<tCoste> R=Floyd(M,X);
	for(size_t i=0;i<G.numVert();i++)
	{
		for(size_t j=0;j<G.numVert();j++)
		{
			cout << R[i][j] << "   ";
		}
		cout << endl;
	}
}

template <typename tCoste>
void Opcionb(const vector<bool>& Ciu,const matriz<bool>& Carr,const typename GrafoP<tCoste>::vertice Capital,const GrafoP<tCoste>& G)
{
	GrafoP<tCoste> M(G);
	for(size_t i=0;i<G.numVert();i++)
	{
		for(size_t j=0;j<G.numVert();j++)
		{
			if(Ciu[i]==true)
			{
				M[i][j]=GrafoP<tCoste>::INFINITO;
				M[j][i]=GrafoP<tCoste>::INFINITO;
			}
			if(Carr[i][j]==true || Carr[i][j]==true)
			{
				M[i][j]=GrafoP<tCoste>::INFINITO;
				M[j][i]=GrafoP<tCoste>::INFINITO;
			}
		}
	}

	typedef typename GrafoP<tCoste>::vertice vertices;
	vector<vertices> X(G.numVert());
	vector<tCoste> alaCapital=DijkstraInv(M,Capital,X);
	vector<tCoste> delaCapital=Dijkstra(M,Capital,X);

	for(size_t i=0;i<G.numVert();i++)
	{
		for(size_t j=0;j<G.numVert();j++)
		{
			if(i==j)
			{
				M[i][j]=0;
			}else
			{
				M[i][j]=suma(alaCapital[i],delaCapital[j]);
			}
		}
	}

	cout << "Pasando por la capital Grafo queda: " << endl;
	cout << M << endl;

	cout << "Calculamos la distancia de todos a todos (Floyd): " << endl;
	matriz<vertices> XM(G.numVert());
	matriz<tCoste> R=Floyd(M,XM);
	for(size_t i=0;i<G.numVert();i++)
	{
		for(size_t j=0;j<G.numVert();j++)
		{
			if(R[i][j]!=GrafoP<tCoste>::INFINITO){
				cout << R[i][j] << "   ";
			}else
			{
				cout << "X" << "   "; 
			}
		}
		cout << endl;
	}

}
