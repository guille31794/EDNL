#include "alg_grafoPMC.h"



template <typename tCoste>
vector<tCoste> DijkstraInv(const GrafoP<tCoste>& G,
                        typename GrafoP<tCoste>::vertice destino,
                        vector<typename GrafoP<tCoste>::vertice>& P)
{


    typedef typename GrafoP<tCoste>::vertice vertice;
    vertice v,w;
    size_t n = G.numVert();
    vector<bool> S(n,false);
    vector<tCoste> D;
    tCoste costemin;
    tCoste vwD;


    for(size_t i=0;i < n;i++)       //con esto en D tenemos
    {
        D[i]=G[i][destino];
    }

    D[destino] = 0;
    P = vector<vertice>(n, destino);

    S[destino] = true;

    for(size_t i = 1; i <= n-2; i++)
    {
        costemin = GrafoP<tCoste>::INFINITO;
        for(v = 0; v < n; v++)
            if(!S[v] && D[v] <= costemin )
            {
                costemin = D[v];
                w = v;
            }
        S[w] = true;
        for(v = 0; v < n; v++)
            if(!S[v])
            {
                vwD = suma(G[v][w],D[w]);
                if(vwD<D[v])
                {
                    D[v] = vwD;
                    P[v] = w;
                }
            }
    }
    return D;
}