/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:16:43 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/24 19:07:11 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string file):_fileName(file){}

//BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy){}

BitcoinExchange::~BitcoinExchange(){}

//BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &source){}

void BitcoinExchange::readFromFile()
{
    std::ifstream file(this->_fileName.c_str());
    std::string line;

    //if(!file.is_open())
    
    while (std::getline(file, line))
    {
        this->_rawData.append(line + "\n") ;
    }
    std::cout << this->_rawData << std::endl;
    file.close();
}

//std::vector<std::string> BitcoinExchange::parseAndPopulate(){}