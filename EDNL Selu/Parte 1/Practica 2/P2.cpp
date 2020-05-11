#include<iostream>
#include"ABIN.hpp"
#include"abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin='#';

//Ejercicio 1:
void Ej1();
bool similares(Abin<tElto>& A,Abin<tElto>& B);
int similaresRec(typename Abin<tElto>::nodo n1,typename Abin<tElto>::nodo n2,Abin<tElto>& A,Abin<tElto>& B);
//Ejercicio 2:
void Ej2();
void reflejado(Abin<tElto>& A,Abin<tElto>& B);
void reflejadoRec(typename Abin<tElto>::nodo n1,typename Abin<tElto>::nodo n2,Abin<tElto>& A,Abin<tElto>& B);

int main(){
	Ej1();
	return 0;
}

void Ej1(){
	Abin<tElto> A,B;
	rellenarAbin(A,fin);
	rellenarAbin(B,fin);
	if(similares(A,B)){
        cout << "Son similares." << endl;
	}else{
        cout << "No son similares." << endl;
	}
}

bool similares(Abin<tElto>& A,Abin<tElto>& B){
	if(A.raizB()==Abin<tElto>::NODO_NULO && B.raizB()==Abin<tElto>::NODO_NULO){
		cout << "Ambos arboles estan vacios." << endl;
		exit(0);
	}
	if(A.raizB()!=Abin<tElto>::NODO_NULO && B.raizB()==Abin<tElto>::NODO_NULO){
		cout << "Arbol A no es vacio y B si lo es." << endl;
		exit(0);
	}
	if(A.raizB()==Abin<tElto>::NODO_NULO && B.raizB()!=Abin<tElto>::NODO_NULO){
		cout << "Arbol B no es vacio y A si lo es." << endl;
		exit(0);
	}
	if(A.raizB()!=Abin<tElto>::NODO_NULO && B.raizB()!=Abin<tElto>::NODO_NULO){
		if(similaresRec(A.raizB(),B.raizB(),A,B)==0){
			return true;
		}else{
			return false;
		}
	}
}

int similaresRec(typename Abin<tElto>::nodo n1,typename Abin<tElto>::nodo n2,Abin<tElto>& A,Abin<tElto>& B){
	if(n1!=Abin<tElto>::NODO_NULO && n2!=Abin<tElto>::NODO_NULO){	//Si ambos son nulos o no nulos, bien.
		return 0+similaresRec(A.hijoIzqdoB(n1),B.hijoIzqdoB(n2),A,B),similaresRec(A.hijoDrchoB(n1),B.hijoDrchoB(n2),A,B);
	}else if(n1==Abin<tElto>::NODO_NULO && n2==Abin<tElto>::NODO_NULO){
		return 0;
	}else{	//En caso contrario mal.
		return 1;
	}
}

void Ej2(){
	Abin<tElto> A,B;
	rellenarAbin(A,fin);
	reflejado(A,B);
	cout << "Arbol original: \n";
    imprimirAbin(A);
	cout << "Arbol reflejado: \n";
	imprimirAbin(B);
}

void reflejado(Abin<tElto>& A,Abin<tElto>& B){
	if(A.raizB()!=Abin<tElto>::NODO_NULO){	//Si no es vacio, comienza copiando la raiz, unico elemento que permanecera en su lugar.
		B.insertarRaizB(A.elemento(A.raizB()));
		reflejadoRec(A.raizB(),B.raizB(),A,B);
	}else{	//Si esta vacio lo indica.
		cout << "Arbol vacio." << endl;
		exit(0);
	}
}

void reflejadoRec(typename Abin<tElto>::nodo n1,typename Abin<tElto>::nodo n2,Abin<tElto>& A,Abin<tElto>& B){
	if(A.hijoIzqdoB(n1)!=Abin<tElto>::NODO_NULO && A.hijoDrchoB(n1)!=Abin<tElto>::NODO_NULO){	//Si tiene hijoIzqdo e hijoDrcho, los copia pero a la inversa.
		B.insertarHijoDrchoB(n2,A.elemento(A.hijoIzqdoB(n1)));
		B.insertarHijoIzqdoB(n2,A.elemento(A.hijoDrchoB(n1)));
		return reflejadoRec(A.hijoIzqdoB(n1),B.hijoDrchoB(n2),A,B),reflejadoRec(A.hijoDrchoB(n1),B.hijoIzqdoB(n2),A,B);
	}
	if(A.hijoIzqdoB(n1)!=Abin<tElto>::NODO_NULO){	//Si tiene hijoIzqdo, lo copia pero a la inversa.
		B.insertarHijoDrchoB(n2,A.elemento(A.hijoIzqdoB(n1)));
		return reflejadoRec(A.hijoIzqdoB(n1),B.hijoDrchoB(n2),A,B);
	}
	if(A.hijoDrchoB(n1)!=Abin<tElto>::NODO_NULO){	//Si tiene hijoDrcho, lo copia pero a la inversa.
		B.insertarHijoIzqdoB(n2,A.elemento(A.hijoDrchoB(n1)));
		return reflejadoRec(A.hijoDrchoB(n1),B.hijoIzqdoB(n2),A,B);
	}
}
