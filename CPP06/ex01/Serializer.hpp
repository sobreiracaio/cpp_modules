/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:27:34 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/26 16:53:03 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdint>

typedef struct Data
{
    std::string name;
    int rank;
    Data *next;
} Data;

class Serializer{
    
    private:
        Serializer();
        Serializer(Serializer const &copy);
        Serializer &operator=(Serializer const &copy);
        ~Serializer();
    
    public:
        static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};
