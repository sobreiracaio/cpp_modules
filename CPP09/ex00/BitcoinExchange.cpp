/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:16:43 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/24 23:42:46 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string file):_fileName(file){}

//BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy){}

BitcoinExchange::~BitcoinExchange(){}

//BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &source){}



static bool checkDataFormat(Data &data, std::string tempValue)
{
    
}


std::vector<std::string> BitcoinExchange::readFromFile(Data &structData)
{
    std::ifstream file(this->_fileName.c_str());
    std::vector<Data> data;
    std::string line;

    if(!file.is_open())
        throw std::runtime_error("Opening file failed.");
    
    std::getline(file, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Table labels are not formatted.");
    
    while (std::getline(file, line))
    {
        std::stringstream stream(line);
        std::string tempValue;
        
        std::getline(stream, structData.date , ',');
		stream >> tempValue;

        structData.price = std::atof(tempValue.c_str());
        if(!checkDataFormat(structData, tempValue))
            throw std::runtime_error("Corrupted data.");
        data.push_back(structData);
        
    }
    
    file.close();
}

//std::vector<std::string> BitcoinExchange::parseAndPopulate(){}