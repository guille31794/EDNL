#include<iostream>
#include"alg_grafoPMC.h"

using namespace std;

void Ejercicio();
template <typename tCoste>
tCoste mejoropcion(const GrafoP<tCoste>& Tren,const GrafoP<tCoste>& Bus,typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino,vector<typename GrafoP<int>::vertice>& ruta,tCoste taxi);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	typedef typename GrafoP<int>::vertice vertices;
	string a="Espana tren.txt";
	string b="Espana Bus.txt";
	GrafoP<int> M1(a);
	GrafoP<int> M2(b);

    vector<vertices> ruta(M1.numVert()+M2.numVert());

	//Tarifa del taxi.
	int taxi=10;
	typename GrafoP<int>::vertice origen=0,destino=5;
	int resultado=mejoropcion(M1,M2,origen,destino,ruta,taxi);

	cout << "El mejor coste es de " << resultado << endl;

	for(size_t i=0;i<ruta.size();i++){
		cout << ruta[i] << " ";
	}
	cout << endl;
}

template <typename tCoste>
tCoste mejoropcion(const GrafoP<tCoste>& Tren,const GrafoP<tCoste>& Bus,typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino,vector<typename GrafoP<int>::vertice>& ruta,tCoste taxi){
	typedef typename GrafoP<tCoste>::vertice vertices;
	GrafoP<tCoste> G(Tren.numVert()+Bus.numVert());	//Creamos un nuevo grafo con capacidad suficiente.

	//Asignamos los valores del grafo Tren.
	for(size_t i=0;i<Tren.numVert();i++){
		for(size_t j=0;j<Tren.numVert();j++){
			G[i][j]=Tren[i][j];
		}
	}

	//Asignamos los valores del grafo Bus.
	for(size_t i=Tren.numVert();i<Tren.numVert()+Bus.numVert();i++){
		for(size_t j=Tren.numVert();j<Tren.numVert()+Bus.numVert();j++){
			G[i][j]=Bus[i-Bus.numVert()][j-Bus.numVert()];
		}
	}

	//Asignamos taxi.
	size_t i=0;
	for(size_t j=Tren.numVert();j<Tren.numVert()+Bus.numVert();j++){
		G[i][j]=taxi;
		i++;
	}

	i=Tren.numVert();
	for(size_t j=0;j<Bus.numVert();j++){
		G[i][j]=taxi;
		i++;
	}

	//Visualizamos el Grafo:
	cout << G << endl;

	//Inicializamos dos rutas. Empezando en Bus o Tren.
 	vector<vertices> ruta1(Tren.numVert()+Bus.numVert());
 	vector<vertices> ruta2(Tren.numVert()+Bus.numVert());

 	vector<tCoste> M1=Dijkstra(G,origen,ruta1);	//Tren.
 	vector<tCoste> M2=Dijkstra(G,origen+Tren.numVert(),ruta2);	//Bus.

 	for(size_t i=0;i<M1.size();i++){
 		cout << M1[i] << " ";
 	}
 	cout << endl;

	for(size_t i=0;i<M2.size();i++){
		cout << M2[i] << " ";
	}
  	cout<<endl;

  	if(M1[destino]<M2[destino+Bus.numVert()]){
  		ruta=ruta1;
  		cout << "La mejor opcion es empezar por Tren." << endl;
  		return M1[destino];
  	}else{
  		ruta=ruta2;
  		cout << "La mejor opcion es empezar por Bus." << endl;
  		return M2[destino+Bus.numVert()];
  	}
}


