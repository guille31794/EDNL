#include"grafoMA.cpp"
#include"alg_grafoMA.cpp"
#include"grafoPMC.h"
#include"alg_grafoPMC.h"
#include"particion.cpp"
#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

struct Coor{
	double x,y;
	Coor(double x_=0.,double y_=0.):x(x_),y(y_){}
};

//Ejercicio 1.
void Ejercicio1();
void inicializar(vector<Coor>& C);
void hacer(const vector<Coor>& C,const Grafo& Gr);
int dis_euclid(Coor C1,Coor C2);
//Ejercicio 2.
void Ejercicio2();
void hacer2(const vector<Coor>& C,const Grafo& Gr);
//Ejercicio 3.
void Ejercicio3();
template <typename tCoste>
void Gmaximo(const GrafoP<tCoste>& G);
//Ejercicio 4.
void Ejercicio4();
template <typename tCoste>
void Gmaximo2(const GrafoP<tCoste>& G);
//Ejercicio 5.
void Ejercicio5();
template <typename tCoste>
tCoste GMinimo(const GrafoP<tCoste>& G);
//Ejercicio 7.
void Ejercicio7();
void inicializar2(vector<Coor>& C);
template <typename tCoste>
void hacer7(const vector<Coor>& C,const vector<tCoste>& Cost1,const vector<tCoste>& Cost2,const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2);

int main()
{
	Ejercicio7();
	return 0;
}

//Ejercicio 1.
void Ejercicio1()
{
	string a="Tombuctu1.txt";
	GrafoP<int> G(a);
	Grafo Gr(G);

	cout << "Grafo Matriz de Costes:" << endl;
	cout << G << endl;
	cout << "Grafo Matriz de Adyacencia:" << endl;
	cout << Gr << endl;

	vector<Coor> C(G.numVert());
	inicializar(C);
	hacer(C,Gr);
}

void inicializar(vector<Coor>& C){
    //Isla 1:
    C[0].x=0;
    C[0].y=5;
    C[1].x=3;
    C[1].y=5;
    C[2].x=0;
    C[2].y=0;
    C[3].x=3;
    C[3].y=0;
    //Isla 2:
    C[4].x=7;
    C[4].y=4;
    C[5].x=10;
    C[5].y=3;
    C[6].x=8;
    C[6].y=2;
    C[7].x=6;
    C[7].y=0;
    //Isla 3:
    C[8].x=13;
    C[8].y=6;
    C[9].x=15;
    C[9].y=6;
    C[10].x=13;
    C[10].y=2;
    C[11].x=15;
    C[11].y=2;
    C[12].x=14;
    C[12].y=0;
}

