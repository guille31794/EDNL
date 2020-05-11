#include<iostream>
#include"ABB.hpp"
#include"abb_Es.h"

using namespace std;
typedef int tElto;
const tElto fin=0;

//Ejercicio 1:
void Ej1();
void borrar(int x,Abb<tElto>& A);
void borrarRec(Abb<tElto>& B,Abb<tElto>& A);

int main(){
	Ej1();
	return 0;
}

void Ej1(){
	Abb<tElto> A;
	int x;
	rellenarAbb(A,fin);
	cout << "Numero a borrar: ";
	cin >> x;
	imprimirAbb(A);
	borrar(x,A);
	imprimirAbb(A);
}

void borrar(int x,Abb<tElto>& A){
	if(!A.vacio()){
		Abb<tElto> B;
		B=A.buscar(x);
		if(!B.vacio()){
			borrarRec(B,A);
		}else{
			cout << "El elemento " << x << " no existe en el arbol." << endl;
			exit(0);
		}
	}else{
		cout << "Arbol vacio." << endl;
		exit(0);
	}
}

void borrarRec(Abb<tElto>& B,Abb<tElto>& A){
	if(!B.vacio()){
		A.eliminar(B.elemento());
		B.eliminar(B.elemento());
		borrarRec(B,A);
	}
}




