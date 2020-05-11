#include"alg_grafoPMC.h"
#include<iostream>

using namespace std;

//Ejercicio 4.
void Ejercicio4();
template <typename tCoste>
tCoste Recorrido(const vector<int> Parte,const typename GrafoP<tCoste>::vertice Capital,const GrafoP<tCoste>& G);
//Ejercicio 5.
void Ejercicio5();
template <typename tCoste>
void PuedeLlegar(const typename GrafoP<tCoste>::vertice Capital,tCoste Presupuesto,const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2);
//Ejercicio 6.
void Ejercicio6();
template <typename tCoste>
void Opciones(const typename GrafoP<tCoste>::vertice Inicio,const typename GrafoP<tCoste>::vertice Destino,const typename GrafoP<tCoste>::vertice Cambio,
		      const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2);
//Ejercicio 7.
void Ejercicio7();
template <typename tCoste>
void mejorOpcion(const typename GrafoP<tCoste>::vertice Inicio,const typename GrafoP<tCoste>::vertice Destino,const typename GrafoP<tCoste>::vertice C1,
	             const typename GrafoP<tCoste>::vertice C2,const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2);
//Ejercicio 8.
void Ejercicio8();
template <typename tCoste>
void mejorOpcion(const typename GrafoP<tCoste>::vertice Origen,const typename GrafoP<tCoste>::vertice Destino,
	             const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2);
//Ejercicio 9.
void Ejercicio9();
template <typename tCoste>
void hacer(const typename GrafoP<tCoste>::vertice Origen,const typename GrafoP<tCoste>::vertice Destino,tCoste taxi,
	       const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2);
//Ejercicio 10.
void Ejercicio10();
template <typename tCoste>
void mejorOpcionentre3(const typename GrafoP<tCoste>::vertice Origen,const typename GrafoP<tCoste>::vertice Destino,tCoste taxia,tCoste taxib,
	                   const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2,const GrafoP<tCoste>& G3);
//Ejercicio 11.
void Ejercicio11();
template <typename tCoste>
void verIslas(const matriz<bool>& M,const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2,const GrafoP<tCoste>& G3);
//Ejercicio 12.
void Ejercicio12();
template <typename tCoste>
void mejorPuente(const vector<bool>& Costeras,const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2);
template <typename tCoste>
tCoste countFloyd(const GrafoP<tCoste>& M,size_t k);
//Ejercicio 13.
void Ejercicio13();
template <typename tCoste>
void mejoresPuentes(const vector<bool>& Costeras,const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2,const GrafoP<tCoste>& G3);

int main()
{
	Ejercicio7();
	return 0;
}

//Ejercicio 4.
void Ejercicio4()
{
	string a="Zuelandia.txt";
	GrafoP<int> G(a);

	//Inicializamos capital.
	typename GrafoP<int>::vertice Capital=0;

	//Inicializamos el parte de trabajo.
	vector<int> Parte(G.numVert());
	Parte[0]=0;
	Parte[1]=3;
	Parte[2]=12;
	Parte[3]=1;
	Parte[4]=10;
	Parte[5]=1;
	Parte[6]=9;
	cout << "Se realizan un total de " << Recorrido(Parte,Capital,G) << " km." << endl;
}

template <typename tCoste>
tCoste Recorrido(const vector<int> Parte,const typename GrafoP<tCoste>::vertice Capital,const GrafoP<tCoste>& G)
{
	typedef typename GrafoP<tCoste>::vertice vertices;

	vector<vertices> X;
	vector<tCoste> alaCapital=DijkstraInv(G,Capital,X);
	vector<tCoste> delaCapital=Dijkstra(G,Capital,X);
	int recorrido=0;
	for(size_t i=0;i<G.numVert();i++)
	{
		recorrido=recorrido+suma(alaCapital[i],delaCapital[i])*Parte[i];
	}
	return recorrido;
}

