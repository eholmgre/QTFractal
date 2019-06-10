#ifndef SIMPLEMATRIX_H
#define SIMPLEMATRIX_H

#include <stdexcept>
#include <iostream>
#include <string>

template<typename T>
class SimpleMatrix
{
    T* matrix;

    int n, m;

public:
    SimpleMatrix(int n, int m)
    {
        this->n = n;
        this->m = m;

        matrix = new T[n * m];
    }

    T get(int i, const int j) const
    {
        if (not (i < n) and (j < m)) {
            throw std::runtime_error("invalid indicies " + std::to_string(i)
                                     + ", " + std::to_string(j)
                                     + " for matrix with size "
                                     + std::to_string(n) + ", "
                                     + std::to_string(m));
        }

        return matrix[(i * n) + j];
    }

    void put(T t, const int i, const int j)
    {
        if (i < 0 or j < 0) {
            throw std::runtime_error("invalid indicies " + std::to_string(i)
                                     + ", " + std::to_string(j));
        }

        if (not ((i < n) and (j < m))) {
            throw std::runtime_error("invalid indicies " + std::to_string(i)
                                     + ", " + std::to_string(j)
                                     + " for matrix with size "
                                     + std::to_string(n) + ", "
                                     + std::to_string(m));
        }

        matrix[i * n + j] = t;
    }

    int getn() const {return n;}
    int getm() const {return m;}

    ~SimpleMatrix()
    {
        delete matrix;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream &ostrm, const SimpleMatrix<T> &m) {
    for (int i = 0; i < m.getn(); ++i) {
        for (int j = 0; j < m.getn(); ++j) {
            //ostrm << std::to_string(m.get(i, j)) << "\t";
            ostrm << m.get(i, j) << "\t";
        }

        ostrm << std::string("\n");

    }

    return ostrm;
}

#endif // SIMPLEMATRIX_H
