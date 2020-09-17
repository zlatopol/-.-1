#include<cstddef>
#include<string>
#include<iostream>
#include<locale>
#include<cassert>
#include<algorithm>
// Строго безопасная в смысле исключений версия
//
template<typename T, size_t size>
class fixed_vector
{
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    fixed_vector() : v_( new T[size] ) {}
    ~fixed_vector() { delete[] v_; }
    template<typename O, size_t osize>
    fixed_vector(const fixed_vector<O,osize>& other)
    : v_( new T[size] )
    {
        try {
        copy( other.begin(),
        other.begin() + std::min(size, osize),
        begin());
            } catch(...) { delete[] v_; throw; }
    }
    fixed_vector(const fixed_vector<T,size>& other)
    : v_( new T[size] )
    {
        try {
            copy( other.begin(), other.end(), begin() );
            } catch(...) { delete[] v_; throw; }
    }
    void Swap( fixed_vector<T,size>& other ) noexcept
    {
        std::swap(v_, other.v_);
    }
    template<typename O, size_t osize>
    fixed_vector<T,size>&
    operator=(const fixed_vector<O,osize>& other)
    {
        // Вся работа делается здесь:
        fixed_vector<T,size> temp(other);
        // Здесь исключения не генерируются:
        Swap(temp); return *this;
    }
    fixed_vector<T,size>&
    operator=(const fixed_vector<T,size>& other)
    {
        // Вся работа делается здесь:
        fixed_vector<T,size> temp(other);
        // Здесь исключения не генерируются:
        Swap(temp); return *this;
    }
    iterator begin() { return v_; }
    iterator end() { return v_ + size; }
    const_iterator begin() const { return v_; }
    const_iterator end() const { return v_ + size; }
private:
    T * v_;
};
 int main()
 {
     return 0;
 }