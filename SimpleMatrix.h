#ifndef __SIMPLE_MATRIX_H
#define __SIMPLE_MATRIX_H

#include <vector>

template <typename Type = std::double_t> class SimpleMatrix {
    private:
        std::vector <std::vector <Type>> mat;
    public:
        SimpleMatrix();
        SimpleMatrix(const int& rows, const int& cols, const Type& val);
        SimpleMatrix(const SimpleMatrix<Type>& _rhs);

        SimpleMatrix<Type>& operator= (const SimpleMatrix<Type>& _rhs);
        virtual ~SimpleMatrix();
        std::vector <std::vector <Type>> get_mat() const;
        Type& value(const int& row, const int& col);
};


#endif