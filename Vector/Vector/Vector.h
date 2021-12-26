//
// Created by Zong-Z on 25.12.2021.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <cstdlib>
#include <exception>

template<typename T>
class Vector {
public:
    class Iterator {
    public:
        Iterator(const Vector<T> *pVector, const std::size_t nIndex) : m_pVector(pVector), m_nIndex(nIndex) {};

        Iterator &operator++() {
            ++m_nIndex;
            return *this;
        }

        Iterator &operator--() {
            --m_nIndex;
            return *this;
        }

        Iterator &operator+(const std::size_t nUpdateIndex) {
            m_nIndex += nUpdateIndex;
            return *this;
        }

        Iterator &operator-(const std::size_t nUpdateIndex) {
            m_nIndex -= nUpdateIndex;
            return *this;
        }

        const T &operator*() {
            return m_pVector->operator[](m_nIndex);
        }

        bool operator==(const Iterator &other) { return m_nIndex == other.m_nIndex; }

        bool operator!=(const Iterator &other) { return m_nIndex != other.m_nIndex; }

    private:
        const Vector<T> *m_pVector;
        std::size_t m_nIndex = 0;
    };

public:
    Vector() = default;

    explicit Vector(const std::size_t nSize) : m_nSize(nSize), m_nCapacity(nSize), m_pData(new T[nSize]) {
        for (std::size_t i = 0; i < nSize; ++i)
            m_pData[i] = T();
    }

    explicit Vector(const std::size_t nSize, const T &initialValue) : m_nSize(nSize), m_nCapacity(nSize),
                                                                      m_pData(new T[nSize]) {
        for (std::size_t i = 0; i < nSize; ++i)
            m_pData[i] = initialValue;
    }

    ~Vector() {
        m_nSize = 0;
        m_nCapacity = 0;
        delete[] m_pData;
    }

    std::size_t size() const noexcept { return m_nSize; }

    std::size_t capacity() const noexcept { return m_nCapacity; }

    void pushBack(const T &value) {
        if (m_nSize == m_nCapacity) {
            if (m_nCapacity == 0)
                m_nCapacity = 1;

            m_nCapacity *= 2;
            T *pNewMemory = new T[m_nCapacity];
            for (std::size_t i = 0; i < m_nSize; ++i)
                pNewMemory[i] = m_pData[i];

            delete[] m_pData;
            m_pData = pNewMemory;
        }

        m_pData[m_nSize] = value;
        ++m_nSize;
    };

    void popBack() {
        --m_nSize;
        T *pNewMemory = new T[m_nSize];
        for (std::size_t i = 0; i < m_nSize; ++i)
            pNewMemory[i] = m_pData[i];

        delete[] m_pData;
        m_pData = pNewMemory;
    }

    const T &operator[](const std::size_t nIndex) const {
        if (nIndex >= m_nSize)
            throw std::exception("Index out of range");

        return m_pData[nIndex];
    }

    Vector<T>::Iterator begin() const noexcept {
        return Vector<T>::Iterator(this, 0);
    }

    Vector<T>::Iterator end() const noexcept {
        return Vector<T>::Iterator(this, m_nSize);
    }

private:
    T *m_pData = nullptr;
    std::size_t m_nSize = 0;
    std::size_t m_nCapacity = 0;
};


#endif //VECTOR_VECTOR_H
