#include<iostream>
#include"alg_grafoPMC.h"

using namespace std;

void Ejercicio();
template <typename tCoste>
void mejorOpcion(const GrafoP<tCoste>& I1,const GrafoP<tCoste>& I2,const GrafoP<tCoste>& I3,const vector<typename GrafoP<tCoste>::vertice>& Costeras);

int main(){
	Ejercicio();
	return 0;
}

void Ejercicio(){
	string a="Isla1.txt";
	string b="Isla2.txt";
	string c="Isla3.txt";

	GrafoP<int> I1(a);
	GrafoP<int> I2(b);
	GrafoP<int> I3(c);

	cout << "Isla 1:" << endl;
	cout << I1 << endl;
	cout << "Isla 2:" << endl;
	cout << I2 << endl;
	cout << "Isla 3:" << endl;
	cout << I3 << endl;

	typedef typename GrafoP<int>::vertice vertices;
	vector<vertices> Costeras(I1.numVert()+I2.numVert()+I3.numVert(),false);

	Costeras[2]=true;
	Costeras[3]=true;
	Costeras[4]=true;
	Costeras[6]=true;
	Costeras[9]=true;
	Costeras[10]=true;
	Costeras[13]=true;

	mejorOpcion(I1,I2,I3,Costeras);
}

template <typename tCoste>
void mejorOpcion(const GrafoP<tCoste>& I1,const GrafoP<tCoste>& I2,const GrafoP<tCoste>& I3,const vector<typename GrafoP<tCoste>::vertice>& Costeras){
	GrafoP<tCoste> G(I1.numVert()+I2.numVert()+I3.numVert());

	//Parte I1:
	for(size_t i=0;i<I1.numVert();i++){
		for(size_t j=0;j<I1.numVert();j++){
			G[i][j]=I1[i][j];
		}
	}

	//Parte INFINITO:
	for(size_t i=0;i<I2.numVert();i++){
		for(size_t j=I1.numVert();j<I1.numVert()+I2.numVert();j++){
			G[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	//Parte INFINITO:
	for(size_t i=0;i<I3.numVert();i++){
		for(size_t j=I1.numVert()+I2.numVert();j<I1.numVert()+I2.numVert()+I3.numVert();j++){
			G[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	//Parte INFINITO:
	for(size_t i=I1.numVert();i<I1.numVert()+I2.numVert();i++){
		for(size_t j=0;j<I1.numVert();j++){
			G[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	//Parte I2:
	for(size_t i=I1.numVert();i<I1.numVert()+I2.numVert();i++){
		for(size_t j=I1.numVert();j<I1.numVert()+I2.numVert();j++){
			G[i][j]=I2[i-I1.numVert()][j-I1.numVert()];
		}
	}

	//Parte INFINITO:
	for(size_t i=I1.numVert();i<I1.numVert()+I2.numVert();i++){
		for(size_t j=I1.numVert()+I2.numVert();j<I1.numVert()+I2.numVert()+I3.numVert();j++){
			G[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	//Parte INFINITO:
	for(size_t i=I1.numVert()+I2.numVert();i<I1.numVert()+I2.numVert()+I3.numVert();i++){
		for(size_t j=0;j<I1.numVert();j++){
			G[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	//Parte INFINITO:
	for(size_t i=I1.numVert()+I2.numVert();i<I1.numVert()+I2.numVert()+I3.numVert();i++){
		for(size_t j=I1.numVert();j<I1.numVert()+I2.numVert();j++){
			G[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	//Parte I3:
	for(size_t i=I1.numVert()+I2.numVert();i<I1.numVert()+I2.numVert()+I3.numVert();i++){
		for(size_t j=I1.numVert()+I2.numVert();j<I1.numVert()+I2.numVert()+I3.numVert();j++){
			G[i][j]=I3[i-(I1.numVert()+I2.numVert())][j-(I1.numVert()+I2.numVert())];
		}
	}

	typedef typename GrafoP<tCoste>::vertice vertices;
	matriz<vertices> P;

	size_t num=0;
	for(size_t i=0;i<I1.numVert()+I2.numVert()+I3.numVert();i++){
		if(Costeras[i]==true){
			num++;
		}
	}

	vector<vertices> Ciu(num);
    num=0;
	for(size_t i=0;i<I1.numVert()+I2.numVert()+I3.numVert();i++){
		if(Costeras[i]==true){
            Ciu[num]=i;
			num++;
		}
	}

	cout << "El grafo completo queda:" << endl;
	cout << G << endl;

	vertices c1=1,c2=1,c3=1;
	tCoste precio=GrafoP<tCoste>::INFINITO;

	GrafoP<tCoste> aux=G;

	for(size_t i=0;i<Ciu.size()-2;i++){
		for(size_t j=i+1;j<Ciu.size()-1;j++){
			for(size_t p=j+1;p<Ciu.size();p++){
				aux[Ciu[i]][Ciu[j]]=0;
				aux[Ciu[j]][Ciu[i]]=0;
				aux[Ciu[j]][Ciu[p]]=0;
				aux[Ciu[p]][Ciu[j]]=0;
				matriz<tCoste> M=Floyd(aux,P);
				tCoste estePrecio=0;
				for(size_t i1=0;i1<I1.numVert()+I2.numVert()+I3.numVert();i1++){
					estePrecio=suma(estePrecio,M[Ciu[i]][i1]);
					estePrecio=suma(estePrecio,M[Ciu[j]][i1]);
					estePrecio=suma(estePrecio,M[Ciu[p]][i1]);
				}
				if(estePrecio<precio){
					c1=Ciu[i];
					c2=Ciu[j];
					c3=Ciu[p];
					precio=estePrecio;
				}
				aux=G;
			}
		}
		cout << endl;
	}

	cout << "Los puentes se deben construir en las ciudades " << c1 << " " << c2 << " " << c3 << " con un precio total de " << precio << " $." << endl;

	G[c1][c2]=0;
	G[c2][c1]=0;
	G[c2][c3]=0;
	G[c3][c2]=0;
	cout << "El grafo quedaria:" << endl;
	cout << G << endl;

	matriz<tCoste> M=Floyd(G,P);
	cout << "Su Floyd queda:" << endl;
	for(size_t i=0;i<I1.numVert()+I2.numVert()+I3.numVert();i++){
		for(size_t j=0;j<I1.numVert()+I2.numVert()+I3.numVert();j++){
			cout << M[i][j] << " ";
		}
		cout << endl;
	}

}





