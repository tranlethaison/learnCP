#include <bits/stdc++.h>
#include <vector>
using namespace std;

stringstream line0("1 1 1 4 5 6");
stringstream line1("1, 5, 2, 2, 3, 10");
// 3 13 13 6 7 6

int main(){
    int size = 6;
    int n_opes = 2;
    vector<int> A(size);
    vector<int> B(size);
    
    for(int i=0; i<size; i++){
        line0 >> A[i];
    }

    char line1_sep = ',';
    for(int i=0; i<n_opes; i++){
        int left, right, X;

        line1 >> left;
        if(line1.peek() == line1_sep) { line1.ignore(); }
        line1 >> right;
        if(line1.peek() == line1_sep) { line1.ignore(); }
        line1 >> X;
        if(line1.peek() == line1_sep) { line1.ignore(); }

        B[left - 1] += X;
        B[right] -= X; 
    }

    int auxB;
    for(int a=0; a<size; a++){
        auxB += B[a];
        A[a] += auxB;
    }

    return 0;
}