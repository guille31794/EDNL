#include<iostream>
#include<cmath>
#include<algorithm>
#include"alg_grafoPMC.h"
#include"alg_grafoMA.cpp"
#include"grafoMA.cpp"
#include "particion.cpp"

using namespace std;

struct Coor{
	int x,y;
	Coor():x(0),y(0){}
	Coor(int cx,int cy):x(cx),y(cy){}
};

void Ejercicio();
void inicializar(vector<Coor>& C);
void islas(const Grafo& G,const vector<Coor>& C,size_t N);
int euclid(Coor C1,Coor C2);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string a="Tombuctu1.txt";
	GrafoP<int> G(a);
	cout << "Grafo Matriz Costes:" << endl;
	cout << G << endl;
	Grafo Gr(G);
	cout << "Grafo Matriz Adyacencia:" << endl;
    cout << Gr << endl;

    size_t N=Gr.numVert();

    vector<Coor> C(N);
    inicializar(C);
    islas(Gr,C,N);
}

void inicializar(vector<Coor>& C){
    //Isla 1:
    C[0].x=0;
    C[0].y=5;
    C[1].x=3;
    C[1].y=5;
    C[2].x=0;
    C[2].y=0;
    C[3].x=3;
    C[3].y=0;
    //Isla 2:
    C[4].x=7;
    C[4].y=4;
    C[5].x=10;
    C[5].y=3;
    C[6].x=8;
    C[6].y=2;
    C[7].x=6;
    C[7].y=0;
    //Isla 3:
    C[8].x=13;
    C[8].y=6;
    C[9].x=15;
    C[9].y=6;
    C[10].x=13;
    C[10].y=2;
    C[11].x=15;
    C[11].y=2;
    C[12].x=14;
    C[12].y=0;
}

void islas(const Grafo& G,const vector<Coor>& C,size_t N){
	//Creamos el grafo de matriz de costes.
	GrafoP<int> R(N);
	Particion Ciu(N);

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(G[i][j]==1){
				R[i][j]=euclid(C[i],C[j]);
				if(Ciu.encontrar(i)!=Ciu.encontrar(j)){
                    Ciu.unir(Ciu.encontrar(i),Ciu.encontrar(j));
				}
			}
		}
	}
	cout << "Grafo de MC: " << endl;
	cout << R << endl;

	cout << "Particiones: ";
	for(size_t i=0;i<N;i++){
        cout << Ciu.encontrar(i) << " ";
	}
	cout << endl;
	cout << "Luego hay ";
	int n=Ciu.encontrar(1);
	int j=1;
	for(size_t i=0;i<N;i++){
        if(n!=Ciu.encontrar(i)){
        	j++;
        	n=Ciu.encontrar(i);
        }
	}
	cout << j << " islas." << endl;

	typedef typename GrafoP<int>::vertice vertices;
	matriz<vertices> X;
	matriz<int> F=Floyd(R,X);

	cout << "Coste para viajar a cada ciudad: " << endl;
	for(size_t i=0;i<N;i++){
		for(size_t j=0;j<N;j++){
			if(F[i][j]==GrafoP<int>::INFINITO){
				cout << "X" << " ";
			}else{
				cout << F[i][j] << " ";
			}
		}
		cout << endl;
	}
}

int euclid(Coor C1,Coor C2){
	float x=C1.x-C2.x;
	float y=C1.y-C2.y;
	x=pow(x,2);
	y=pow(y,2);
	float z=x+y;
	return int(sqrt(z));
}
