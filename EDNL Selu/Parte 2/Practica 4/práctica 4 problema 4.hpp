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

template <typename T> // Es un typedef pero para plantillas, no sé si hay una forma mejor de hacerlo
using Conjunto = Abb<T>;

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
void Interseccion_rec(Conjunto<T>& I, const Conjunto<T>& A, const Conjunto<T>& B)
{

	if (!A.vacio())
	{

		Interseccion_rec(I, A.izqdo(), B);
		Interseccion_rec(I, A.drcho(), B);

		if (!B.buscar(A.elemento()).vacio())
			I.insertar(A.elemento());

	}

}

template <typename T>
Conjunto<T> Interseccion(const Conjunto<T>& A, const Conjunto<T>& B)
{

	Conjunto<T> I;

	Interseccion_rec(I, A, B);

	Equilibrar(I);

	return I;

}