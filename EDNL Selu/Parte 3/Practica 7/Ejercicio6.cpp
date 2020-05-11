#include<iostream>
#include"alg_grafoPMC.h"

using namespace std;

void Ejercicio();
template <typename tCoste>
void mejorcombi(const GrafoP<tCoste>& A,const GrafoP<tCoste>& B,typename GrafoP<tCoste>::vertice estacion,typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino);
template <typename tCoste>
void mejorFloyd(const GrafoP<tCoste>& A,const GrafoP<tCoste>& B,typename GrafoP<tCoste>::vertice estacion,typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino);


int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string a="Espana tren.txt";
	string b="Espana Bus.txt";
	GrafoP<int> M1(a);
	GrafoP<int> M2(b);

	//Es la ciudad 4 la que tiene la estacion.
	typename GrafoP<int>::vertice estacion=3;

	//Origen y detino:
	typename GrafoP<int>::vertice origen=0,destino=2;
	mejorcombi(M1,M2,estacion,origen,destino);
	//mejorFloyd(M1,M2,estacion,origen,destino);
}

//Esta bien, pero el enunciado pide MATRIZ DE COSTES MINIMOs, osea un Floyd en toda regla.
template <typename tCoste>
void mejorcombi(const GrafoP<tCoste>& A,const GrafoP<tCoste>& B,typename GrafoP<tCoste>::vertice estacion,typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino){
	//Calculamos las 4 combinaciones y nos quedamos con la mejor.
	int precio,combi,aux;
	precio=GrafoP<tCoste>::INFINITO;
	typedef typename GrafoP<tCoste>::vertice vertices;
	vector<vertices> P;

	//Tren.
	vector<tCoste> Op1=Dijkstra(A,origen,P);
	cout << Op1[destino] << endl;
	if(Op1[destino]<precio){
		precio=Op1[destino];
		combi=1;
	}

	//Bus.
	vector<tCoste> Op2=Dijkstra(B,origen,P);
	cout << Op2[destino] << endl;
	if(Op1[destino]<precio){
		precio=Op2[destino];
		combi=2;
	}

	//Tren-Bus.
	vector<tCoste> Op3a=Dijkstra(A,origen,P);
	vector<tCoste> Op3b=Dijkstra(B,estacion,P);
	aux=Op3a[estacion]+Op3b[destino];
	cout << aux << endl;
	if(aux<precio){
		precio=aux;
		combi=3;
	}

	//Bus-Tren.
	vector<tCoste> Op4a=Dijkstra(B,origen,P);
	vector<tCoste> Op4b=Dijkstra(A,estacion,P);
	aux=Op3a[estacion]+Op3b[destino];
	cout << aux << endl;
	if(aux<precio){
		precio=aux;
		combi=4;
	}

	cout << precio << ":" << combi << endl;
}

template <typename tCoste>
void mejorFloyd(const GrafoP<tCoste>& A,const GrafoP<tCoste>& B,typename GrafoP<tCoste>::vertice estacion,typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino){
	int precio,combi,aux;
	precio=GrafoP<tCoste>::INFINITO;
	typedef typename GrafoP<tCoste>::vertice vertices;
	matriz<vertices> P;

	//Tren.
	matriz<tCoste> Op1=Floyd(A,P);
	cout << Op1[origen][destino] << endl;
	if(Op1[origen][destino]<precio){
		precio=Op1[origen][destino];
		combi=1;
	}

	//Bus.
	matriz<tCoste> Op2=Floyd(B,P);
	cout << Op2[origen][destino] << endl;
	if(Op2[origen][destino]<precio){
		precio=Op2[origen][destino];
		combi=2;
	}

	//Tren-Bus.
	//Se ha de llegar hasta la estacion, desde ahi, se viaja al destino.
}











