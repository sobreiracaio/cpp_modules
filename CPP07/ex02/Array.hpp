/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:10:48 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/09 16:08:46 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
class Array{
    
    private:
    T* _array;
    unsigned int _length;

    public:
    Array();
    Array(unsigned int size);
    Array(Array const &copy);
    Array &operator=(Array const &copy);
    ~Array();
    unsigned int size(void) const;
    T& operator[](unsigned int index); 

    class OutofLimitException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
};

template<typename T>
char const *Array<T>::OutofLimitException::what() const throw()
{
    return (" Out of limits.");
}

template<typename T>
std::ostream &operator<<(std::ostream & out, Array<T> &array)
{
    out << "{";
    for (unsigned int i = 0; i < array.size(); i++)
    {
        if(i != array.size() - 1)
            out << array[i] << ", ";
        else
            out << array[i];
    }
    out << "}";
    return (out);
}

#include "Array.tpp"
