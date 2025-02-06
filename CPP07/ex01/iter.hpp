/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:01:13 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/06 16:49:15 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template<typename T, typename F>
    void iter (T *array, int array_length, F iter_func)
    {
        for (int i = 0; i < array_length ; i++)
            iter_func(array[i]);
    }
    
template<typename T>
    void printData(T const &data)
    {
        std::cout << data << std::endl;
    }

