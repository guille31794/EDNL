#include"AGEN.hpp"
#include"agen_E-S.h"
#include<iostream>

typedef char tElto;
const tElto fin='#';

using namespace std;

//Ejercicio 1.
int Grado(const Agen<tElto>& A);
void RecGrado(typename Agen<tElto>::nodo n,int &max,const Agen<tElto>& A);
int Num(typename Agen<tElto>::nodo n,const Agen<tElto>& A);
//Ejercicio 2.
int Altura(const Agen<tElto>& A);
int RecAltura(typename Agen<tElto>::nodo n,const Agen<tElto>& A);
int Max(int a,int b);
//Ejercicio 3.
int Desequilibrio(const Agen<tElto>& A);
int RecDesequilibrio(typename Agen<tElto>::nodo n,const Agen<tElto>& A);
int Min(int a,int b);
//Ejercicio 4.
void Podar(char x,Agen<tElto>& A);
void Buscar(typename Agen<tElto>::nodo n,char x,Agen<tElto>& A);
void RecPodar(typename Agen<tElto>::nodo n,typename Agen<tElto>::nodo n1,Agen<tElto>& A);

int main(){
	Agen<tElto> A;
	rellenarAgen(A,fin);
    cout << Desequilibrio(A) << endl;
	return 0;
}

//Ejercicio 1.
int Grado(const Agen<tElto>& A){
	if(A.raiz()==Agen<tElto>::NODO_NULO){
		return 0;
	}else{
		int max=0;
		RecGrado(A.raiz(),max,A);
		return max;
	}
}

void RecGrado(typename Agen<tElto>::nodo n,int &max,const Agen<tElto>& A){
	if(n!=Agen<tElto>::NODO_NULO){
		if(Num(n,A)>max){
			max=Num(n,A);
		}
		RecGrado(A.hijoIzqdo(n),max,A),RecGrado(A.hermDrcho(n),max,A);
	}
}

int Num(typename Agen<tElto>::nodo n,const Agen<tElto>& A){
	int i=0;
	while(n!=Agen<tElto>::NODO_NULO){
		n=A.hermDrcho(n);
		i++;
	}
	return i;
}

//Ejercicio 2.
int Altura(const Agen<tElto>& A){
	if(A.raiz()==Agen<tElto>::NODO_NULO){
		return 0;
	}else{
		return RecAltura(A.raiz(),A);
	}
}

int RecAltura(typename Agen<tElto>::nodo n,const Agen<tElto>& A){
	if(n==Agen<tElto>::NODO_NULO){
		return 0;
	}else{
		return Max(RecAltura(A.hijoIzqdo(n),A)+1,RecAltura(A.hermDrcho(n),A)+0);
	}
}

int Max(int a,int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

//Ejercicio 3.
int Desequilibrio(const Agen<tElto>& A){
	if(A.arbolVacio()){
		cout << "Arbol vacio." << endl;
		exit(0);
	}else{
		return Altura(A)-RecDesequilibrio(A.raiz(),A);
	}
}

int RecDesequilibrio(typename Agen<tElto>::nodo n,const Agen<tElto>& A){
	if(n==Agen<tElto>::NODO_NULO){
		return 0;
	}else{
		return Min(RecDesequilibrio(A.hijoIzqdo(n),A)+1,RecDesequilibrio(A.hermDrcho(n),A)+0);
	}
}

int Min(int a,int b){
	if(a!=0 && b!=0){
		if(a>b){
			return b;
		}else{
			return a;
		}
	}
}

//Ejercicio 4.
void Podar(char x,Agen<tElto>& A){
	if(A.arbolVacio()){
		cout << "Arbol vacio." << endl;
		exit(0);
	}else{
		Buscar(A.raiz(),x,A);
	}
}

void Buscar(typename Agen<tElto>::nodo n,char x,Agen<tElto>& A){
	if(A.elemento(n)==x){
		RecPodar(n,n,A);
	}else{
		if(A.hermDrcho(n)!=Agen<tElto>::NODO_NULO && A.hijoIzqdo(n)!=Agen<tElto>::NODO_NULO){
			Buscar(A.hermDrcho(n),x,A),Buscar(A.hijoIzqdo(n),x,A);
		}else if(A.hermDrcho(n)!=Agen<tElto>::NODO_NULO){
			Buscar(A.hermDrcho(n),x,A);
		}else if(A.hijoIzqdo(n)!=Agen<tElto>::NODO_NULO){
			Buscar(A.hijoIzqdo(n),x,A);
		}
	}
}

void RecPodar(typename Agen<tElto>::nodo n,typename Agen<tElto>::nodo n1,Agen<tElto>& A){
	if(A.hijoIzqdo(n1)!=Agen<tElto>::NODO_NULO){
		if(A.hijoIzqdo(n)!=Agen<tElto>::NODO_NULO){
			if(A.hijoIzqdo(A.hijoIzqdo(n))==Agen<tElto>::NODO_NULO){
				A.eliminarHijoIzqdo(n);
				RecPodar(n,n1,A);
			}else{
				RecPodar(A.hijoIzqdo(n),n1,A);
			}
		}else{
			RecPodar(A.padre(n),n1,A);
		}
	}
}