//Ejercicio 5.
void Ejercicio5()
{
	string a="Zuelandia Avion.txt";
	string b="Zuelandia Coche.txt";
	string c="Zuelandia Tren.txt";
	GrafoP<int> G1(a);
	GrafoP<int> G2(b);
	GrafoP<int> G3(c);

	//Definimos punto de salida.
	typename GrafoP<int>::vertice Capital=0;

	//Inicializamos presupuesto.
	int Presupuesto=40;

	//Funcion solo mandando dos grafos.
	PuedeLlegar(Capital,Presupuesto,G1,G2);
}

template <typename tCoste>
void PuedeLlegar(const typename GrafoP<tCoste>::vertice Capital,tCoste Presupuesto,const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2)
{
	typedef typename GrafoP<tCoste>::vertice vertices;
	vector<vertices> X;

	vector<tCoste> Va=Dijkstra(G1,Capital,X);
	vector<tCoste> Vb=Dijkstra(G2,Capital,X);

	for(size_t i=0;i<G1.numVert();i++)
	{
		if(i!=Capital && (Va[i]<=Presupuesto || Vb[i]<=Presupuesto))
		{
			cout << "Se puede llegar a la ciudad " << i << "." << endl;
		}
	}
}

//Ejercicio 6.
void Ejercicio6()
{
	string a="Espana Tren.txt";
	string b="Espana Bus.txt";
	GrafoP<int> G1(a);
	GrafoP<int> G2(b);

	//Definimos el inicio y la ciudad de cambio.
	typename GrafoP<int>::vertice Inicio=0,Destino=2,Cambio=3;

	cout << "Tren: " << endl;
	cout << G1 << endl;
	cout << "Bus: " << endl;
	cout << G2 << endl;

	Opciones(Inicio,Destino,Cambio,G1,G2);
}

template <typename tCoste>
void Opciones(const typename GrafoP<tCoste>::vertice Inicio,const typename GrafoP<tCoste>::vertice Destino,const typename GrafoP<tCoste>::vertice Cambio,
	          const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2)
{
	tCoste minimo=GrafoP<tCoste>::INFINITO;
	size_t opcion=0;

	typedef typename GrafoP<tCoste>::vertice vertices;
	vector<vertices> X;

	//Opcion solo tren.
	vector<tCoste> R1=Dijkstra(G1,Inicio,X);
	if(R1[Destino]<minimo)
	{
		minimo=R1[Destino];
		opcion=1;
	}

	//Opcion solo bus.
	vector<tCoste> R2=Dijkstra(G2,Inicio,X);
	if(R2[Destino]<minimo)
	{
		minimo=R2[Destino];
		opcion=2;
	}

	//Opcion Tren-Bus.
	vector<tCoste> R3=Dijkstra(G2,Cambio,X);
	if(R1[Cambio]+R3[Destino]<minimo)
	{
		minimo=R1[Cambio]+R3[Destino];
		opcion=3;
	}

	//Opcion Bus-Tren.
	vector<tCoste> R4=Dijkstra(G1,Cambio,X);
	if(R2[Cambio]+R4[Destino]<minimo)
	{
		minimo=R2[Cambio]+R4[Destino];
		opcion=4;
	}

	cout << "El coste minimo es " << minimo << " km con la opcion " << opcion << "." << endl;
}

//Ejercicio 7.
void Ejercicio7()
{
	string a="Espana tren.txt";
	string b="Espana Bus.txt";
	GrafoP<int> G1(a);
	GrafoP<int> G2(b);

	typedef typename GrafoP<int>::vertice vertice;
	vertice Origen=0,Destino=1;
	vertice C1=4,C2=3;

	//Tenemos dos opciones.
	mejorOpcion(Origen,Destino,C1,C2,G1,G2);
}

