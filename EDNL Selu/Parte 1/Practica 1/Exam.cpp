#include"ABIN.hpp"
#include"abin_E-S.h"
#include<iostream>
#include<cstdlib>

typedef char tElto;
const tElto fin='#';

using namespace std;

//Ejercicio 1.
int Contar(const Abin<tElto>& A);
int RecContar(typename Abin<tElto>::nodo n,const Abin<tElto>& A);
//Ejercicio 2.
int Altura(const Abin<tElto>& A);
int RecAltura(typename Abin<tElto>::nodo n,const Abin<tElto>& A);
int Max(int a,int b);
//Ejercicio 3.
int Prof(typename Abin<tElto>::nodo n,const Abin<tElto>& A);
//Ejercicio 6.
int Desequilibrio(const Abin<tElto>& A);
int RecDesequilibrio(typename Abin<tElto>::nodo n,const Abin<tElto>& A);
int Min(int a,int b);
//Ejercicio 7.
int Pseudo(const Abin<tElto>& A);
int RecPseudo(typename Abin<tElto>::nodo n,int prof,const Abin<tElto>& A);

int main(){
	Abin<tElto> A;
	rellenarAbin(A,fin);
	cout << Desequilibrio(A) << endl;
	return 0;
}

//Ejercicio 1.
int Contar(const Abin<tElto>& A){
	if(A.raizB()==Abin<tElto>::NODO_NULO){
		return 0;
	}else{
		return RecContar(A.raizB(),A);
	}
}

int RecContar(typename Abin<tElto>::nodo n,const Abin<tElto>& A){
	if(n==Abin<tElto>::NODO_NULO){
		return 0;
	}else{
        return 1+RecContar(A.hijoIzqdoB(n),A)+RecContar(A.hijoDrchoB(n),A);
	}
}

//Ejercicio 2.
int Altura(const Abin<tElto>& A){
	if(A.raizB()==Abin<tElto>::NODO_NULO){
		return 0;
	}else{
		return RecAltura(A.raizB(),A);
	}
}

int RecAltura(typename Abin<tElto>::nodo n,const Abin<tElto>& A){
	if(n==Abin<tElto>::NODO_NULO){
		return 0;
	}else{
		return 1+Max(RecAltura(A.hijoIzqdoB(n),A),RecAltura(A.hijoDrchoB(n),A));
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
int Prof(typename Abin<tElto>::nodo n,const Abin<tElto>& A){
	if(n==A.raizB()){
		return 0;
	}else{
		return 1+Prof(A.padreB(n),A);
	}
}

//Ejercicio 6.
int Desequilibrio(const Abin<tElto>& A){
	if(A.raizB()==Abin<tElto>::NODO_NULO){
		return 0;
	}else{
		int n=RecDesequilibrio(A.raizB(),A);
		return Altura(A)-n;
	}
}

int RecDesequilibrio(typename Abin<tElto>::nodo n,const Abin<tElto>& A){
	if(n==Abin<tElto>::NODO_NULO){
		return 0;
	}else{
		return 1+Min(RecDesequilibrio(A.hijoIzqdoB(n),A),RecDesequilibrio(A.hijoDrchoB(n),A));
	}
}

int Min(int a,int b){
	if(a>b){
		return b;
	}else{
		return a;
	}
}

//Ejercicio 7.
int Pseudo(const Abin<tElto>& A){
	if(A.raizB()==Abin<tElto>::NODO_NULO){
		cout << "Arbol vacio." << endl;
		exit(0);
	}else{
		return RecPseudo(A.raizB(),1,A);
	}
}

int RecPseudo(typename Abin<tElto>::nodo n,int prof,const Abin<tElto>& A){
	//Bajamos hasta el ultimo nivel, puede ser el nodo raiz.
	if(prof==Altura(A)-1 || Altura(A)==1){
		if((A.hijoIzqdoB(n)==Abin<tElto>::NODO_NULO && A.hijoDrchoB(n)==Abin<tElto>::NODO_NULO) ||
		   (A.hijoIzqdoB(n)!=Abin<tElto>::NODO_NULO && A.hijoDrchoB(n)!=Abin<tElto>::NODO_NULO)){
			return 0;
		}else{
			return 1;
		}
	}else{
		//Si no seguimos bajando.
		if(A.hijoIzqdoB(n)!=Abin<tElto>::NODO_NULO && A.hijoDrchoB(n)!=Abin<tElto>::NODO_NULO){
			return 0+RecPseudo(A.hijoIzqdoB(n),prof+1,A),RecPseudo(A.hijoDrchoB(n),prof+1,A);
		}
		if(A.hijoIzqdoB(n)!=Abin<tElto>::NODO_NULO){
			return 0+RecPseudo(A.hijoIzqdoB(n),prof+1,A);
		}
		if(A.hijoDrchoB(n)!=Abin<tElto>::NODO_NULO){
			return 0+RecPseudo(A.hijoDrchoB(n),prof+1,A);
		}
	}
}
