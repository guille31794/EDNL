#include<iostream>
#include"ABIN.hpp"
#include"abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin='#';

//Ejercicio 1:
void Ej1();
int numNodos(typename Abin<tElto>::nodo n,Abin<tElto>& A);
//Ejercicio 2:
void Ej2();
int altura(Abin<tElto>& A);
int alturaRec(typename Abin<tElto>::nodo n,Abin<tElto>& A);
int Max(int a,int b);
//Ejercicio 3:
void Ej3();
int prof(typename Abin<tElto>::nodo n,Abin<tElto>& A);
//Ejercicio 7:
void Ej7();
int pseudo(Abin<tElto>& A);
int pseudoRec(typename Abin<tElto>::nodo n,int prof,Abin<tElto>& A);

int main(){
    Ej7();
	return 0;
}

void Ej1(){
	Abin<tElto> A;
	rellenarAbin(A,fin);
	imprimirAbin(A);
	cout << "El numero de nodos es " << numNodos(A.raizB(),A) << endl;
}

int numNodos(typename Abin<tElto>::nodo n,Abin<tElto>& A){
	if(n==Abin<tElto>::NODO_NULO){  //SI es nodo nulo, suma0.
		return 0;
	}else{  //Mientras no lo sea suma 1.
		return 1+numNodos(A.hijoIzqdoB(n),A)+numNodos(A.hijoDrchoB(n),A);
	}
}

void Ej2(){
	Abin<tElto> A;
	rellenarAbin(A,fin);
	imprimirAbin(A);
	cout << "La altura del arbol es " << altura(A) << endl;
}

int altura(Abin<tElto>& A){
	if(A.raizB()==Abin<tElto>::NODO_NULO){
		return 0;
	}else{
		return alturaRec(A.raizB(),A);
	}
}

int alturaRec(typename Abin<tElto>::nodo n,Abin<tElto>& A){
	if(n==Abin<tElto>::NODO_NULO){
		return 0;
	}else{
		return 1+Max(alturaRec(A.hijoIzqdoB(n),A),alturaRec(A.hijoDrchoB(n),A));
	}
}

int Max(int a,int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

void Ej3(){
	Abin<tElto> A;
	rellenarAbin(A,fin);
	imprimirAbin(A);
	cout << "La profundidad del nodo es " << prof(A.hijoDrchoB(A.hijoIzqdoB(A.hijoIzqdoB(A.raizB()))),A) << endl;
}

int prof(typename Abin<tElto>::nodo n,Abin<tElto>& A){
	if(n==A.raizB()){
		return 0;
	}else{
		return 1+prof(A.padreB(n),A);
	}
}

void Ej7(){
	Abin<tElto> A;
	rellenarAbin(A,fin);
	imprimirAbin(A);
    if(pseudo(A)!=0){
        cout << "El arbol es pseudocompleto.";
    }else{
        cout << "El arbol No es pseudocompleto.";
    }
}

int pseudo(Abin<tElto>& A){
	if(A.raizB()==Abin<tElto>::NODO_NULO){	//Si el arbol esta vacio no ejecuta.
		cout << "Arbol vacio." << endl;
		return 1;
	}else{
		return pseudoRec(A.raizB(),1,A);
	}
}

int pseudoRec(typename Abin<tElto>::nodo n,int prof,Abin<tElto>& A){
	if(prof==altura(A)-1 || altura(A)==1){	//Si nos encontramos en el penultimo nivel comprobamos para cada nodo.
		if(A.hijoIzqdoB(n)==Abin<tElto>::NODO_NULO && A.hijoDrchoB(n)==Abin<tElto>::NODO_NULO ||
		  (A.hijoIzqdoB(n)!=Abin<tElto>::NODO_NULO && A.hijoDrchoB(n)!=Abin<tElto>::NODO_NULO)){
			return 0;
		}else{
			return 1;
		}
	}else{	//Si no seguimos bajando.
        if(A.hijoIzqdoB(n)!=Abin<tElto>::NODO_NULO && A.hijoDrchoB(n)!=Abin<tElto>::NODO_NULO){
        	return 0+pseudoRec(A.hijoIzqdoB(n),prof+1,A),pseudoRec(A.hijoDrchoB(n),prof+1,A);
        }
		if(A.hijoIzqdoB(n)!=Abin<tElto>::NODO_NULO){
			return 0+pseudoRec(A.hijoIzqdoB(n),prof+1,A);
		}
		if(A.hijoDrchoB(n)!=Abin<tElto>::NODO_NULO){
			return 0+pseudoRec(A.hijoDrchoB(n),prof+1,A);
		}
	}
}















