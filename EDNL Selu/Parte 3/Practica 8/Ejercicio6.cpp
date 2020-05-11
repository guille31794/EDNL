#include<iostream>
#include"particion.cpp"
#include"alg_grafoMA.cpp"
#include"grafoMA.cpp"
#include"alg_grafoPMC.h"

using namespace std;

void Ejercicio();
template <typename tCoste>
void inicializar(matriz<tCoste>& Caudal);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string a="Caceres.txt";
	GrafoP<int> G(a);
	cout << G << endl;

	matriz<int> Caudal(G.numVert(),0);
	inicializar(Caudal);
}

template <typename tCoste>
void inicializar(matriz<tCoste>& Caudal){

}
