/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:05:36 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/08 18:44:21 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array():_size(0)
{
    std::cout << "Default Array constructor called." << std::endl;
    this->_array = new T[_size];
}

template <typename T>
Array<T>::Array(unsigned int size):_size(size)
{
    std::cout << "Parameter Array constructor called. Array size is: " << size << std::endl;
    this->_size = size;
    this->_array = new T[size];
}

template <typename T>
Array<T>::Array(Array const &copy):_size(copy._size)
{
    std::cout << "Array copy constructor called." << std::endl;
    this->_array = NULL;
    *this = copy;
}

template<typename T>
Array<T>::~Array()
{
    std::cout << "Array destructor called. Its size is: " << this->_size << std::endl;
    if(this->_array)
        delete [] this->_array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &copy)
{
    std::cout << "Assignment operator called." << std::endl;
    if(this->_array)
        delete [] this->_array;
    if(copy.size() > 0)
    {
        this->_size = copy.size();
        this->_array = new T[other.size()];
        for (unsigned int i = 0; i < copy.size(); i++)
            this->_array[i] = copy._array[i];
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if(index >= this->_size || this->_array == NULL)
    {
        std::cout << "Invalid index number:";
        throw Array<T>::OutofLimitException();
    }
    return (this->_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (thiz->_size);
}