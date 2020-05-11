#include"ABB.hpp"
#include"abb_Es.h"
#include<iostream>

typedef int tElto;
const tElto fin=0;

using namespace std;

void Podar(int x,Abb<tElto>& A);
void RecPodar(Abb<tElto>& A,Abb<tElto>& B);

int main(){
	Abb<tElto> A;
	rellenarAbb(A,fin);
	int x=9;
	cout << "Original: " << endl;
	imprimirAbb(A);
	Podar(x,A);
	cout << "Podado: " << endl;
	imprimirAbb(A);
	return 0;
}

void Podar(int x,Abb<tElto>& A){
    Abb<tElto> B=A.buscar(x);
    if(B.vacio()){
        cout << "Elemento no encontrado." << endl;
    }else{
        RecPodar(A,B);
	}
}

void RecPodar(Abb<tElto>& A,Abb<tElto>& B){
	if(!B.vacio()){
		A.eliminar(B.elemento());
		B.eliminar(B.elemento());
		RecPodar(A,B);
	}
}
