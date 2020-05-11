#include<iostream>
#include"alg_grafoPMC.h"

using namespace std;

void Ejercicio();
template <typename tCoste>
void minimo(const GrafoP<tCoste>& A,const GrafoP<tCoste>& B,typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string a="Espana tren.txt";
	string b="Espana Bus.txt";
	GrafoP<int> M1(a);
	GrafoP<int> M2(b);

	typename GrafoP<int>::vertice origen=0,destino=1;
	minimo(M1,M2,origen,destino);
}

template <typename tCoste>
void minimo(const GrafoP<tCoste>& A,const GrafoP<tCoste>& B,typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino){
	int precio=GrafoP<tCoste>::INFINITO;
	int tras=-1;
	typedef typename GrafoP<tCoste>::vertice vertices;
	vector<vertices> P;

	//Primero sin trasbordos.
	vector<tCoste> M=Dijkstra(A,origen,P);
	if(M[destino]<precio){
		precio=M[destino];
	}

	M=Dijkstra(B,origen,P);
	if(M[destino]<precio){
		precio=M[destino];
	}

	//Ahora combinaciones.
	vector<tCoste> Pa;
	vector<tCoste> Pb;
	for(size_t i=0;i<A.numVert();i++){
		if(i!=origen){
			Pa=Dijkstra(A,origen,P);
			Pb=DijkstraInv(B,i,P);
			if(Pa[i]+Pb[destino]<precio){
				precio=Pa[i]+Pb[destino];
				tras=i;
			}
		}
	}
	if(tras!=-1){
		cout << "Se realizo el trasbordo en la ciudad " << tras << "." << endl;
	}
    cout << "El viaje saldra por " << precio << " $." << endl;
}









