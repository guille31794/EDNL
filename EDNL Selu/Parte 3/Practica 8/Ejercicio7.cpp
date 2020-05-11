#include<iostream>
#include<cmath>
#include"particion.cpp"
#include"alg_grafoPMC.h"
#include"alg_grafoMA.cpp"
#include"GrafoMa.cpp"

using namespace std;


struct Coor{
	int x,y;
	Coor(int cx=0,int cy=0):x(cy),y(cx){}
};

void Ejercicio();
template <typename tCoste>
GrafoP<tCoste> unir(const GrafoP<tCoste>& D,const GrafoP<tCoste>& P);
void inicializar(vector<Coor>& C);
template <typename tCoste>
void part(const GrafoP<tCoste>& G,Particion& islas);
template <typename tCoste>
void puente(GrafoP<tCoste>& G,const vector<Coor>& C,const Particion& islas,const vector<bool>& Cos);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string a="Deimos.txt";
	string b="Phobos.txt";
	GrafoP<int> D(a);
	GrafoP<int> P(b);
	cout << D << endl;
	cout << P << endl;

	GrafoP<int> G=unir(D,P);
	cout << G << endl;

	//Inicializamos vector de coordenadas:
	vector<Coor> C(G.numVert());
	inicializar(C);

	//Vector ciudades costeras:
	vector<bool> Cos(G.numVert(),false);
	Cos[0]=true;
	Cos[1]=true;
	Cos[2]=true;
	Cos[6]=true;
	Cos[7]=true;
	Cos[8]=true;

	//Lo importante es ver el puente, ya que las carreteras se hacen con Prim.
	Particion Islas(G.numVert());
	part(G,Islas);
	puente(G,C,Islas,Cos);

	//Una vez todo hecho, aplicamos Prim:
	G=Prim(G);
	cout << G << endl;
}

template <typename tCoste>
GrafoP<tCoste> unir(const GrafoP<tCoste>& D,const GrafoP<tCoste>& P){
	GrafoP<tCoste> G(D.numVert()+P.numVert());

	for(size_t i=0;i<D.numVert();i++){
		for(size_t j=0;j<D.numVert();j++){
			G[i][j]=D[i][j];
		}
	}

	for(size_t i=0;i<D.numVert();i++){
		for(size_t j=D.numVert();j<D.numVert()+P.numVert();j++){
			G[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	for(size_t i=D.numVert();i<D.numVert()+P.numVert();i++){
		for(size_t j=0;j<D.numVert();j++){
			G[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	for(size_t i=D.numVert();i<D.numVert()+P.numVert();i++){
		for(size_t j=D.numVert();j<D.numVert()+P.numVert();j++){
			G[i][j]=P[i-D.numVert()][j-D.numVert()];
		}
	}
	return G;
}

void inicializar(vector<Coor>& C){
	C[0].x=10;
	C[0].y=15;
	C[1].x=0;
	C[1].y=0;
	C[2].x=20;
	C[2].y=0;
	C[3].x=5;
	C[3].y=10;
	C[4].x=15;
	C[4].y=10;
	C[5].x=50;
	C[5].y=15;
	C[6].x=40;
	C[6].y=15;
	C[7].x=60;
	C[7].y=15;
	C[8].x=45;
	C[8].y=0;
	C[9].x=55;
	C[9].y=0;
}

template <typename tCoste>
void part(const GrafoP<tCoste>& G,Particion& islas){
	for(size_t i=0;i<G.numVert();i++){
		for(size_t j=0;j<G.numVert();j++){
			if(G[i][j]!=GrafoP<tCoste>::INFINITO && islas.encontrar(i)!=islas.encontrar(j)){
				islas.unir(islas.encontrar(i),islas.encontrar(j));
			}
		}
	}

	for(size_t i=0;i<G.numVert();i++){
		cout << islas.encontrar(i) << " ";
	}
	cout << endl;
}

template <typename tCoste>
void puente(GrafoP<tCoste>& G,const vector<Coor>& C,const Particion& islas,const vector<bool>& Cos){
	typedef typename GrafoP<tCoste>::vertice vertices;
	vertices c1,c2;
	tCoste minDis=GrafoP<tCoste>::INFINITO;

	//Vamos a sacar las ciudades costeras.
	int num=0;
	for(size_t i=0;i<G.numVert();i++){
		if(Cos[i]==true){
			num++;
		}
	}
	vector<vertices> VertCos(num);
	num=0;
	for(size_t i=0;i<G.numVert();i++){
		if(Cos[i]==true){
			VertCos[num]=i;
			num++;
		}
	}

	for(size_t i=0;i<VertCos.size()-1;i++){
		for(size_t j=i+1;j<VertCos.size();j++){
			if(islas.encontrar(VertCos[i])!=islas.encontrar(VertCos[j])){
				if(euclid(C[VertCos[i]],C[VertCos[j]])<minDis){
					c1=VertCos[i];
					c2=VertCos[j];
					minDis=euclid(C[VertCos[i]],C[VertCos[j]]);
				}
			}
		}
		cout << endl;
	}

	G[c1][c2]=minDis;
	G[c2][c1]=minDis;
}

int euclid(Coor C1,Coor C2){
	int x=C1.x-C2.x;
	int y=C1.y-C2.y;
	x=pow(x,2);
	y=pow(y,2);
	int z=x+y;
	return int(sqrt(z));
}
