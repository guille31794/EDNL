#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

template <typename T> class Abin
{   
    public:
        typedef int node;
        static const node NULL_NODE;
        Abin(int h);
        void rootInsert(T& e);
        void leftSonInsert(node n, T& e);
        node father(node n) const;
        node root() const;
        node leftSon(node n) const;
        node rightSon(node n) const;
        bool empty() const;
        int height() const;
        int heightRec(node n) const;
    private:
        vector<T> tree;
        int depth(node n) const;
        int depthRec(node n) const;
};

template <typename T> 
const typename Abin<T>::node Abin<T>::NULL_NODE{-1};

template <typename T> 
inline Abin<T>::Abin(int h): tree{new vector<T>(h)} {}

template <typename T>
inline void Abin<T>::rootInsert(T& e)
{
    assert(tree.empty());
    tree[tree.size()/2].push(e);
}

template <typename T>
inline bool Abin<T>::empty() const
{
    return tree.empty();
}

template <typename T>
void Abin<T>::leftSonInsert(node n,T& e)
{

}

template <typename T>
typename Abin<T>::node Abin<T>::father(node n) const
{
    assert(n == Abin<T>::NULL_NODE);

    if ((n - tree.size()+1) / pow(2, depth(n)+1) 
    {
        
    }
    
}

template <typename T>
inline typename Abin<T>::node Abin<T>::root() const
{
    if(!tree.empty())
    {
        if(tree.size()/2 == 0)
            return tree.size()/2;
        else
            return (tree.size()/2) + 1;
    }
    else
        return NULL_NODE;
}

template <typename T>
inline int Abin<T>::height() const 
{
    //We star in root node
    Abin<T>::node n = root();

    //If tree is empty: -1 else, at least 0
    if(n == NULL_NODE)
        return -1;
    else
        return 0 + max(depthRec(leftSon(n)), depthRec(rightSon(n))); 
}

template <typename T>
inline int Abin<T>::heightRec(typename Abin<T>::node n) const
{
    if(n == NULL_NODE)
        return 0;
    else
        return 1 + max(depthRec(leftSon(n), depthRec(rightSon(n))));
}

template <typename T>
inline int depth(typename Abin<T>::node n)
{
    if(n == Abin<T>::NULL_NODE)
        return -1;
    else
        return 0 + depthRec(father(n));
}

template <typename T>
inline int depthRec(typename Abin<T>::node n)
{
    if (n == Abin<T>::NULL_NODE)
        return 1;
    else
        return 1 + depthRec(father(n));
}

template <typename T>
inline typename Abin<T>::node Abin<T>::leftSon(node n) const
{
    assert(n != NULL_NODE);
    //return 
}