template <typename tCoste>
void mejorOpcion(const typename GrafoP<tCoste>::vertice Inicio,const typename GrafoP<tCoste>::vertice Destino,const typename GrafoP<tCoste>::vertice C1,
	             const typename GrafoP<tCoste>::vertice C2,const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2)
{
	tCoste minimo=GrafoP<tCoste>::INFINITO;
	size_t opcion=0;

	typedef typename GrafoP<tCoste>::vertice vertices;
	vector<vertices> X;

	//Opcion C1.
	vector<tCoste> Op1a=Dijkstra(G1,Inicio,X);
	vector<tCoste> Op1b=Dijkstra(G2,C1,X);
	if(Op1a[C1]+Op1b[Destino]<minimo)
	{
		minimo=Op1a[C1]+Op1b[Destino];
		opcion=1;
	}

	//Opcion C2.
	vector<tCoste> Op2=Dijkstra(G2,C2,X);
	if(Op1a[C2]+Op2[Destino]<minimo)
	{
		minimo=Op1a[C2]+Op2[Destino];
		opcion=2;
	}

	cout << "El coste es: " << minimo << " y se obtiene con la ruta: " << opcion << ": ";
	cout << Inicio << "-";
	if(opcion==1)
	{
		cout << C1 << "-";
	}else
	{
		cout << C2 << "-";
	}
	cout << Destino << endl;
	/*
	typename GrafoP<tCoste>::tCamino camino=camino(Inicio,Destino,X);
	typename GrafoP<tCoste>::tCamino::posicion p=camino.primera();
	while(p!=camino.fin())
	{
		cout << camino.elemento(p) << " ";
		p=camino.siguiente(p);
	}*/
}

//Ejercicio 8.
void Ejercicio8()
{
	string a="Espana Tren.txt";
	string b="Espana Bus.txt";
	GrafoP<int> G1(a);
	GrafoP<int> G2(b);

	typename GrafoP<int>::vertice Origen=0,Destino=2;
	mejorOpcion(Origen,Destino,G1,G2);
}

template <typename tCoste>
void mejorOpcion(const typename GrafoP<tCoste>::vertice Origen,const typename GrafoP<tCoste>::vertice Destino,
	             const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2)
{
	typedef typename GrafoP<tCoste>::vertice vertice;

	tCoste minimo=GrafoP<tCoste>::INFINITO;
	vertice Cambio=-1;

	vector<vertice> X;

	vector<tCoste> Op1=Dijkstra(G1,Origen,X);
	vector<tCoste> Op2=Dijkstra(G2,Origen,X);
	vector<tCoste> Op3;
	for(vertice i=0;i<G1.numVert();i++)
	{
		Op3=Dijkstra(G2,i,X);
		if(Op1[i]+Op3[Destino]<minimo)
		{
			minimo=Op1[i]+Op3[Destino];
			Cambio=i;
		}
		Op3=Dijkstra(G1,i,X);
		if(Op2[i]+Op3[Destino]<minimo)
		{
			minimo=Op2[i]+Op3[Destino];
			Cambio=i;
		}
	}
	cout << "El coste es " << minimo << endl;
	if(Cambio!=-1 && Cambio!=Origen)
	{
		cout << "La ruta es: " << Origen << "-" << Cambio << "-" << Destino << endl;
	}
}

//Ejercicio 9.
void Ejercicio9()
{
	string a="Espana Tren.txt";
	string b="Espana Bus.txt";
	GrafoP<int> G1(a);
	GrafoP<int> G2(b);

	typename GrafoP<int>::vertice Origen=0,Destino=5;
	int taxi=5;

	cout << "Tren:" << endl;
	cout << G1 << endl;
	cout << "Bus:" << endl;
	cout << G2 << endl;
	hacer(Origen,Destino,taxi,G1,G2);
}

