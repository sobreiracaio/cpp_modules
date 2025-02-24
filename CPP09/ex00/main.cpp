/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:37:11 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/24 18:24:40 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
    try
    {
        if(argc != 2)
            throw std::runtime_error("Need a file as argument.");
        
        BitcoinExchange btc(argv[1]);
        btc.readFromFile();
            
    
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << RED << "Error: " << e.what() << WHITE << std::endl;
        return (EXIT_FAILURE);
        
    }
}