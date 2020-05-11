template <typename T>
void Apo_min_max<T>::Reordenar_nivel_impar(typename Apo_min_max<T>::nodo n)
{

	T auxiliar;

	if (n > 2 && nodos[n] > nodos[padre(padre(n))])
	{

		auxiliar = nodos[padre(padre(n))];
		nodos[padre(padre(n))] = nodos[n];
		nodos[n] = auxiliar;

		Reordenar_nivel_impar(padre(padre(n)));

	}

}

template <typename T>
void Apo_min_max<T>::Reordenar_nivel_par(typename Apo_min_max<T>::nodo n)
{

	T auxiliar;

	if (n != 0)
		if (nodos[n] > nodos[padre(n)])
		{

			auxiliar = nodos[n];
			nodos[n] = nodos[padre(n)];
			nodos[padre(n)] = auxiliar;

			Reordenar_nivel_impar(padre(n));

		}
		else
			if (nodos[padre(padre(n))] > nodos[n])
			{

				auxiliar = nodos[n];
				nodos[n] = nodos[padre(padre(n))];
				nodos[padre(padre(n))] = auxiliar;

				Reordenar_nivel_par(padre(padre(n)));

			}

}

template <typename T>
void Apo_min_max<T>::insertar(const T& e)
{

	assert(ultimo < maxNodos - 1);

	int nivel;
	T auxiliar;

	ultimo++;

	nodos[ultimo] = e;

	if (ultimo != 0)
	{

		nivel = (int)log2(ultimo + 1);
		if (nivel % 2 == 0)
			Reordenar_nivel_par(ultimo);
		else
		{
			if (nodos[padre(ultimo)] > nodos[ultimo])
			{

				auxiliar = nodos[padre(n)];
				nodos[padre(n)] = nodos[n];
				nodos[n] = auxiliar;

				Reordenar_nivel_par(padre(n));

			}
			else
				Reordenar_nivel_impar(ultimo);
		}

	}

}