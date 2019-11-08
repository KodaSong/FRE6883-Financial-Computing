#ifndef BinLattice02_h
#define BinLattice02_h

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

template <typename Type>
class BinLattice
{
private:
    int N;
    vector<vector<Type> > Lattice;
public:
    void SetN(int N_)
    {
        N = N_;
        Lattice.resize(N+1);
        for(int n=0; n<=N; n++){
            Lattice[n].resize(N+1); // Make a matrix to store value
            for(int k=0; k<=N; k++)
                Lattice[n][k] = -1;  // Initiate every element = -1
        }
    }

    void SetNode(int n, int i, Type x) {Lattice[n][i] = x;}
    Type GetNode(int n, int i) {return Lattice[n][i];}
    void Display()
    {
        cout << setiosflags(ios::fixed) << setprecision(3);
        for(int i=0; i<=N; i++){
            for(int j=0; j<=N; j++){
                cout << setw(10) << GetNode(i,j);   // output every node of the tree
            }
            cout << endl;
        }
        cout << endl;
    }
};

#endif // BinLattice02_h
