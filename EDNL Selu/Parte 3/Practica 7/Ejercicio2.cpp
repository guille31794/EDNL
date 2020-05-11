#include<iostream>
#include"alg_grafoPMC.h"
#include<cstdlib>
#include<cmath>

using namespace std;

//Metodo grafo:
void Ejercicio();
template <typename tCoste>
void camino(const GrafoP<tCoste>& G,const matriz<bool>& Paredes,typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino);


//Especiandolo a examen:
typedef typename GrafoP<size_t>::vertice vertice;

struct casilla{
	int x,y;
	casilla(vertice cx=0,vertice cy=0):x(cx),y(cy){};
	bool operator ==(casilla b){if(this->x==b.x && this->y==b.y){return true;}else{return false;}}
};

struct pared{
	int x,y;
	pared(vertice cx=0,vertice cy=0):x(cx),y(cy){};
};

void Examen();
template <typename tCoste>
void camino(GrafoP<tCoste>& G,vector<pared> Paredes,size_t N);
casilla VerticeCasilla(size_t n,size_t N);
vertice CasillaVertice(casilla c,size_t N);
bool adyacentes(casilla c1,casilla c2);
bool hayPared(casilla c1,casilla c2,vector<pared> Paredes,size_t N);

int main(){
	//Ejercicio();
	Examen();
	return 0;
}

//Ejercicio:
void Ejercicio(){
	string a="Laberinto.txt";

	GrafoP<int> G(a);

	cout <<  G << endl;

	matriz<bool> Paredes(G.numVert(),false);

	Paredes[2][6]=true;
	Paredes[6][2]=true;
	Paredes[3][7]=true;
	Paredes[7][3]=true;
	Paredes[8][9]=true;
	Paredes[9][8]=true;
	Paredes[8][12]=true;
	Paredes[12][8]=true;
	Paredes[10][11]=true;
	Paredes[11][10]=true;
	Paredes[13][14]=true;
	Paredes[14][13]=true;

	typename GrafoP<int>::vertice origen=0,destino=15;

	camino(G,Paredes,origen,destino);
}


template <typename tCoste>
void camino(const GrafoP<tCoste>& G,const matriz<bool>& Paredes,typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino){
	GrafoP<tCoste> aux=G;

	for(size_t i=0;i<G.numVert();i++){
		for(size_t j=0;j<G.numVert();j++){
			if(Paredes[i][j]==true){
				aux[i][j]=GrafoP<tCoste>::INFINITO;
			}
			if(i==j){
				aux[i][j]=0;
			}
		}
	}

	cout << aux << endl;

	typedef typename GrafoP<tCoste>::vertice vertices;
	vector<vertices> P;

	vector<tCoste> M=Dijkstra(aux,origen,P);

	cout << "Coste: " << M[destino] << endl;
	cout << "Camino: ";
	for(size_t i=0;i<P.size();i++){
		cout << P[i] << " ";
	}
	cout << endl;
}

//Examen:
void Examen(){
	size_t N=4;
	GrafoP<size_t> G(N*N);

	vector<pared> Paredes;
	Paredes.push_back(pared(0,4));
	Paredes.push_back(pared(6,7));
	Paredes.push_back(pared(11,15));

	cout <<  G << endl;

	camino(G,Paredes,N);
}

template <typename tCoste>
void camino(GrafoP<tCoste>& G,vector<pared> Paredes,size_t N){
	//Hemos de inicializar el grafo:
	casilla c1,c2;
	for(size_t i=0;i<G.numVert();i++){
		c1=VerticeCasilla(i,N);
		for(size_t j=0;j<G.numVert();j++){
			c2=VerticeCasilla(j,N);
			if(c1==c2){
				G[i][j]=0;
			}else{
				if(adyacentes(c1,c2) && !hayPared(c1,c2,Paredes,N)){
					G[i][j]=1;
				}else{
					G[i][j]=GrafoP<tCoste>::INFINITO;
				}
			}
		}
	}

	cout << "El grafo queda: " << endl;
	cout << G << endl;

	vector<vertice> P;

	vertice origen=0;
	vertice destino=15;
	vector<tCoste> M=Dijkstra(G,origen,P);

	cout << "Coste: " << M[destino] << endl;
	cout << "Camino:" << endl;
	for(size_t i=0;i<M.size();i++){
		cout << M[i] << " ";
	}
	cout << endl;
}

casilla VerticeCasilla(size_t n,size_t N){
	casilla c(n/N,n%N);
	return c;
}

vertice CasillaVertice(casilla c,size_t N){
	return c.x*N+c.y;
}

bool adyacentes(casilla c1,casilla c2){
	return (abs(c1.x-c2.x)+abs(c1.y-c2.y)==1);
}

bool hayPared(casilla c1,casilla c2,vector<pared> Paredes,size_t N){
	vertice aux1=CasillaVertice(c1,N);
	vertice aux2=CasillaVertice(c2,N);

	vertice paux1,paux2;
	for(size_t i=0;i<Paredes.size();i++){
		pared aux=Paredes[i];
		paux1=aux.x;
		paux2=aux.y;
		if(((paux1==aux1) && (paux2==aux2)) || ((paux1==aux2) && (paux2==aux1))){
			return true;
		}
	}
	return false;
}


