#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("date.in"); 
ofstream fout("date.out");

int main()
{
    int n; 
    fin >> n; 
    int mat1[100][100]; 
    for (int i = 0; i < n; i++) {
        fin >> mat1[i][i];
    }
    for (int i = 0; i < n; i++) {
        fout << mat1; 
    }
    
}