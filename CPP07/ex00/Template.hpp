/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:34:44 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/06 14:54:25 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>

struct Operations{
    static void swap(T *a, T *b)
    {
        T temp = *a;
        *a = *b;
        *b = temp;
    }
    
    static T min(T a, T b)
    {
        if(a < b)
            return (a);
        return (b);
    }
    static T max(T a, T b)
    {
        if(a > b)
            return (a);
        return (b);
    }
};