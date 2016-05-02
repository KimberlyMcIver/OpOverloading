#pragma once

#include <exception>
#include <vector>
#include <iostream>
#include <vector>

using namespace std;


template<typename T>
using twoD = std::vector<std::vector<T>>;
//more info on the above: http://stackoverflow.com/a/16861385/3255842

template<class T>
class Matrix {
private:
    int rows;
    int cols;
    twoD<T> matrix;
protected:
    void validSizeCheck(int rows, int cols);

public:
    Matrix(int rows, int cols);

    Matrix(int rows, int cols, twoD<T> newMatrix);

    twoD<T> getMatrix();

    int getRows();

    int getCols();

    void operator=(const Matrix<T> &);

    Matrix<T> &operator+=(const Matrix<T> &);

    Matrix<T> &operator-=(const Matrix<T> &);

    Matrix<T> &operator*=(const Matrix<T> &);

    Matrix<T> &operator*=(const T &);

    /*
    friend void operator<<(ostream &os, const Matrix<T> &m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                os << m.matrix[i][j] << " ";
            }
            os << endl;
        }
        os << endl;
        os << endl;
    }
    */

    void printMatrix();

    //TODO Implement the functions below

    //  answer = obj1.operator+(obj2) ->     object1 function {   oprator+(obj2) }
    //  obj1.expand()
    //  obj1.+(obj2)
    // obj1.operator+(obj2)

    Matrix<T> operator+(const Matrix<T> &other)   //;//Matrix Addition
    {
        if( (rows != other.rows) || (cols != other.cols))
        {
            throw exception();
        }

        Matrix *obj = new Matrix(rows, cols);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                obj->matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }

        return *obj;
    }

    Matrix<T> operator-(const Matrix<T> &other) //;//Matrix Subtraction
    {
        if( (rows != other.rows) || (cols != other.cols))
        {
            throw exception();
        }


        Matrix *obj = new Matrix(rows, cols);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                obj->matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }

        return *obj;
    }


    Matrix<T> operator*(const Matrix<T> &other) //;//Matrix Multiplication
    {
        if( (rows != other.cols) || (cols != other.rows))
        {
            throw exception();
        }


        Matrix *obj = new Matrix(rows, other.cols);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<other.cols;j++)
            {
                int sum = 0;
                for(int k=0;k<cols;k++)
                {
                    sum = sum + matrix[i][k]*other.matrix[k][j];
                }
                obj->matrix[i][j] = sum;
            }
        }

        return *obj;
    }

    Matrix<T> operator*(const T &scalar) //;//Matrix Multiplication with a Scalar
    {
        Matrix *obj = new Matrix(rows, cols);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                obj->matrix[i][j] = matrix[i][j] * scalar;
            }
        }

        return *obj;
    }


};



template<class T>
void Matrix<T>::validSizeCheck(int rows, int cols) {
    //DO NOT MODIFY
    //This is a helper function for checking invalid size.
    if (rows < 1 || cols < 1) {
        throw exception();
    }
}


template<class T>
twoD<T> Matrix<T>::getMatrix() {
    //DO NOT MODIFY
    return matrix;
}

template<class T>
int Matrix<T>::getRows() {
    //DO NOT MODIFY
    return rows;
}

template<class T>
int Matrix<T>::getCols() {
    //DO NOT MODIFY
    return cols;
}


template<class T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    //DO NOT MODIFY
    validSizeCheck(rows, cols);
    matrix.resize(rows);
    for (int i = 0; i < rows; i++) {
        matrix[i].resize(cols);
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
            //cout << "Writing: i: " << i << " j: " << j << " val: " << matrix[i][j] << endl;
        }
    }

}

template<class T>
Matrix<T>::Matrix(int rows, int cols, twoD<T> newMatrix) : rows(rows), cols(cols) {
    //DO NOT MODIFY
    validSizeCheck(rows, cols);
    matrix.resize(rows);
    for (int i = 0; i < rows; i++) {
        matrix[i].resize(cols);
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = newMatrix[i][j];
        }
    }


}

template<class T>
void Matrix<T>::operator=(const Matrix<T> &rhs) {
    //DO NOT MODIFY

    if (rows != rhs.rows || cols != rhs.cols) {
        //throw exception
    }
    Matrix<T> newMatrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newMatrix.matrix[i][j] = rhs.matrix[i][j];
        }
    }
}

template<class T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs) {
    //DO NOT MODIFY
    *this = *this + rhs;
    return *this;
}

template<class T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs) {
    //DO NOT MODIFY
    *this = *this - rhs;
    return *this;
}

template<class T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &rhs) {
    //DO NOT MODIFY
    *this = *this * rhs;
    return *this;
}

template<class T>
Matrix<T> &Matrix<T>::operator*=(const T &rhs) {
    //DO NOT MODIFY
    *this = *this * rhs;
    return *this;
}

template<class T>
void Matrix<T>::printMatrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}


//TODO Implement the functions here.
