/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:37:11 by crocha-s          #+#    #+#             */
/*   Updated: 2025/03/03 15:20:05 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
    std::vector<btcData> print;
    try
    {
        if(argc != 2)
            throw std::runtime_error("Need a file as argument.");
        std::vector<btcData> dB = readDB();
        readFromFile(dB, argv[1]);
            
    
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << RED << "Error: " << e.what() << WHITE << std::endl;
        return (EXIT_FAILURE);
        
    }
    
}