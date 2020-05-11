#include<iostream>
#include"alg_grafoPMC.h"

using namespace std;

void Ejercicio();
template <typename tCoste>
tCoste diametro(const GrafoP<tCoste>& G);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
  typedef typename GrafoP<int>::vertice vertice;

  string a="G.txt";
  GrafoP<int> G(a);
  int n=G.numVert();
  cout << G;

  cout << "Diametro:" << diametro(G) << endl;

}

template <typename tCoste>
tCoste diametro(const GrafoP<tCoste>& G){
    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<vertice> P(G.numVert());
    matriz<tCoste> M=Floyd(G,P);

    cout << "Imprimiendo Floyd del grafo:" << endl;
    for(int i=0;i<G.numVert();i++){
    	for(int j=0;j<G.numVert();j++){
    		cout << M[i][j] << " ";
    	}
    	cout << "\n";
    }

	tCoste minaux[2]={0,0};
	tCoste diametro=GrafoP<tCoste>::INFINITO;
	vertice pseudocentro;

    cout << "Nodos maximos: " << endl;
	for(int i=0;i<G.numVert();i++){
		for(int j=0;j<G.numVert();j++){
			if(M[i][j]>=minaux[0]){
				minaux[1]=minaux[0];
				minaux[0]=M[i][j];
			}else if(M[i][j]>=minaux[1]){
				minaux[1]=M[i][j];
			}
		}
		if(diametro>minaux[0]+minaux[1]){
			diametro=minaux[0]+minaux[1];
			pseudocentro=i;
		}
		cout<<minaux[0]<<" "<<minaux[1]<<endl;

		minaux[0]=0;
		minaux[1]=0;
	}
	cout << "El pseudocentro es " << pseudocentro << endl;
	return diametro;
}
