/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:53:52 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/28 20:08:17 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <climits>
#include <stdexcept>

#define WHITE	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define YELLOW	"\033[33m"
#define CLEAR   "\033c"


typedef struct data
        {
            std::tm date;
            float exchange_rate;
            float amount;
        }btcData;

bool checkDate(btcData &btc, std::string const &date)
{
    if(date.size() != 10
        ||  date.find_first_not_of("1234567890-") != std::string::npos		
		|| (date.find_first_of("-") != 4 || date.find_last_of("-") != 7))	
		    return (false);
            
    std::tm tm = {};
        if (strptime(date.c_str(), "%Y-%m-%d", &tm))
        {
            tm.tm_year += 1900;
            tm.tm_mon += 1;
            btc.date = tm;
            return (true);
        }
        return (false);
}

bool checkValue(btcData &btc, std::string const &tmp, int option = 0)
{
    if ((tmp.find_first_not_of("1234567890+-.") != std::string::npos)		
		|| (tmp.find_first_of(".") != tmp.find_last_of("."))			
		|| (tmp.find_first_of(".") == tmp.length() - 1)				
		|| (tmp.find_first_of(".") == 0)								
		|| (tmp.find_first_of("+-") != tmp.find_last_of("+-")))
        {
            std::cerr << "Error: Number is not properly formatted." << std::endl;
		    return (false);
        }	
            
    float nb = std::atof(tmp.c_str());
    if (nb < 0 || nb >= (float)INT_MAX)
    {
        std::cerr << "Error: Number beyond limits." << std::endl;
        return (false);
    }
        
    if(option == 0)        
        btc.exchange_rate = nb;   
    else
    {
        if (nb < 0)
	    {
		    std::cerr << "Error: Not a positive number." << std::endl;
		    return (false);
	    }
	        else if (nb > 1000)
	    {
		    std::cerr << "Number too big." << std::endl;
		    return (false);
	    }
        btc.amount = nb;
    }
    return (true);
}

std::vector<btcData> readDB(void)
{
    std::ifstream file ("data.csv");
    std::vector<btcData> database;
	std::string line;
    std::stringstream ss(line);

	if (!file.is_open())
		throw std::runtime_error("Opening file failed.");
        
    std::getline(file, line);
    if (line != "date,exchange_rate")
        throw std::runtime_error("Table labels are in incorrect format.");
    
    while (std::getline(file, line))
	{
		btcData tmp;
		std::string tmpDate;
		std::string tmpExchangeValue;

        std::getline(ss, tmpDate, ',');
        ss >> tmpExchangeValue;
        
        if(!checkDate(tmp, tmpDate) || !checkValue(tmp, tmpExchangeValue))
            throw std::runtime_error("Database corrupted");
        database.push_back(tmp);
        
    }
    file.close();
    return (database);
}


float exchangeResult(std::vector<btcData> const &database, btcData const &reference)
{
    
}




void readFromFile(std::vector<btcData> &btc, std::string const &filename)
{
    std::ifstream	file(filename.c_str());
	std::string line;
    
	if (!file.is_open())
		throw std::runtime_error("Opening file failed: " + filename);

	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("Table labels corrupted: " + filename);

    while(std::getline(file, line))
    {
        btcData tmp;
        std::stringstream ss(line);
        std::string tempDate;
	    std::string tempAmount;
	    std::string garbage;

        std::getline(ss, tempDate, '|');
		//tempDate = trim(tempDate);
		ss >> tempAmount;
		if (!checkDate(tmp, tempDate) || ss.fail())
		{
			std::cerr << "Invalid date format." << line << std::endl;
			continue;
		}
        ss >> garbage;
		if (!ss.fail())
			std::cerr << "Garbage characters on line." << line << std::endl;
        else if (!checkValue(tmp,tempAmount, 1)){}
        
        else
        {
            std::cout << tempDate << " => ";
            std::cout << tmp.amount << " = ";
            std::cout << exchangeResult(btc, tmp);
        }


    }
}
