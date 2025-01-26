/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:32:15 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/26 16:55:11 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){};

Serializer::Serializer(Serializer const &copy)
{
    *this = copy;
}

Serializer &Serializer::operator=(Serializer const &copy)
{
    if(this == &copy)
        return (*this);
    return (*this);
}

Serializer::~Serializer(){};

uintptr_t Serializer::serialize(Data *dataPtr)
{
    return(reinterpret_cast<uintptr_t>(dataPtr));
}

Data *Serializer::deserialize(uintptr_t intPtr)
{
    return(reinterpret_cast<Data*>(intPtr));
}