/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:37:07 by spoole            #+#    #+#             */
/*   Updated: 2020/01/23 13:37:08 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"

template <typename F>
Array<F>::Array(void) : _array(NULL), _size(0) {}

template <typename F>
Array<F>::Array(unsigned int n) : _array(new F[n]), _size(n)
{
    for (int i = 0; i < n; i++)
        _array[i] = 0;
}

template <typename F>
Array<F>::Array(const Array<F> & arr)
{
    _array = new F[arr._size];
    _size = arr._size;
    std::copy(arr._array[0], arr._array[arr._size - 1], _array);
}

template <typename F>
Array<F>::~Array(void)
{
    if (_array != NULL)
        delete [] _array;
}

template <typename F>
Array<F> & Array<F>::operator = (const Array<F> & arr)
{
    if (arr != *this)
    {
        if (_size != arr._size)
        {
            if (_array != NULL)
            {
                delete [] _array;
                _size = 0;
                _array = NULL;
            }
            _array = new F[arr._size];
        }
        _size = arr._size;
        std::copy(arr._array, arr._array + arr._size, _array);
    }
    return (*this);
}

template <typename F>
F & Array<F>::operator[] (int idx)
{
    if (idx >= _size)
        throw BadAccess();
    else
        return *_array[idx];
}

template <typename F>
const F & Array<F>::operator[] (int idx) const 
{
    if (idx >= _size)
        throw BadAccess();
    else
        return *_array[idx];
}

template <typename F>
const char *Array<F>::BadAccess::what() const throw()
{
    return ("Bad Access: index out of range");
}
