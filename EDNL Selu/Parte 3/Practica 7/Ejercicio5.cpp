#include<iostream>
#include"alg_grafoPMC.h"

using namespace std;

void Ejercicio();
template <typename tCoste>
void viajes(const GrafoP<tCoste>& A, const GrafoP<tCoste>& B,typename GrafoP<tCoste>::vertice origen,int dinero);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string coche="Zuelandia Coche.txt";
	string tren="Zuelandia Tren.txt";
	string avion="Zuelandia Avion.txt";
	GrafoP<int> G1(coche);
	GrafoP<int> G2(tren);
	GrafoP<int> G3(avion);

	//Aqui se decidiria a que es alergico:
	//...
	//Dinero:
	typename GrafoP<int>::vertice origen=0;
	int dinero=40;
	viajes(G1,G3,origen,dinero);

}

template <typename tCoste>
void viajes(const GrafoP<tCoste>& A, const GrafoP<tCoste>& B,typename GrafoP<tCoste>::vertice origen,int dinero){
	typedef typename GrafoP<tCoste>::vertice vertices;
	vector<vertices> P;
	vector<tCoste> M1=Dijkstra(A,origen,P);
	vector<tCoste> M2=Dijkstra(B,origen,P);
	//IMPORTANTE: Sin estaciones, solo o medio A o B.
	for(size_t i=1;i<A.numVert();i++){
		if(M1[i]<=dinero || M2[i]<=dinero){
			cout << "Puede llegar a la ciudad " << i << endl;
		}
	}
}

