/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:08:56 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/26 19:45:00 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void proceed(std::string msg)
{
    std::cout << msg << std::endl;
    std::cout << "Press ENTER to proceed." << std::endl;
    std::cin.ignore();
}

int main(void)
{
    proceed("Creating Data structures:");
    
    Data person3 = {"George", 50, NULL};
    Data person2 = {"Charles", 20, &person3};
    Data person1 = {"John", 10, &person2};
    
    Data *people [3] = {&person1, &person2, &person3};

    for(int i = 0; i < 3; i++)
    {
        std::cout << "##### Person " << i + 1 << " #####" << std::endl;
        std::cout << "Address: " << people[i] << std::endl;
        std::cout << "Name: " << people[i]->name << std::endl;
        std::cout << "Rank: " << people[i]->rank << std::endl;
        std::cout << "Next Address: " << people[i]->next << std::endl << std::endl;
    }

    proceed("Serializing and Deserializing tests:");
    
    uintptr_t serializedPeople [3] = {Serializer::serialize(&person1), Serializer::serialize(&person2), Serializer::serialize(&person3)};
    for(int i = 0; i < 3; i++)
    {
        std::cout << "##### Person " << i + 1 << " #####" << std::endl;
        std::cout << "Original Address: " << &serializedPeople[i] << std::endl;
        std::cout << "Original Name: " << people[i]->name << std::endl;
        std::cout << "Deserialized Name: " << Serializer::deserialize(serializedPeople[i])->name << std::endl;
        std::cout << "***********" << std::endl;
        std::cout << "Original Rank: " << people[i]->rank << std::endl;
        std::cout << "Deserialized Rank: " << Serializer::deserialize(serializedPeople[i])->rank << std::endl;
        std::cout << "***********" << std::endl;
        std::cout << "Original Next: " << people[i]->next << std::endl;
        std::cout << "Deserialized Next: " << Serializer::deserialize(serializedPeople[i])->next << std::endl;
        
    }
    
    

    
}
