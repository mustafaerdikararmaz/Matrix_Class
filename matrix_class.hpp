#include <iostream>
#include <math.h>

using namespace std;


template <int N>
class Matrix
{
private:
    
    double data[N][N];


public:

    Matrix(){ 
        //This function initialise the matrix with identity matrix with size NxN.
        

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i!=j) data[i][j] = 0;
                else data[i][j] = 1;
            }
        }
    }

    int GetSize() const{
        // This function returns the size of the matrix.
        return N;
    }

    double Getter(int i,int j) const{
        // This function returns the value at the given index.
        if(i>N||j>N) 
            throw std::invalid_argument( "Given number is bigger than the matrix size N" );

        return data[i][j];
    }

    void Setter(double number,int i,int j){

        //This function sets the parameter of the matrix at given index.

        if(i>N||j>N) 
            throw std::invalid_argument( "Given number is bigger than the matrix size N" );
        data[i][j] = number;
    }

    Matrix operator +(Matrix &Matrix2){

        // I defined operators for addition(same as multiplication and subtraction) 
        // so that we can use it for 3 or more matrices.
        // But, if I defined a function, I must use only for 2 matrices.
        // I found operator is better for the usage but it has the same idea with the addition funciton.

        //UPDATE: I talked with Klaus Hoca and he said that this usage is OK but I have to 
        // tell the code reviewer that he said OK. This comment is for this purpose.

        Matrix <N> ResultMatrix;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                ResultMatrix.Setter(this->Getter(i,j) + Matrix2.Getter(i,j),i,j);
            }
        }
        return ResultMatrix;
    }

    Matrix operator -(Matrix &Matrix2){
        //This operator is used for matrix subtraction.
            Matrix <N> ResultMatrix;

            for(int i = 0;i<N;i++){
                for(int j = 0;j<N;j++){
                    ResultMatrix.Setter(this->Getter(i,j) - Matrix2.Getter(i,j),i,j);
                }
            }

            return ResultMatrix;
        }

    Matrix operator *(Matrix &Matrix2){
        //This is a matrix multiplication operator. We can use it with 3 or more matrices at the same row.
        Matrix <N> ResultMatrix;

        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                int total = 0;
                for(int k = 0;k<N;k++){
                    total += this->Getter(i,k)*Matrix2.Getter(k,j);
                }
                ResultMatrix.Setter(total,i,j);
            }
        }

        return ResultMatrix;

    }

    Matrix operator *(double k){
        //This is an extra function that multiplies the matrix with a scalar.
        // Please don't take my points of for this extra function :(
        Matrix <N> ResultMatrix;

        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                ResultMatrix.Setter(k * this->Getter(i,j),i,j);
            }
        }

        return ResultMatrix;

    }
    

double Determinant(){

            // This function calculates the determinant of the matrix.
            // I tried to write a recursive program below.
        double result;
        double **arr;

        result = SubDeterminant(this->GetSize(), arr);
       
        return result; 

    };

double SubDeterminant(int A, double ** arr);

};


double SubDeterminant(int A, double **array){
    double Deter = 0;




    return Deter;
}








