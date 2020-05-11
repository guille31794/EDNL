template <typename T>
void Listado_elementos_rec(const Abb<T>& A, vector<T>& elementos_A)
{

	if (!A.vacio())
	{

		Listado_elementos_rec(A.izqdo(), elementos_A);
		elementos_A.push_back(A.elemento());
		Listado_elementos_rec(A.drcho(), elementos_A);

	}

}

template <typename T>
const vector<T> Listado_elementos(const Abb<T>& A)
{

	vector<T> elementos_A;

	if (A.vacio())
		return elementos_A;
	else
	{

		Listado_elementos_rec(A, elementos_A);
		return elementos_A;

	}

}

template <typename T>
void Equilibrar_rec(Abb<T>& A, typename vector<T>::iterator iterador, typename vector<T>::iterator mediana, vector<T>& elementos_A)
{

	A.insertar(*iterador);

	if (*iterador < *mediana && iterador != elementos_A.begin())
		Equilibrar_rec(A, iterador - 1, mediana, elementos_A);
	else
		if (*iterador > * mediana&& iterador + 1 != elementos_A.end())
			Equilibrar_rec(A, iterador + 1, mediana, elementos_A);

}

template <typename T>
void Equilibrar(Abb<T>& A)
{

	vector<T> elementos_A;
	typename vector<T>::iterator mediana;
	Abb<T> A_ordenado;

	if (!A.vacio())
	{

		elementos_A = Listado_elementos(A);
		mediana = elementos_A.begin() + ((elementos_A.size() - 1) / 2); // Accedemos al elemento que se encuentre en la mitad del vector
																		// elementos_A.size() - 1 equivale a número de elementos del vector - 1
		A_ordenado.insertar(*mediana);

		if (mediana != elementos_A.begin())
			Equilibrar_rec(A_ordenado, mediana - 1, mediana, elementos_A);
		if (mediana + 1 != elementos_A.end())
			Equilibrar_rec(A_ordenado, mediana + 1, mediana, elementos_A);

	}

	A = A_ordenado;


}

template <typename T> // Básicamente es una forma de hacer typedef pero con plantillas, no sé si es la mejor forma
using Conjunto = Abb<T>;

template <typename T>
void Union_rec(Conjunto<T>& A, const Conjunto<T>& B)
{

	if (!B.vacio())
	{

		A.insertar(B.elemento());
		Union_rec(A, B.izqdo());
		Union_rec(A, B.drcho());

	}
}

template <typename T>
Conjunto<T> Union(const Conjunto<T>& A, const Conjunto<T>& B)
{

	Conjunto<T> U = A;
	Union_rec(U, B);
	Equilibrar(U);

	return U;

}
