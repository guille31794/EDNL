#include<iostream>
#include"ABIN.hpp"
#include"abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin='#';

//Equivalentes. Se dira que dos arboles son equivalentes si ademas de tener la misma estructura, tienen los mismo valores.
void Ej1();
bool equivalentes(Abin<tElto>& A,Abin<tElto>& B);
int equivalentesRec(typename Abin<tElto>::nodo n1,typename Abin<tElto>::nodo n2,Abin<tElto>& A,Abin<tElto>& B);
//Nodos verdes:
//Se define nodo verde como aquel que tiene exactamente 3 nietos. Contar el numero de nodos verdes que hay en un arbol.

void Ej2();
int verdes(Abin<tElto>& A);
int verdesRec(typename Abin<tElto>::nodo n,Abin<tElto>& A);
//Eliminar el desde el nodo x. El no incluido.
void Ej3();
void eliminar(char x,Abin<tElto>& A);
void buscar(typename Abin<tElto>::nodo n,char x,Abin<tElto>& A);
void eliminarRec(typename Abin<tElto>::nodo n,typename Abin<tElto>::nodo n1,Abin<tElto>& A);

int main(){
	Ej3();
    return 0;
}

void Ej1(){
	Abin<tElto> A,B;
	rellenarAbin(A,fin);
	rellenarAbin(B,fin);
	if(equivalentes(A,B)){
        cout << "Son equivalentes." << endl;
	}else{
        cout << "No son equivalentes." << endl;
	}
}

bool equivalentes(Abin<tElto>& A,Abin<tElto>& B){
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
		if(equivalentesRec(A.raizB(),B.raizB(),A,B)==0){
			return true;
		}else{
			return false;
		}
	}
}

int equivalentesRec(typename Abin<tElto>::nodo n1,typename Abin<tElto>::nodo n2,Abin<tElto>& A,Abin<tElto>& B){
	if((n1!=Abin<tElto>::NODO_NULO && n2!=Abin<tElto>::NODO_NULO) && (A.elemento(n1)==A.elemento(n2))){	//Si ambos son nulos o no nulos, bien. Si son no nulos se comprueba que sean iguales.
		return 0+equivalentesRec(A.hijoIzqdoB(n1),B.hijoIzqdoB(n2),A,B),equivalentesRec(A.hijoDrchoB(n1),B.hijoDrchoB(n2),A,B);
	}else if(n1==Abin<tElto>::NODO_NULO && n2==Abin<tElto>::NODO_NULO){
		return 0;
	}else{	//En caso contrario mal.
		return 1;
	}
}

void Ej2(){
	Abin<tElto> A;
	rellenarAbin(A,fin);
	imprimirAbin(A);
	cout << "El arbol tiene " << verdes(A) << " nodos verdes." << endl;
}

int verdes(Abin<tElto>& A){
	if(A.raizB()==Abin<tElto>::NODO_NULO){
		return 0;
	}else{
		return verdesRec(A.raizB(),A);
	}
}

