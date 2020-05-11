#include<iostream>
#include"alg_grafoPMC.h"

using namespace std;

void Ejercicio();
template <typename tCoste>
void mejoropcion(const GrafoP<tCoste>& Bus,const GrafoP<tCoste>& Tren,const GrafoP<tCoste>& Avion,typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino,
				 int taxia,int taxib);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string a="Espana Bus.txt";
	string b="Espana Tren.txt";
	string c="Espana Avion.txt";

	GrafoP<int> Bus(a);
	GrafoP<int> Tren(b);
	GrafoP<int> Avion(c);

	typename GrafoP<int>::vertice origen=3,destino=2;

	int taxia=3,taxib=7;

	mejoropcion(Bus,Tren,Avion,origen,destino,taxia,taxib);
}

template <typename tCoste>
void mejoropcion(const GrafoP<tCoste>& Bus,const GrafoP<tCoste>& Tren,const GrafoP<tCoste>& Avion,typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino,
				 int taxia,int taxib){
	GrafoP<tCoste> G(Bus.numVert()+Tren.numVert()+Avion.numVert());
	typedef typename GrafoP<tCoste>::vertice vertices;
	vector<vertices> ruta(Bus.numVert()+Tren.numVert()+Avion.numVert());

	//Inicializamos parte Bus:
	for(size_t i=0;i<Bus.numVert();i++){
		for(int j=0;j<Bus.numVert();j++){
			G[i][j]=Bus[i][j];
		}
	}

	//Inicializamos 1 parte taxia:
	size_t i=0;
	for(size_t j=Bus.numVert();j<Bus.numVert()+Tren.numVert();j++){
		G[i][j]=taxia;
		i++;
	}

	//Inicializamos 1 parte taxib:
	i=0;
	for(size_t j=Bus.numVert()+Tren.numVert();j<Bus.numVert()+Tren.numVert()+Avion.numVert();j++){
		G[i][j]=taxib;
		i++;
	}

	//Inicializamos 1 parte de taxia:
	i=Bus.numVert();
	for(size_t j=0;j<Tren.numVert();j++){
		G[i][j]=taxia;
		i++;
	}

	//Inicializamos parte Tren:
	for(size_t i=Bus.numVert();i<Bus.numVert()+Tren.numVert();i++){
		for(size_t j=Bus.numVert();j<Bus.numVert()+Tren.numVert();j++){
			G[i][j]=Tren[i-Tren.numVert()][j-Tren.numVert()];
		}
	}

	//Inicializamos 1 parte taxib:
	i=Bus.numVert();
	for(size_t j=Bus.numVert()+Tren.numVert();j<Bus.numVert()+Tren.numVert()+Avion.numVert();j++){
		G[i][j]=taxib;
		i++;
	}

	//Inicializamos 1 parte taxib:
	i=Bus.numVert()+Tren.numVert();
	for(size_t j=0;j<Bus.numVert();j++){
		G[i][j]=taxib;
		i++;
	}

	//Inicializamos 1 parte taxib:
	i=Bus.numVert()+Tren.numVert();
	for(size_t j=Bus.numVert();j<Bus.numVert()+Tren.numVert();j++){
		G[i][j]=taxib;
		i++;
	}

	//Inicializamos parte Avion:
	for(size_t i=Bus.numVert()+Tren.numVert();i<Bus.numVert()+Tren.numVert()+Avion.numVert();i++){
		for(size_t j=Bus.numVert()+Tren.numVert();j<Bus.numVert()+Tren.numVert()+Avion.numVert();j++){
			G[i][j]=Avion[i-(Bus.numVert()+Tren.numVert())][j-(Bus.numVert()+Tren.numVert())];
		}
	}

	cout << G << endl;

	tCoste precio=GrafoP<tCoste>::INFINITO;
	vector<vertices> ruta1;
	vector<vertices> ruta2;
	vector<vertices> ruta3;

	vector<tCoste> M1=Dijkstra(G,origen,ruta1);	//Bus.
	vector<tCoste> M2=Dijkstra(G,origen+Bus.numVert(),ruta2);	//Tren.
	vector<tCoste> M3=Dijkstra(G,origen+Bus.numVert()+Tren.numVert(),ruta3);  //Avion.

	tCoste d1=min(M1[destino],min(M1[destino+Bus.numVert()],M1[destino+Bus.numVert()+Tren.numVert()]));
    tCoste d2=min(M2[destino],min(M2[destino+Bus.numVert()],M2[destino+Bus.numVert()+Tren.numVert()]));
    tCoste d3=min(M3[destino],min(M3[destino+Bus.numVert()],M3[destino+Bus.numVert()+Tren.numVert()]));

    cout << "El coste es: ";
	if(d1<d2){
	    if(d1<d3){
	    	ruta=ruta1;
	        cout << d1;
	    }else{
	        ruta=ruta3;
	    	cout << d3;
	    }
	}else{
	    if(d2<d3){
	    	ruta=ruta2;
	        cout << d2;
	    }else{
	        ruta=ruta3;
	        cout << d3;
	    }
	}
	cout << endl;
	for(size_t i=0;i<ruta.size();i++){
		cout << ruta[i] << " ";
	}
	cout << endl;
}





