#include"ABIN.hpp"
#include"abin_E-S.h"
#include<iostream>

typedef char tElto;
const tElto fin='#';

using namespace std;

//Ejercicio 1.
bool Similares(const Abin<tElto>& A,const Abin<tElto>& B);
int RecSimilares(typename Abin<tElto>::nodo na,typename Abin<tElto>::nodo nb,const Abin<tElto>& A,const Abin<tElto>& B);
//Extra.
bool Iguales(const Abin<tElto>& A,const Abin<tElto>& B);
int RecIguales(typename Abin<tElto>::nodo na,typename Abin<tElto>::nodo nb,const Abin<tElto>& A,const Abin<tElto>& B);
//Ejercicio 2.
void Reflejado(const Abin<tElto>& A,Abin<tElto>& B);
void RecReflejado(typename Abin<tElto>::nodo na,typename Abin<tElto>::nodo nb,const Abin<tElto>& A,Abin<tElto>& B);
//Extra2.
void Eliminar(Abin<tElto>& A,char x);
void Buscar(typename Abin<tElto>::nodo n,char x,Abin<tElto>& A);
void RecEliminar(typename Abin<tElto>::nodo n,typename Abin<tElto>::nodo n1,Abin<tElto>& A);

int main(){
	Abin<tElto> A;
	rellenarAbin(A,fin);
	cout << A.alturaB() << endl;
	return 0;
}

//Ejercicio 1.
bool Similares(const Abin<tElto>& A,const Abin<tElto>& B){
	if(A.raizB()==Abin<tElto>::NODO_NULO && B.raizB()==Abin<tElto>::NODO_NULO){
		return true;
	}
	if(A.raizB()==Abin<tElto>::NODO_NULO && B.raizB()!=Abin<tElto>::NODO_NULO ||
	   A.raizB()!=Abin<tElto>::NODO_NULO && B.raizB()==Abin<tElto>::NODO_NULO){
		return false;
	}
	if(A.raizB()!=Abin<tElto>::NODO_NULO && B.raizB()!=Abin<tElto>::NODO_NULO){
		if(RecSimilares(A.raizB(),B.raizB(),A,B)==0){
			return true;
		}else{
			return false;
		}
	}
}

int RecSimilares(typename Abin<tElto>::nodo na,typename Abin<tElto>::nodo nb,const Abin<tElto>& A,const Abin<tElto>& B){
	if(na!=Abin<tElto>::NODO_NULO && nb!=Abin<tElto>::NODO_NULO){
		return 0+RecSimilares(A.hijoIzqdoB(na),B.hijoIzqdoB(nb),A,B)+RecSimilares(A.hijoDrchoB(na),B.hijoDrchoB(nb),A,B);
	}else if(na==Abin<tElto>::NODO_NULO && nb==Abin<tElto>::NODO_NULO){
		return 0;
	}else{
		return 1;
	}
}

//Extra.
bool Iguales(const Abin<tElto>& A,const Abin<tElto>& B){
	if(A.raizB()==Abin<tElto>::NODO_NULO && B.raizB()==Abin<tElto>::NODO_NULO){
		return true;
	}
	if(A.raizB()==Abin<tElto>::NODO_NULO && B.raizB()!=Abin<tElto>::NODO_NULO ||
	   A.raizB()!=Abin<tElto>::NODO_NULO && B.raizB()==Abin<tElto>::NODO_NULO){
		return false;
	}
	if(A.raizB()!=Abin<tElto>::NODO_NULO && B.raizB()!=Abin<tElto>::NODO_NULO){
		if(RecIguales(A.raizB(),B.raizB(),A,B)==0){
			return true;
		}else{
			return false;
		}
	}
}

