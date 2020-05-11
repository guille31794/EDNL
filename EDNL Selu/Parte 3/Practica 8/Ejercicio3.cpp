#include<iostream>
#include<cmath>
#include"particion.cpp"
#include"alg_grafoMA.cpp"
#include"GrafoMA.cpp"
#include"alg_grafoPMC.h"

using namespace std;

struct Coor{
	int x,y;
	Coor():x(0),y(0){}
	Coor(int cx,int cy):x(cx),y(cy){}
};

void Ejercicio();
template <typename tCoste>
void hacer(const GrafoP<tCoste>& G);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string a="Zuelandia.txt";
	GrafoP<int> G(a);

	cout << G << endl;

    hacer(G);
}

template <typename tCoste>
void hacer(const GrafoP<tCoste>& G){
	GrafoP<tCoste> R(G);
	cout << "Arbol de extension minimo:" << endl;
	GrafoP<tCoste> ming=Prim(R);
	cout << ming << endl;

	//Para el maximo vale con multiplicar por -1.
	for(int i=0;i<G.numVert();i++){
		for(int j=0;j<G.numVert();j++){
            if(R[i][j]!=GrafoP<tCoste>::INFINITO){
                R[i][j]=-1*R[i][j];
            }
		}
	}
	cout << R << endl;
	cout << "Arbol de extension maximo:" << endl;
	GrafoP<tCoste> maxg=Prim(R);
	for(int i=0;i<G.numVert();i++){
		for(int j=0;j<G.numVert();j++){
            if(maxg[i][j]!=GrafoP<tCoste>::INFINITO){
                maxg[i][j]=-1*maxg[i][j];
            }
		}
	}
	cout << maxg << endl;
}

