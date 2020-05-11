#include<iostream>
#include"alg_grafoPMC.h"

using namespace std;

void Ejercicio();
template <typename tCoste>
void mejoropcion(const GrafoP<tCoste>& A,const GrafoP<tCoste>& B,typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino,
				 typename GrafoP<tCoste>::vertice cambio1,typename GrafoP<tCoste>::vertice cambio2);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string a="Espana tren.txt";
	string b="Espana Bus.txt";
	GrafoP<int> M1(a);
	GrafoP<int> M2(b);

	typename GrafoP<int>::vertice origen=0,destino=2;
	typename GrafoP<int>::vertice cambio1=4,cambio2=3;
	mejoropcion(M1,M2,origen,destino,cambio1,cambio2);
}

//Segun el propio enunciado solo hay dos opciones.
template <typename tCoste>
void mejoropcion(const GrafoP<tCoste>& A,const GrafoP<tCoste>& B,typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino,
				 typename GrafoP<tCoste>::vertice cambio1,typename GrafoP<tCoste>::vertice cambio2){
	typedef typename GrafoP<tCoste>::vertice vertices;
	int precio=GrafoP<tCoste>::INFINITO;
	vector<vertices> ruta;
	ruta.push_back(origen);
	vector<vertices> P;

	vector<tCoste> desdeTren=Dijkstra(A,origen,P);
	vector<tCoste> desdeBus=DijkstraInv(B,destino,P);

	if(suma(desdeTren[cambio1],desdeBus[cambio1])<suma(desdeTren[cambio2],desdeBus[cambio2])){
		ruta.push_back(cambio1);
		precio=suma(desdeTren[cambio1],desdeBus[cambio1]);
	}else{
		ruta.push_back(cambio2);
		precio=suma(desdeTren[cambio2],desdeBus[cambio2]);
	}

	ruta.push_back(destino);

	cout << "El precio del viaje es de " << precio << "$." << endl;
	cout << "La ruta es :" << endl;
	for(size_t i=0;i<ruta.size();i++){
		cout << ruta[i] << " ";
	}
	cout << endl;
}