int verdesRec(typename Abin<tElto>::nodo n,Abin<tElto>& A){
	if(A.hijoIzqdoB(n)!=Abin<tElto>::NODO_NULO && A.hijoDrchoB(n)!=Abin<tElto>::NODO_NULO){	//Si tiene hijo, comprueba que tenga 3 nietos.
		if(A.hijoIzqdoB(A.hijoIzqdoB(n))!=Abin<tElto>::NODO_NULO && A.hijoDrchoB(A.hijoIzqdoB(n))!=Abin<tElto>::NODO_NULO && A.hijoIzqdoB(A.hijoDrchoB(n))!=Abin<tElto>::NODO_NULO &&A.hijoDrchoB(A.hijoDrchoB(n))==Abin<tElto>::NODO_NULO ||
		   A.hijoIzqdoB(A.hijoIzqdoB(n))!=Abin<tElto>::NODO_NULO && A.hijoDrchoB(A.hijoIzqdoB(n))!=Abin<tElto>::NODO_NULO && A.hijoIzqdoB(A.hijoDrchoB(n))==Abin<tElto>::NODO_NULO &&A.hijoDrchoB(A.hijoDrchoB(n))!=Abin<tElto>::NODO_NULO ||
		   A.hijoIzqdoB(A.hijoIzqdoB(n))!=Abin<tElto>::NODO_NULO && A.hijoDrchoB(A.hijoIzqdoB(n))==Abin<tElto>::NODO_NULO && A.hijoIzqdoB(A.hijoDrchoB(n))!=Abin<tElto>::NODO_NULO &&A.hijoDrchoB(A.hijoDrchoB(n))!=Abin<tElto>::NODO_NULO ||
		   A.hijoIzqdoB(A.hijoIzqdoB(n))==Abin<tElto>::NODO_NULO && A.hijoDrchoB(A.hijoIzqdoB(n))!=Abin<tElto>::NODO_NULO && A.hijoIzqdoB(A.hijoDrchoB(n))!=Abin<tElto>::NODO_NULO &&A.hijoDrchoB(A.hijoDrchoB(n))!=Abin<tElto>::NODO_NULO){
			return 1+verdesRec(A.hijoIzqdoB(n),A)+verdesRec(A.hijoDrchoB(n),A);
		}
	}else if(A.hijoIzqdoB(n)!=Abin<tElto>::NODO_NULO){	//Si solo tiene un hijo, simplemente lo devuelve.
		return verdesRec(A.hijoIzqdoB(n),A);
	}else if(A.hijoDrchoB(n)!=Abin<tElto>::NODO_NULO){
		return verdesRec(A.hijoDrchoB(n),A);
	}else{
		return 0;
	}
}

void Ej3(){
	Abin<tElto> A,B;
	char x;
	rellenarAbin(A,fin);
	imprimirAbin(A);
	cout << "Introduzca el nodo desde el que eliminar: ";
	cin >> x;
	eliminar(x,A);
	imprimirAbin(A);
}

void eliminar(char x,Abin<tElto>& A){
	buscar(A.raizB(),x,A);
}

void buscar(typename Abin<tElto>::nodo n,char x,Abin<tElto>& A){
	if(A.elemento(n)==x){
			eliminarRec(n,n,A);
	}else{
		if(A.hijoIzqdoB(n)!=Abin<tElto>::NODO_NULO && A.hijoDrchoB(n)!=Abin<tElto>::NODO_NULO){
			buscar(A.hijoIzqdoB(n),x,A),buscar(A.hijoDrchoB(n),x,A);
		}else if(A.hijoIzqdoB(n)!=Abin<tElto>::NODO_NULO){
			buscar(A.hijoIzqdoB(n),x,A);
		}else if(A.hijoDrchoB(n)!=Abin<tElto>::NODO_NULO){
			buscar(A.hijoDrchoB(n),x,A);;
		}
	}
}

void eliminarRec(typename Abin<tElto>::nodo n,typename Abin<tElto>::nodo n1,Abin<tElto>& A){
	if(n!=A.padreB(n1)){
		if(A.hijoIzqdoB(n)!=Abin<tElto>::NODO_NULO){
			if(A.hijoIzqdoB(A.hijoIzqdoB(n))==Abin<tElto>::NODO_NULO && A.hijoDrchoB(A.hijoIzqdoB(n))==Abin<tElto>::NODO_NULO){
				A.eliminarHijoIzqdoB(n);
				eliminarRec(n,n1,A);
			}else{
				eliminarRec(A.hijoIzqdoB(n),n1,A);
			}
		}
		if(A.hijoDrchoB(n)!=Abin<tElto>::NODO_NULO){
			if(A.hijoIzqdoB(A.hijoDrchoB(n))==Abin<tElto>::NODO_NULO && A.hijoDrchoB(A.hijoDrchoB(n))==Abin<tElto>::NODO_NULO){
				A.eliminarHijoDrchoB(n);
				eliminarRec(n,n1,A);
			}else{
				eliminarRec(A.hijoDrchoB(n),n1,A);
			}
		}
	}
}

