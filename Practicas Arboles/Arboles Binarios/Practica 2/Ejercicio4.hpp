#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

template <typename T> class Abin
{   
    public:
        typedef int node;
        static const node NULL_NODE;
        Abin(int d); //h es la profundidad máxima del arbol
        void rootInsert(const T& e);
        void leftSonInsert(node n, const T& e);
        node father(node n) const;
        node root() const;
        node leftSon(node n) const;
        node rightSon(node n) const;
        bool empty() const;
        int height() const;
        int heightRec(node n) const;
        T& element(node n);
        const T& element(node n) const;
        void printA() const;
        int size() const;
        int depthNode(node ) const;
        //friend ostream operator<<(ostream &, const Abin&); 
    private: 
        vector<T> tree;
        int depth(node n) const;
        int depthRec(node n) const;
};

template <typename T> 
const typename Abin<T>::node Abin<T>::NULL_NODE{-1};

template <typename T> 
inline Abin<T>::Abin(int d): tree{vector<T>(pow(2, d+1) - 1)} {}

template <typename T>
inline void Abin<T>::rootInsert(const T& e)
{
    assert(!tree.empty());
    tree[tree.size()/2] = e;
}

template <typename T>
inline bool Abin<T>::empty() const
{
    return tree.empty();
}

template <typename T>
void Abin<T>::leftSonInsert(node n, const T& e)
{
    assert(tree[n - (tree.size() +1) / pow(2, depth(n) + 1)] == T{});
    //tree[n - ((tree.size() + 1) / pow(2, depth(n) + 1))] = e;
    tree[n - (n+1)/2] = e;
}

template <typename T>
typename Abin<T>::node Abin<T>::father(node n) const
{
    assert(n != Abin<T>::NULL_NODE);

    Abin<T>::node d = depthNode(n);

    if(n % (tree.size() + 1)/ pow(2, d - 1) == 
    (tree.size() + 1 / pow(2, d + 1)) - 1)
        return n + (n+1)/2;
    else
        return n - (n+1)/2;
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
        return 0 + max(heightRec(leftSon(n)), heigthRec(rightSon(n))); 
}

template <typename T>
inline int Abin<T>::heightRec(typename Abin<T>::node n) const
{
    if(n == NULL_NODE)
        return 0;
    else
        return 1 + max(heigthRec(leftSon(n), heigthRec(rightSon(n))));
}

template <typename T>
inline int Abin<T>::depth(typename Abin<T>::node n) const
{
    if(n == Abin<T>::NULL_NODE || T{})
        return -1;
    else
        if(n == tree.size()/2 + 1)
            return 1;
        else
            return 1 + depthRec(n);
}

template <typename T>
inline int Abin<T>::depthRec(typename Abin<T>::node n) const
{
    if (n-(n+1)/2 != 0 && n+(n+1)/2 <= tree.size())
    {
        if(tree[n-(n+1)/2] == T{} && tree[n+(n+1)/2] == T{})
            return 0;
        else
            return 1 + max(depthRec(n-(n+1)/2), depthRec(n+(n+1)/2));
    }

    return 0;
}

template <typename T>
inline int Abin<T>::depthNode(typename Abin<T>::node n) const
{
    return depth(n) - 1;
}

template <typename T>
inline typename Abin<T>::node Abin<T>::leftSon(node n) const
{
    assert(n != NULL_NODE);
    return n - ((tree.size() + 1) / pow(2, depth(n) + 1));  
}

template <typename T>
inline typename Abin<T>::node Abin<T>::rightSon(node n) const
{
    assert(n != NULL_NODE);
    return n + ((tree.size() + 1) / pow(2, depth(n) + 2));
}

template <typename T>
inline const T& Abin<T>::element(Abin<T>::node n) const
{
    assert(n != NULL_NODE);
    return tree[n];
}

template <typename T>
inline T& Abin<T>::element(Abin<T>::node n)
{
    assert(n != NULL_NODE);
    return tree[n];
}

template <typename T>
void Abin<T>::printA() const
{
    for(auto it : tree)
    {
        cout << it << ' ';
    }
    cout << endl;
}

template <typename T>
int Abin<T>::size() const
{
    return tree.size();
}

/*template <typename T>
ostream operator <<(ostream& os, const Abin<T>& A)
{
    for(auto it : A.tree)
    {
        os << A.tree[it] << ' ';
    }
    
    return os;
}*/