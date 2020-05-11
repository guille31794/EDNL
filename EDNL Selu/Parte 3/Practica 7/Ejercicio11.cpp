#include<iostream>
#include"alg_grafoPMC.h"

using namespace std;

void Ejercicio();
template <typename tCoste>
void coste(const GrafoP<tCoste>& I1,const GrafoP<tCoste>& I2,const GrafoP<tCoste>& I3,const matriz<bool>& M,typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string a="Isla1.txt";
	string b="Isla2.txt";
	string c="Isla3.txt";

	GrafoP<int> I1(a);
	GrafoP<int> I2(b);
	GrafoP<int> I3(c);

	cout << I1 << endl;
	cout << I2 << endl;
	cout << I3 << endl;

	typename GrafoP<int>::vertice origen=3,destino=14;

	//Definimos los puentes.
	matriz<bool> M(I1.numVert()+I2.numVert()+I3.numVert(),false);
	M[0][6]=true;
	M[6][0]=true;
	M[7][11]=true;
	M[11][7]=true;

	coste(I1,I2,I3,M,origen,destino);
}

//Disponemos de los 3 grafos, la matriz de puentes y destino/origen.
template <typename tCoste>
void coste(const GrafoP<tCoste>& I1,const GrafoP<tCoste>& I2,const GrafoP<tCoste>& I3,const matriz<bool>& M,typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino){
	GrafoP<tCoste> I(I1.numVert()+I2.numVert()+I3.numVert());

	//Parte I1:
	for(size_t i=0;i<I1.numVert();i++){
		for(size_t j=0;j<I1.numVert();j++){
			I[i][j]=I1[i][j];
		}
	}

	//Parte INFINITO:
	for(size_t i=0;i<I2.numVert();i++){
		for(size_t j=I1.numVert();j<I1.numVert()+I2.numVert();j++){
			I[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	//Parte INFINITO:
	for(size_t i=0;i<I3.numVert();i++){
		for(size_t j=I1.numVert()+I2.numVert();j<I1.numVert()+I2.numVert()+I3.numVert();j++){
			I[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	//Parte INFINITO:
	for(size_t i=I1.numVert();i<I1.numVert()+I2.numVert();i++){
		for(size_t j=0;j<I1.numVert();j++){
			I[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	//Parte I2:
	for(size_t i=I1.numVert();i<I1.numVert()+I2.numVert();i++){
		for(size_t j=I1.numVert();j<I1.numVert()+I2.numVert();j++){
			I[i][j]=I2[i-I1.numVert()][j-I1.numVert()];
		}
	}

	//Parte INFINITO:
	for(size_t i=I1.numVert();i<I1.numVert()+I2.numVert();i++){
		for(size_t j=I1.numVert()+I2.numVert();j<I1.numVert()+I2.numVert()+I3.numVert();j++){
			I[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	//Parte INFINITO:
	for(size_t i=I1.numVert()+I2.numVert();i<I1.numVert()+I2.numVert()+I3.numVert();i++){
		for(size_t j=0;j<I1.numVert();j++){
			I[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	//Parte INFINITO:
	for(size_t i=I1.numVert()+I2.numVert();i<I1.numVert()+I2.numVert()+I3.numVert();i++){
		for(size_t j=I1.numVert();j<I1.numVert()+I2.numVert();j++){
			I[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	//Parte I3:
	for(size_t i=I1.numVert()+I2.numVert();i<I1.numVert()+I2.numVert()+I3.numVert();i++){
		for(size_t j=I1.numVert()+I2.numVert();j<I1.numVert()+I2.numVert()+I3.numVert();j++){
			I[i][j]=I3[i-(I1.numVert()+I2.numVert())][j-(I1.numVert()+I2.numVert())];
		}
	}

	for(size_t i=0;i<I1.numVert()+I2.numVert()+I3.numVert();i++){
		for(size_t j=0;j<I1.numVert()+I2.numVert()+I3.numVert();j++){
			if(M[i][j]==true){
				I[i][j]=0;
			}
		}
	}

	cout << "Grafo resultante:" << endl;
	cout << I << endl;

	typedef typename GrafoP<tCoste>::vertice vertices;
	matriz<vertices> P;
	matriz<tCoste> F=Floyd(I,P);

	for(size_t i=0;i<I1.numVert()+I2.numVert()+I3.numVert();i++){
		for(size_t j=0;j<I1.numVert()+I2.numVert()+I3.numVert();j++){
			cout << F[i][j] << "  ";
		}
		cout << endl;
	}
}
