#include<iostream>
#include"AGEN.hpp"
#include"agen_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin='#';

//Ejercicio 1:
void Ej1();
int grado(Agen<tElto>& A);
int gradoRec(typename Agen<tElto>::nodo n,int &gradoMax,Agen<tElto>& A);
int contar(typename Agen<tElto>::nodo n,Agen<tElto>& A);
//Ejercicio 2:
void Ej2();
int profundidad(typename Agen<tElto>::nodo n,Agen<tElto>& A);
//Ejercicio 3:
void Ej3();

//Ejercicio 4:
void Ej4();
void podar(char x,Agen<tElto>& A);
void buscar(typename Agen<tElto>::nodo n,char x,Agen<tElto>& A);
void podarRec(typename Agen<tElto>::nodo n,typename Agen<tElto>::nodo n1,Agen<tElto>& A);

int main(){
    Ej4();
	return 0;
}


void Ej1(){
	Agen<tElto> A;
	rellenarAgen(A,fin);
	imprimirAgen(A);
	cout << "El grado del arbol es " << grado(A) << endl;
}

int grado(Agen<tElto>& A){
	if(A.arbolVacio()){
		cout << "Arbol vacio, grado 0." << endl;
		exit(0);
	}else{
		int grado=1;
		gradoRec(A.raiz(),grado,A);
		return grado;
	}
}

int gradoRec(typename Agen<tElto>::nodo n,int &gradoMax,Agen<tElto>& A){
	if(n!=Agen<tElto>::NODO_NULO){
		int grado;
		grado=contar(n,A);
		if(grado>gradoMax){
			gradoMax=grado;
		}
		if(A.hermDrcho(n)!=Agen<tElto>::NODO_NULO && A.hijoIzqdo(n)!=Agen<tElto>::NODO_NULO){
			return gradoRec(A.hermDrcho(n),gradoMax,A),gradoRec(A.hijoIzqdo(n),gradoMax,A);
		}
		if(A.hermDrcho(n)!=Agen<tElto>::NODO_NULO ){
			return gradoRec(A.hermDrcho(n),gradoMax,A);
		}
		if(A.hijoIzqdo(n)!=Agen<tElto>::NODO_NULO){
			return gradoRec(A.hijoIzqdo(n),gradoMax,A);
		}
	}
}

int contar(typename Agen<tElto>::nodo n,Agen<tElto>& A){
	int grado;
	grado=0;
	while(n!=Agen<tElto>::NODO_NULO){
		grado++;
		n=A.hermDrcho(n);
	}
	return grado;
}

void Ej2(){
	Agen<tElto> A;
	rellenarAgen(A,fin);
	imprimirAgen(A);
	cout << "La profundidad del nodo es " << profundidad(A.hermDrcho(A.hijoIzqdo(A.hijoIzqdo(A.raiz()))),A) << endl;
}

int profundidad(Agen<tElto>::nodo n,Agen<tElto>& A){
	if(n==A.raiz()){
		return 0;
	}else{
		return 1+profundidad(A.padre(n),A);
	}
}

void Ej3(){
	Agen<tElto> A;
	rellenarAgen(A,fin);
	imprimirAgen(A);

}

void Ej4(){
	Agen<tElto> A;
	char x;
	rellenarAgen(A,fin);
	cout << "Nodo desde el que podar: ";
	cin >> x;
	cout << "Arbol original: " << endl;
	imprimirAgen(A);
	podar(x,A);
	cout << "Arbol podado: " << endl;
	imprimirAgen(A);
}

void podar(char x,Agen<tElto>& A){
	if(A.arbolVacio()){
		cout << "Arbol vacio." << endl;
		exit(0);
	}else{
		buscar(A.raiz(),x,A);
	}
}

void buscar(typename Agen<tElto>::nodo n,char x,Agen<tElto>& A){
	if(A.elemento(n)==x){
		if(A.hijoIzqdo(n)!=Agen<tElto>::NODO_NULO){
			podarRec(n,n,A);
		}else{
			cout << "El nodo no tiene descendientes." << endl;
			exit(0);
		}
	}else{
		if(A.hermDrcho(n)!=Agen<tElto>::NODO_NULO && A.hijoIzqdo(n)!=Agen<tElto>::NODO_NULO){
			buscar(A.hermDrcho(n),x,A),buscar(A.hijoIzqdo(n),x,A);
		}else if(A.hermDrcho(n)!=Agen<tElto>::NODO_NULO){
			buscar(A.hermDrcho(n),x,A);
		}else if(A.hijoIzqdo(n)!=Agen<tElto>::NODO_NULO){
			buscar(A.hijoIzqdo(n),x,A);
		}
	}
}

void podarRec(typename Agen<tElto>::nodo n,typename Agen<tElto>::nodo n1,Agen<tElto>& A){
	if(A.hijoIzqdo(n1)!=Agen<tElto>::NODO_NULO){
		if(A.hijoIzqdo(n)!=Agen<tElto>::NODO_NULO){
			if(A.hijoIzqdo(A.hijoIzqdo(n))==Agen<tElto>::NODO_NULO){
				A.eliminarHijoIzqdo(n);
				podarRec(n,n1,A);
			}else{
				podarRec(A.hijoIzqdo(n),n1,A);
			}
		}else{
			podarRec(A.padre(n),n1,A);
		}
	}
}