void hacer(const vector<Coor>& C,const Grafo& Gr)
{
	GrafoP<int> G(Gr.numVert());
	Particion P(Gr.numVert());

	for(size_t i=0;i<Gr.numVert();i++)
	{
		for(size_t j=0;j<Gr.numVert();j++)
		{
			//Hay conexion.
			if(Gr[i][j]==1){
				if(P.encontrar(i)!=P.encontrar(j))
				{
					P.unir(P.encontrar(i),P.encontrar(j));
				}
				G[i][j]=dis_euclid(C[i],C[j]);
			}
		}
	}
	cout << "Grafo resultante:" << endl;
	cout << G << endl;
	cout << "Las particiones: ";
	for(size_t i=0;i<Gr.numVert();i++)
	{
		cout << P.encontrar(i) << " ";
	}
	cout << endl;

	typedef typename GrafoP<int>::vertice vertice;
	matriz<vertice> X;
	matriz<int> M=Floyd(G,X);

	cout << "Su Floyd queda:" << endl;
	for(size_t i=0;i<Gr.numVert();i++)
	{
		for(size_t j=0;j<Gr.numVert();j++)
		{
			if(M[i][j]==GrafoP<int>::INFINITO)
			{
				cout << "X" << " ";
			}else{
				cout << M[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

int dis_euclid(Coor C1,Coor C2)
{
	int x=C2.x-C1.x;
	x=pow(x,2);
	int y=C2.y-C1.y;
	y=pow(y,2);
	int z=x+y;
	return sqrt(z);
}

//Ejercicio 2.
void Ejercicio2()
{
	string a="Tombuctu1.txt";
	GrafoP<int> G(a);
	Grafo Gr(G);

	cout << "Grafo Matriz de Costes:" << endl;
	cout << G << endl;
	cout << "Grafo Matriz de Adyacencia:" << endl;
	cout << Gr << endl;

	vector<Coor> C(G.numVert());
	inicializar(C);
	hacer2(C,Gr);
}

void hacer2(const vector<Coor>& C,const Grafo& Gr)
{
	GrafoP<int> G(Gr.numVert());
	Particion P(Gr.numVert());

	for(size_t i=0;i<Gr.numVert();i++)
	{
		for(size_t j=0;j<Gr.numVert();j++)
		{
			//Hay conexion.
			if(Gr[i][j]==1){
				if(P.encontrar(i)!=P.encontrar(j))
				{
					P.unir(P.encontrar(i),P.encontrar(j));
				}
				G[i][j]=dis_euclid(C[i],C[j]);
			}
		}
	}

}

//Ejercicio 3.
void Ejercicio3()
{
	string a="Zuelandia.txt";
	GrafoP<int> G(a);
	Gmaximo(G);
}

template <typename tCoste>
void Gmaximo(const GrafoP<tCoste>& G)
{
	GrafoP<tCoste> G1(G.numVert());

	for(size_t i=0;i<G.numVert();i++)
	{
		for(size_t j=0;j<G.numVert();j++)
		{
			if(G[i][j]!=GrafoP<tCoste>::INFINITO)
			{
				G1[i][j]=G[i][j]*-1;
			}
		}
	}

	cout << "Grafo Maximo:" << endl;
	cout << Prim(G1) << endl;
	cout << "Grafo Minimo:" << endl;
	cout << Prim(G) << endl;
}

//Ejercicio 4.
void Ejercicio4()
{
	string a="Caceres.txt";
	GrafoP<int> G(a);
	Gmaximo2(G);
}

template <typename tCoste>
void Gmaximo2(const GrafoP<tCoste>& G)
{
	GrafoP<tCoste> G1(G.numVert());

	for(size_t i=0;i<G.numVert();i++)
	{
		for(size_t j=0;j<G.numVert();j++)
		{
			if(G[i][j]!=GrafoP<tCoste>::INFINITO)
			{
				G1[i][j]=G[i][j]*-1;
			}
		}
	}

	G1=Prim(G1);

	for(size_t i=0;i<G.numVert();i++)
	{
		for(size_t j=0;j<G.numVert();j++)
		{
			if(G1[i][j]!=GrafoP<tCoste>::INFINITO)
			{
				G1[i][j]=G1[i][j]*-1;
			}
		}
	}

	cout << "Grafo Maximo:" << endl;
	cout << G1 << endl;
}

//Ejercicio 5.
void Ejercicio5()
{
	string a="Espana.txt";
	GrafoP<int> G(a);

	cout << GMinimo(G) << endl;
}

template <typename tCoste>
tCoste GMinimo(const GrafoP<tCoste>& G)
{
	tCoste coste=0;
	GrafoP<tCoste> G1=Prim(G);

	cout << "Grafo:" << endl;
	cout << G << endl;
	cout << "Grafo Minimo:" << endl;
	cout << G1 << endl;
	for(size_t i=0;i<G.numVert();i++)
	{
		for(size_t j=i;j<G.numVert();j++)
		{
			if(G1[i][j]!=GrafoP<tCoste>::INFINITO)
			{
				coste=suma(coste,G1[i][j]);
			}
		}
	}
	return coste;
}

//Ejercicio 7.
void Ejercicio7()
{
	string a="Deimos.txt";
	string b="Phobos.txt";
	GrafoP<int> G1(a);
	GrafoP<int> G2(b);

	vector<int> Cost1(5);
	Cost1[0]=0;
	Cost1[1]=1;
	Cost1[2]=2;
	Cost1[3]=3;
	Cost1[4]=4;
	vector<int> Cost2(5);
	Cost2[0]=5;
	Cost2[1]=6;
	Cost2[2]=7;
	Cost2[3]=8;
	Cost2[4]=9;

	vector<Coor> C(G1.numVert()+G2.numVert());
	inicializar2(C);

	hacer7(C,Cost1,Cost2,G1,G2);
}

template <typename tCoste>
void hacer7(const vector<Coor>& C,const vector<tCoste>& Cost1,const vector<tCoste>& Cost2,const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2)
{
	GrafoP<tCoste> G(G1.numVert()+G2.numVert());

	for(size_t i=0;i<G1.numVert();i++){
		for(size_t j=0;j<G1.numVert();j++){
			G[i][j]=G1[i][j];
		}
	}

	for(size_t i=0;i<G1.numVert();i++){
		for(size_t j=G1.numVert();j<G1.numVert()+G2.numVert();j++){
			G[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	for(size_t i=G1.numVert();i<G1.numVert()+G2.numVert();i++){
		for(size_t j=0;j<G1.numVert();j++){
			G[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	for(size_t i=G1.numVert();i<G1.numVert()+G2.numVert();i++){
		for(size_t j=G1.numVert();j<G1.numVert()+G2.numVert();j++){
			G[i][j]=G2[i-G1.numVert()][j-G1.numVert()];
		}
	}

	for(size_t i=0;i<G1.numVert()+G2.numVert();i++)
	{
		for(size_t j=0;j<G1.numVert()+G2.numVert();j++)
		{
			if(G[i][j]!=GrafoP<tCoste>::INFINITO){
				G[i][j]=dis_euclid(C[i],C[j]);
			}
		}
	}

	cout << "El grafo queda:" << endl;
	cout << G << endl;

	tCoste minimo=GrafoP<tCoste>::INFINITO;
	size_t Ciu1,Ciu2;

	GrafoP<tCoste> aux=G;

	for(size_t i=0;i<5;i++)
	{
		for(size_t j=0;j<5;j++)
		{
			aux[Cost1[i]][Cost2[j]]=dis_euclid(C[Cost1[i]],C[Cost2[j]]);
			aux[Cost2[j]][Cost1[i]]=dis_euclid(C[Cost1[i]],C[Cost2[j]]);

			aux=Prim(aux);
			tCoste actual=0;
			for(size_t i=0;i<aux.numVert();i++)
			{
				for(size_t j=i;j<aux.numVert();j++)
				{
					if(aux[i][j]!=GrafoP<tCoste>::INFINITO){
						actual=suma(actual,aux[i][j]);
					}
				}
			}
			if(actual<minimo)
			{
				minimo=actual;
				Ciu1=Cost1[i];
				Ciu2=Cost2[j];
			}
			aux=G;
		}
	}

	cout << Ciu1 << " " << Ciu2 <<endl;
	cout << "El coste minimo es: " << minimo << ", con puentes entre " << Ciu1 << " y " << Ciu2 << "." << endl;

	GrafoP<tCoste> R=G;
	R[Ciu1][Ciu2]=dis_euclid(C[Ciu1],C[Ciu2]);
	R[Ciu2][Ciu1]=dis_euclid(C[Ciu1],C[Ciu2]);

	cout << "La mejor situacion es:" << endl;
	cout << Prim(R) << endl;

}

void inicializar2(vector<Coor>& C){
	C[0].x=10;
	C[0].y=15;
	C[1].x=0;
	C[1].y=0;
	C[2].x=20;
	C[2].y=0;
	C[3].x=5;
	C[3].y=10;
	C[4].x=15;
	C[4].y=10;
	C[5].x=50;
	C[5].y=15;
	C[6].x=40;
	C[6].y=15;
	C[7].x=60;
	C[7].y=15;
	C[8].x=45;
	C[8].y=0;
	C[9].x=55;
	C[9].y=0;
}
