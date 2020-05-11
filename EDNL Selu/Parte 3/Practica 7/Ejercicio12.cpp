#include<iostream>
#include"alg_grafoPMC.h"
#include<cstdlib>

using namespace std;

void Ejercicio();
template <typename tCoste>
void mejorOpcion(const GrafoP<tCoste>& Deimos,const GrafoP<tCoste>& Phobos,const vector<typename GrafoP<tCoste>::vertice>& Costeras);


int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string a="Deimos.txt";
	string b="Phobos.txt";

	GrafoP<int> Deimos(a);
	GrafoP<int> Phobos(b);

	cout << "Deimos: " << endl;
	cout << Deimos << endl;

	cout << "Phobos: " << endl;
	cout << Phobos << endl;

	//Creamos la lista de los ciudades costeras.
	typedef typename GrafoP<int>::vertice vertices;
	vector<vertices> Costeras(Deimos.numVert()+Phobos.numVert(),false);

	Costeras[0]=true;
	Costeras[1]=true;
	Costeras[2]=true;
	Costeras[6]=true;
	Costeras[7]=true;

	mejorOpcion(Deimos,Phobos,Costeras);
}

template <typename tCoste>
void mejorOpcion(const GrafoP<tCoste>& Deimos,const GrafoP<tCoste>& Phobos,const vector<typename GrafoP<tCoste>::vertice>& Costeras){
	GrafoP<tCoste> G(Deimos.numVert()+Phobos.numVert());

	//Parte Deimos:
	for(size_t i=0;i<Deimos.numVert();i++){
		for(size_t j=0;j<Deimos.numVert();j++){
			G[i][j]=Deimos[i][j];
		}
	}

	//Parte INFINITO:
	for(size_t i=0;i<Deimos.numVert();i++){
		for(size_t j=Deimos.numVert();j<Deimos.numVert()+Phobos.numVert();j++){
			G[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	//Parte INFINITO:
	for(size_t i=Deimos.numVert();i<Deimos.numVert()+Phobos.numVert();i++){
		for(size_t j=0;j<Deimos.numVert();j++){
			G[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	//Parte Phobos:
	for(size_t i=Deimos.numVert();i<Deimos.numVert()+Phobos.numVert();i++){
		for(size_t j=Deimos.numVert();j<Deimos.numVert()+Phobos.numVert();j++){
			G[i][j]=Phobos[i-Deimos.numVert()][j-Deimos.numVert()];
		}
	}

	//Grafo completo:
	cout << "Grafo combinado:" << endl;
	cout << G << endl;

	//Una vez lo tenemos, debemos probar todas las combinaciones
	typedef typename GrafoP<tCoste>::vertice vertices;
	matriz<vertices> P;

	size_t num=0;
	for(size_t i=0;i<Deimos.numVert()+Phobos.numVert();i++){
		if(Costeras[i]==true){
			num++;
		}
	}

	vector<vertices> Ciu(num);
    num=0;
	for(size_t i=0;i<Deimos.numVert()+Phobos.numVert();i++){
		if(Costeras[i]==true){
            Ciu[num]=i;
			num++;
		}
	}

	tCoste precio=GrafoP<tCoste>::INFINITO;
	vertices c1=-1;
	vertices c2=-1;

	GrafoP<tCoste> aux=G;

	//No hace falta diferenciar entre que ciudades son de la misma isla, ya que si son de la misma isla, estePrecio=infinito
	for(size_t i=0;i<Ciu.size()-1;i++){
		for(size_t j=i+1;j<Ciu.size();j++){
			aux[Ciu[i]][Ciu[j]]=0;
			aux[Ciu[j]][Ciu[i]]=0;
			matriz<tCoste> M=Floyd(aux,P);
			tCoste estePrecio=0;
			for(size_t i1=0;i1<Deimos.numVert()+Phobos.numVert();i1++){
				estePrecio=suma(estePrecio,M[Ciu[j]][i1]);
				estePrecio=suma(estePrecio,M[Ciu[i]][i1]);
			}
			if(estePrecio<precio){
				precio=estePrecio;
				c1=Ciu[i];
				c2=Ciu[j];
			}
			aux=G;
		}
	}

	cout << "Si el puente se situa entre las islas: " << c1 << " y " << c2 << " nos saldria " << precio << "." << endl;

	cout << "El grafo quedaria:" << endl;
	G[c1][c2]=0;
	G[c2][c1]=0;
	cout << G << endl;

	matriz<tCoste> M=Floyd(G,P);
	cout << "Su Floyd queda:" << endl;
	for(size_t i=0;i<Deimos.numVert()+Phobos.numVert();i++){
		for(size_t j=0;j<Deimos.numVert()+Phobos.numVert();j++){
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}
