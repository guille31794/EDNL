#include<iostream>
#include"alg_grafoPMC.h"

using namespace std;

void Ejercicio();
template <typename tCoste>
void opciona(GrafoP<tCoste>& G,matriz<bool> carrOcupadas,vector<bool> ciuOcupadas);
template <typename tCoste>
void opcionb(GrafoP<tCoste>& G,matriz<bool> carrOcupadas,vector<bool> ciuOcupadas,typename GrafoP<tCoste>::vertice capital);


int main(){
	Ejercicio();
	return 0;
}

//Ocupadas carreteras: 0-6, 0-1, 1-4.
//Ocupadas ciudades: 6.
void Ejercicio(){
	typedef typename GrafoP<int>::vertice vertice;

    string a="Zuelandia.txt";
    GrafoP<int> G(a);
    int n=G.numVert();
    cout << G;

    matriz<bool> carrOcupadas(G.numVert(),false);

    carrOcupadas[0][4]=true;
    carrOcupadas[1][4]=true;
    carrOcupadas[0][1]=true;

    vector<bool> ciuOcupadas(G.numVert());
    for(int i=0;i<G.numVert();i++){
    	ciuOcupadas[i]=false;
    }
    ciuOcupadas[6]=true;
    opciona(G,carrOcupadas,ciuOcupadas);

    typename GrafoP<int>::vertice capital=0;
    opcionb(G,carrOcupadas,ciuOcupadas,capital);
}

template <typename tCoste>
void opciona(GrafoP<tCoste>& G,matriz<bool> carrOcupadas,vector<bool> ciuOcupadas){
	//Si una ciudad esta ocupada, en la matriz de costes ponemos su fila y columna a INFINITO.
	for(int i=0;i<G.numVert();i++){
		if(ciuOcupadas[i]==true){
			for(int j=0;j<G.numVert();j++){
				G[i][j]=GrafoP<tCoste>::INFINITO;
				G[j][i]=GrafoP<tCoste>::INFINITO;
			}
		}
	}

	//Si una caretera esta ocupada ponemos su casilla a INFINITO.
	for(int i=0;i<G.numVert();i++){
		for(int j=0;j<G.numVert();j++){
			if(carrOcupadas[i][j]==true){
				G[i][j]=GrafoP<tCoste>::INFINITO;
				G[j][i]=GrafoP<tCoste>::INFINITO;
			}
		}
	}

	//Listo para hacer Floyd:
    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<vertice> P(G.numVert());

    matriz<tCoste> M=Floyd(G,P);

    cout << "Sin pasar por la capital: " << endl;

    for(int i=0;i<G.numVert();i++){
    	for(int j=0;j<G.numVert();j++){
            if(M[i][j]==GrafoP<tCoste>::INFINITO){
                cout << "X" << " ";
            }else{
                cout << M[i][j] << " ";
            }
    	}
    	cout << "\n";
    }
    cout << endl;
}

template <typename tCoste>
void opcionb(GrafoP<tCoste>& G,matriz<bool> carrOcupadas,vector<bool> ciuOcupadas,typename GrafoP<tCoste>::vertice capital){
//Si una ciudad esta ocupada, en la matriz de costes ponemos su fila y columna a INFINITO.
	for(int i=0;i<G.numVert();i++){
		if(ciuOcupadas[i]==true){
			for(int j=0;j<G.numVert();j++){
				G[i][j]=GrafoP<tCoste>::INFINITO;
				G[j][i]=GrafoP<tCoste>::INFINITO;
			}
		}
	}

	//Si una caretera esta ocupada ponemos su casilla a INFINITO.
	for(int i=0;i<G.numVert();i++){
		for(int j=0;j<G.numVert();j++){
			if(carrOcupadas[i][j]==true){
				G[i][j]=GrafoP<tCoste>::INFINITO;
			}
		}
	}

    typedef typename GrafoP<tCoste>::vertice vertice;

  	vector<vertice> P;

  	vector<tCoste> alacapital;
  	alacapital=DijkstraInv(G,capital,P);

  	vector<tCoste> delacapital;
 	delacapital=Dijkstra(G,capital,P);

 	cout << "Pasando por la capital: " << endl;
 	for(size_t i=0;i<G.numVert();++i){
    	for(size_t j=0;j<G.numVert();++j){
      		G[i][j]=suma(alacapital[i],delacapital[j]);
		}
 	}

 	for(size_t i=0;i<G.numVert();i++){
 		if(G[i][i]!=0 && ciuOcupadas[i]==false){
 			G[i][i]=0;
 		}
 	}

	cout << G << endl;
}

