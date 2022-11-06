#include "matrix_class.hpp"
#include <iostream>


int main(){

    
    int i=3,j=3;
    
    Matrix<100> MyMatrix;
    Matrix<100> Matrix1;
    Matrix<100> Matrix2;

    MyMatrix.Setter(2.5,1,2); 
    MyMatrix = Matrix1 * 5.4;

    cout<<"Determinant of the matrix = "<< MyMatrix.Determinant() << endl;
    
    
    return 0;

};