template <typename tCoste>
void hacer(const typename GrafoP<tCoste>::vertice Origen,const typename GrafoP<tCoste>::vertice Destino,tCoste taxi,
	       const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2)
{
	GrafoP<tCoste> G(G1.numVert()+G2.numVert());

	for(size_t i=0;i<G1.numVert();i++)
	{
		for(size_t j=0;j<G1.numVert();j++)
		{
			G[i][j]=G1[i][j];
		}
	}

	size_t i=0;
	for(size_t j=G1.numVert();j<G1.numVert()+G2.numVert();j++){
		G[i][j]=taxi;
		i++;
	}

	i=G1.numVert();
	for(size_t j=0;j<G1.numVert();j++){
		G[i][j]=taxi;
		i++;
	}

	for(size_t i=G1.numVert();i<G1.numVert()+G2.numVert();i++)
	{
		for(size_t j=G1.numVert();j<G1.numVert()+G2.numVert();j++)
		{
			G[i][j]=G2[i-G1.numVert()][j-G1.numVert()];
		}
	}

	cout << "El grafo queda:" << endl;
	cout << G << endl;

	typedef typename GrafoP<tCoste>::vertice vertices;

	vector<vertices> R1,R2,R;
	vector<tCoste> M1=Dijkstra(G,Origen,R1);
	vector<tCoste> M2=Dijkstra(G,Origen+G1.numVert(),R2);


	if(M1[Destino]<M2[Destino+G1.numVert()])
	{
		cout << "Es mas optimo empezar por Tren." << endl;
		cout << "El coste es de " << M1[Destino] << endl;
		R=R1;
	}else
	{
		cout << "Es mas optimo empezar por Bus." << endl;
		cout << "El coste es de " << M2[Destino+G1.numVert()] << endl;
		R=R2;
	}
	cout << "La ruta es: ";
	for(size_t i=0;i<R.size();i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
}

//Ejercicio 10.
void Ejercicio10()
{
	string a="Espana Tren.txt";
	string b="Espana Bus.txt";
	string c="Espana Avion.txt";
	GrafoP<int> G1(a);
	GrafoP<int> G2(b);
	GrafoP<int> G3(c);

	typename GrafoP<int>::vertice Origen=3,Destino=2;
	int taxia=3,taxib=7;
	mejorOpcionentre3(Origen,Destino,taxia,taxib,G1,G2,G3);
}

template <typename tCoste>
void mejorOpcionentre3(const typename GrafoP<tCoste>::vertice Origen,const typename GrafoP<tCoste>::vertice Destino,tCoste taxia,tCoste taxib,
	                   const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2,const GrafoP<tCoste>& G3)
{
	GrafoP<tCoste> G(G1.numVert()+G2.numVert()+G3.numVert());

	for(size_t i=0;i<G1.numVert();i++)
	{
		for(size_t j=0;j<G1.numVert();j++)
		{
			G[i][j]=G1[i][j];
		}
	}

	size_t i=0;
	for(size_t j=G1.numVert();j<G1.numVert()+G2.numVert();j++)
	{
		G[i][j]=taxia;
		i++;
	}

	i=0;
	for(size_t j=G1.numVert()+G2.numVert();j<G1.numVert()+G2.numVert()+G3.numVert();j++)
	{
		G[i][j]=taxib;
		i++;
	}

	i=G1.numVert();
	for(size_t j=0;j<G1.numVert();j++)
	{
		G[i][j]=taxia;
		i++;
	}

	for(size_t i=G1.numVert();i<G1.numVert()+G2.numVert();i++)
	{
		for(size_t j=G1.numVert();j<G1.numVert()+G2.numVert();j++)
		{
			G[i][j]=G2[i-G1.numVert()][j-G1.numVert()];
		}
	}

	i=G1.numVert();
	for(size_t j=G1.numVert()+G2.numVert();j<G1.numVert()+G2.numVert()+G3.numVert();j++)
	{
		G[i][j]=taxib;
		i++;
	}

	i=G1.numVert()+G2.numVert();
	for(size_t j=0;j<G1.numVert();j++)
	{
		G[i][j]=taxib;
		i++;
	}

	i=G1.numVert()+G2.numVert();
	for(size_t j=G1.numVert();j<G1.numVert()+G2.numVert();j++)
	{
		G[i][j]=taxib;
		i++;
	}

	for(size_t i=G1.numVert()+G2.numVert();i<G1.numVert()+G2.numVert()+G3.numVert();i++)
	{
		for(size_t j=G1.numVert()+G2.numVert();j<G1.numVert()+G2.numVert()+G3.numVert();j++)
		{
			G[i][j]=G3[i-(G1.numVert()+G2.numVert())][j-(G1.numVert()+G2.numVert())];
		}
	}

	cout << "Tren:" << endl;
	cout << G1 << endl;
	cout << "Bus:" << endl;
	cout << G2 << endl;
	cout << "Avion:" << endl;
	cout << G3 << endl;
	cout << "Total:" << endl;
	cout << G << endl;

	typedef typename GrafoP<tCoste>::vertice vertices;

	vector<vertices> R1,R2,R3,R;
	vector<tCoste> M1=Dijkstra(G,Origen,R1);
	vector<tCoste> M2=Dijkstra(G,Origen+G1.numVert(),R2);
	vector<tCoste> M3=Dijkstra(G,Origen+G1.numVert()+G2.numVert(),R3);

	if(M1[Destino]<M2[Destino+G1.numVert()])
	{
		if(M1[Destino]<M3[Destino+G1.numVert()+G2.numVert()])
		{
			cout << "Mejor empezar en Tren." << endl;
			cout << "El coste es " << M1[Destino] << "." << endl;
			R=R1;
		}else
		{
			cout << "Mejor empezar en Avion." << endl;
			cout << "El coste es " << M3[Destino+G1.numVert()+G2.numVert()] << "." << endl;
			R=R3;
		}
	}else
	{
		if(M2[Destino+G1.numVert()]<M3[Destino+G1.numVert()+G2.numVert()])

		{
			cout << "Mejor empezar en Bus." << endl;
			cout << "El coste es " << M2[Destino+G1.numVert()] << "." << endl;
			R=R2;
		}else
		{
			cout << "Mejor empezar en Avion." << endl;
			cout << "El coste es " << M3[Destino+G1.numVert()+G2.numVert()] << "." << endl;
			R=R3;
		}
	}

	cout << "La ruta es: ";
	for(size_t i=0;i<R.size();i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
}

//Ejercicio 11.
void Ejercicio11()
{
	string a="Isla1.txt";
	string b="Isla2.txt";
	string c="Isla3.txt";
	GrafoP<int> G1(a);
	GrafoP<int> G2(b);
	GrafoP<int> G3(c);

	matriz<bool> M(G1.numVert()+G2.numVert()+G3.numVert(),false);
	M[0][6]=true;
	M[7][11]=true;
	verIslas(M,G1,G2,G3);
}

template <typename tCoste>
void verIslas(const matriz<bool>& M,const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2,const GrafoP<tCoste>& G3)
{
	GrafoP<tCoste> G(G1.numVert()+G2.numVert()+G3.numVert());

	for(size_t i=0;i<G1.numVert()+G2.numVert()+G3.numVert();i++)
	{
		for(size_t j=0;j<G1.numVert()+G2.numVert()+G3.numVert();j++)
		{
			if(M[i][j]==true || M[j][i]==true)
			{
				G[i][j]=0;
			}else
			{
				G[i][j]=GrafoP<tCoste>::INFINITO;
			}
		}
	}

	for(size_t i=0;i<G1.numVert();i++)
	{
		for(size_t j=0;j<G1.numVert();j++)
		{
			G[i][j]=G1[i][j];
		}
	}

	for(size_t i=G1.numVert();i<G1.numVert()+G2.numVert();i++)
	{
		for(size_t j=G1.numVert();j<G1.numVert()+G2.numVert();j++)
		{
			G[i][j]=G2[i-G1.numVert()][j-G1.numVert()];
		}
	}

	for(size_t i=G1.numVert()+G2.numVert();i<G1.numVert()+G2.numVert()+G3.numVert();i++)
	{
		for(size_t j=G1.numVert()+G2.numVert();j<G1.numVert()+G2.numVert()+G3.numVert();j++)
		{
			G[i][j]=G3[i-(G1.numVert()+G2.numVert())][j-(G1.numVert()+G2.numVert())];
		}
	}

	cout << "Isla 1:" << endl;
	cout << G1 << endl;
	cout << "Isla 2:" << endl;
	cout << G2 << endl;
	cout << "Isla 3:" << endl;
	cout << G3 << endl;
	cout << "Total con puentes:" << endl;
	cout << G << endl;

	typedef typename GrafoP<tCoste>::vertice vertices;

	matriz<vertices> X;
	matriz<tCoste> M1=Floyd(G,X);

	for(size_t i=0;i<G1.numVert()+G2.numVert()+G3.numVert();i++)
	{
		for(size_t j=0;j<G1.numVert()+G2.numVert()+G3.numVert();j++)
		{
			cout << M1[i][j] << "  ";
		}
		cout << endl;
	}
}

//Ejercicio 12.
void Ejercicio12()
{
	string a="Deimos.txt";
	string b="Phobos.txt";
	GrafoP<int> G1(a);
	GrafoP<int> G2(b);

	//Ciudades costeras.
	vector<bool> Costeras(G1.numVert()+G2.numVert(),false);
	Costeras[0]=true;
	Costeras[1]=true;
	Costeras[2]=true;
	Costeras[6]=true;
	Costeras[7]=true;
	mejorPuente(Costeras,G1,G2);
}

template <typename tCoste>
void mejorPuente(const vector<bool>& Costeras,const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2)
{
	typedef typename GrafoP<tCoste>::vertice vertice;

	GrafoP<tCoste> G(G1.numVert()+G2.numVert());

	for(size_t i=0;i<G1.numVert();i++)
	{
		for(size_t j=0;j<G1.numVert();j++)
		{
			G[i][j]=G1[i][j];
		}
	}

	for(size_t i=0;i<G1.numVert();i++){
		for(size_t j=G1.numVert();j<G1.numVert()+G2.numVert();j++){
			G[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	for(size_t i=G1.numVert();i<G1.numVert()+G2.numVert();i++){
		for(size_t j=0;j<G1.numVert();j++){
			G[i][j]=GrafoP<tCoste>::INFINITO;
		}
	}

	for(size_t i=G1.numVert();i<G1.numVert()+G2.numVert();i++)
	{
		for(size_t j=G1.numVert();j<G1.numVert()+G2.numVert();j++)
		{
			G[i][j]=G2[i-G1.numVert()][j-G2.numVert()];
		}
	}

	cout << "Deimos:" << endl;
	cout << G1 << endl;
	cout << "Phobos:" << endl;
	cout << G2 << endl;
	cout << "Total:" << endl;
	cout << G << endl;

	//Vemos las ciudades que son costeras.
	size_t count=0;
	for(size_t i=0;i<G1.numVert()+G2.numVert();i++)
	{
		if(Costeras[i]==true)
		{
			count++;
		}
	}
	vector<vertice> Ciu(count);
	count=0;
	for(size_t i=0;i<G1.numVert()+G2.numVert();i++)
	{
		if(Costeras[i]==true)
		{
			Ciu[count]=i;
			count++;
		}
	}

	int minimo=GrafoP<tCoste>::INFINITO;

	GrafoP<tCoste> aux(G1.numVert()+G2.numVert());
	matriz<vertice> X;
	matriz<tCoste> M;
	vertice Ciu1,Ciu2;
	for(size_t i=0;i<Ciu.size()-1;i++)
	{
		for(size_t j=i+1;j<Ciu.size();j++)
		{
			aux=G;
			aux[Ciu[i]][Ciu[j]]=0;
			aux[Ciu[j]][Ciu[i]]=0;
			M=Floyd(aux,X);
			if(countFloyd(M,G1.numVert()+G2.numVert())<minimo)
			{
				minimo=countFloyd(M,G1.numVert()+G2.numVert());
				Ciu1=Ciu[i];
				Ciu2=Ciu[j];
			}
		}
	}

	cout << "El Floyd minimo es: " << minimo << ", con puentes entre las ciudades " << Ciu1 << " y " << Ciu2 << "." << endl;

}

template <typename tCoste>
tCoste countFloyd(const matriz<tCoste>& M,size_t k)
{
	tCoste valor=0;
	for(size_t i=0;i<k;i++)
	{
		for(size_t j=0;j<k;j++)
		{
			valor=suma(valor,M[i][j]);
		}
	}
	return valor;
}

//Ejercicio 13.
void Ejercicio13()
{
	string a="Isla1.txt";
	string b="Isla2.txt";
	string c="Isla3.txt";
	GrafoP<int> G1(a);
	GrafoP<int> G2(b);
	GrafoP<int> G3(c);

	//Introducimos el vector Costeras.
	vector<bool> Costeras(G1.numVert()+G2.numVert()+G3.numVert(),false);
	Costeras[2]=true;
	Costeras[3]=true;
	Costeras[4]=true;
	Costeras[6]=true;
	Costeras[9]=true;
	Costeras[10]=true;
	Costeras[13]=true;
	mejoresPuentes(Costeras,G1,G2,G3);
}

template <typename tCoste>
void mejoresPuentes(const vector<bool>& Costeras,const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2,const GrafoP<tCoste>& G3)
{
	typedef typename GrafoP<tCoste>::vertice vertice;

	GrafoP<tCoste> G(G1.numVert()+G2.numVert()+G3.numVert());

	for(size_t i=0;i<G1.numVert();i++)
	{
		for(size_t j=0;j<G1.numVert();j++)
		{
			G[i][j]=G1[i][j];
		}
	}

	for(size_t i=G1.numVert();i<G1.numVert()+G2.numVert();i++)
	{
		for(size_t j=G1.numVert();j<G1.numVert()+G2.numVert();j++)
		{
			G[i][j]=G2[i-G1.numVert()][j-G1.numVert()];
		}
	}

	for(size_t i=G1.numVert()+G2.numVert();i<G1.numVert()+G2.numVert()+G3.numVert();i++)
	{
		for(size_t j=G1.numVert()+G2.numVert();j<G1.numVert()+G2.numVert()+G3.numVert();j++)
		{
			G[i][j]=G3[i-(G1.numVert()+G2.numVert())][j-(G1.numVert()+G2.numVert())];
		}
	}

	cout << "Isla 1:" << endl;
	cout << G1 << endl;
	cout << "Isla 2:" << endl;
	cout << G2 << endl;
	cout << "Isla 3:" << endl;
	cout << G3 << endl;
	cout << "Total:" << endl;
	cout << G << endl;

	//Costeras.
	size_t count=0;
	for(size_t i=0;i<Costeras.size();i++)
	{
		if(Costeras[i]==true)
		{
			count++;
		}
	}
	vector<vertice> Ciu(count);
	count=0;
	for(size_t i=0;i<Costeras.size();i++)
	{
		if(Costeras[i]==true)
		{
			Ciu[count]=i;
			count++;
		}
	}

	GrafoP<tCoste> aux=G;
	matriz<vertice> X;
	matriz<tCoste> M;

	tCoste minimo=GrafoP<tCoste>::INFINITO;
	vertice C1,C2,C3;

	for(size_t i=0;i<Ciu.size()-2;i++)
	{
		for(size_t j=i+1;j<Ciu.size()-1;j++)
		{
			for(size_t z=j+1;z<Ciu.size();z++)
			{
				aux[Ciu[i]][Ciu[j]]=0;
				aux[Ciu[j]][Ciu[i]]=0;
				aux[Ciu[j]][Ciu[z]]=0;
				aux[Ciu[z]][Ciu[j]]=0;
				M=Floyd(aux,X);
				if(countFloyd(M,G1.numVert()+G2.numVert()+G3.numVert())<minimo)
				{
					minimo=countFloyd(M,G1.numVert()+G2.numVert()+G3.numVert());
					C1=Ciu[i];
					C2=Ciu[j];
					C3=Ciu[z];
				}
				aux=G;
			}
		}
	}
	cout << "El Floyd minimo es: " << minimo << ", con puentes entre las ciudades " << C1 << ", " << C2 << " y " << C3 << "." << endl;
}