int RecIguales(typename Abin<tElto>::nodo na,typename Abin<tElto>::nodo nb,const Abin<tElto>& A,const Abin<tElto>& B){
	if(na!=Abin<tElto>::NODO_NULO && nb!=Abin<tElto>::NODO_NULO && A.elemento(na)==B.elemento(nb)){
		return 0+RecIguales(A.hijoIzqdoB(na),B.hijoIzqdoB(nb),A,B)+RecIguales(A.hijoDrchoB(na),B.hijoDrchoB(nb),A,B);
	}else if(na==Abin<tElto>::NODO_NULO && nb==Abin<tElto>::NODO_NULO){
		return 0;
	}else{
		return 1;
	}
}

//Ejercicio 2.
void Reflejado(const Abin<tElto>& A,Abin<tElto>& B){
	if(A.raizB()!=Abin<tElto>::NODO_NULO){
		B.insertarRaizB(A.elemento(A.raizB()));
		RecReflejado(A.raizB(),B.raizB(),A,B);
	}else{
		cout << "Arbol vacio." << endl;
		exit(0);
	}
}

void RecReflejado(typename Abin<tElto>::nodo na,typename Abin<tElto>::nodo nb,const Abin<tElto>& A,Abin<tElto>& B){
	if(A.hijoIzqdoB(na)!=Abin<tElto>::NODO_NULO){	//Si tiene hijoIzqdo, lo copia pero a la inversa.
		B.insertarHijoDrchoB(nb,A.elemento(A.hijoIzqdoB(na)));
		RecReflejado(A.hijoIzqdoB(na),B.hijoDrchoB(nb),A,B);
	}
	if(A.hijoDrchoB(na)!=Abin<tElto>::NODO_NULO){	//Si tiene hijoDrcho, lo copia pero a la inversa.
		B.insertarHijoIzqdoB(nb,A.elemento(A.hijoDrchoB(na)));
		RecReflejado(A.hijoDrchoB(na),B.hijoIzqdoB(nb),A,B);
	}
}

//Extra2.
void Eliminar(Abin<tElto>& A,char x){
	if(A.raizB()!=Abin<tElto>::NODO_NULO){
		Buscar(A.raizB(),x,A);
	}else{
		cout << "Arbol vacio." << endl;
	}
}

void Buscar(typename Abin<tElto>::nodo n,char x,Abin<tElto>& A){
	if(A.elemento(n)==x){
		RecEliminar(n,n,A);
	}else{
		if(A.hijoIzqdoB(n)!=Abin<tElto>::NODO_NULO){
			Buscar(A.hijoIzqdoB(n),x,A);
		}
		if(A.hijoDrchoB(n)!=Abin<tElto>::NODO_NULO){
			Buscar(A.hijoDrchoB(n),x,A);
		}
	}
}

void RecEliminar(typename Abin<tElto>::nodo n,typename Abin<tElto>::nodo n1,Abin<tElto>& A){
	if(n!=A.padreB(n1)){
		//Si su hijo no es nulo.
		if(A.hijoIzqdoB(n)!=Abin<tElto>::NODO_NULO){
			//Y si sus nietos son nulos, podemos borrar.
			if(A.hijoIzqdoB(A.hijoIzqdoB(n))==Abin<tElto>::NODO_NULO && A.hijoDrchoB(A.hijoIzqdoB(n))==Abin<tElto>::NODO_NULO){
				A.eliminarHijoIzqdoB(n);
				RecEliminar(A.padreB(n),n1,A);
			}else{
				RecEliminar(A.hijoIzqdoB(n),n1,A);
			}
		}
		if(A.hijoDrchoB(n)!=Abin<tElto>::NODO_NULO){
			//Y si sus nietos son nulos, podemos borrar.
			if(A.hijoDrchoB(A.hijoDrchoB(n))==Abin<tElto>::NODO_NULO && A.hijoIzqdoB(A.hijoDrchoB(n))==Abin<tElto>::NODO_NULO){
				A.eliminarHijoDrchoB(n);
				RecEliminar(A.padreB(n),n1,A);
			}else{
				RecEliminar(A.hijoDrchoB(n),n1,A);
			}
		}
	}
}
