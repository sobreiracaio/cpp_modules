/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:16:43 by crocha-s          #+#    #+#             */
/*   Updated: 2025/03/03 20:12:47 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string trimDate(std::string const &date)
{
    size_t start = date.find_first_not_of(" \t\n\r\f\v");
    size_t end = date.find_last_not_of(" \t\n\r\f\v");

    if (start == std::string::npos)
        return "";

    return (date.substr(start, end - start + 1));
}

bool checkDate(btcData &btc, std::string const &date)
{
    if(date.size() != 10
        ||  date.find_first_not_of("-0123456789") != std::string::npos		
		|| (date.find_first_of("-") != 4 || date.find_last_of("-") != 7))
  		    return (false);
      
            
    std::tm tm;
        if (strptime(date.c_str(), "%Y-%m-%d", &tm))
        {
            tm.tm_year += 1900;
            tm.tm_mon += 1;
            btc.date = tm;
            return (true);
        }
        std::cerr << "Error: Data is not properly formatted." << std::endl;
        return (false);
}

bool checkNumFormat(std::string const &ref)
{
    if ((ref.find_first_not_of("1234567890+-.") != std::string::npos)		
            || (ref.find_first_of(".") != ref.find_last_of("."))			
            || (ref.find_first_of(".") == ref.length() - 1)				
            || (ref.find_first_of(".") == 0)								
            || (ref.find_first_of("+-") != ref.find_last_of("+-")))
            {
                std::cerr << "Error: Number is not properly formatted." << std::endl;
                return (false);
            }
    return (true);	
}

bool checkValue(std::string const &data)
{
    if (!checkNumFormat(data))
		return (false);
	
	float nb = std::atof(data.c_str());

	if (nb < 0 || nb >= (float)INT_MAX)
    {
        std::cerr << "Error: Number out of limits" << std::endl;
		return (false);
    }
	return (true);
}

bool checkAmount(std::string const &amount)
{
    if(checkValue(amount))
        return (false);
    float nb = std::atof(amount.c_str());
    if(nb > 1000)
    {
        std::cerr << "Error: Number is too big, should be less than 1000" << std::endl;
    }
    return (true);
}
            
    

std::vector<btcData> readDB(void)
{
    std::ifstream file ("data.csv");
    std::vector<btcData> database;
	std::string line;
    
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
        std::stringstream ss(line);
        
        std::getline(ss, tmpDate, ',');
        ss >> tmpExchangeValue;
        if((!checkDate(tmp, tmpDate)) || !checkValue(tmpExchangeValue))
            throw std::runtime_error("Database corrupted");
        tmp.amount = std::atof(tmpExchangeValue.c_str());
        database.push_back(tmp);
        
    }
    file.close();
    return (database);
}

int dateComparison(std::tm const &dbDate, std::tm const &refDate)
{
    if (dbDate.tm_year > refDate.tm_year)
		return (1);
	else if (dbDate.tm_year < refDate.tm_year)
		return (-1);
	else if (dbDate.tm_mon > refDate.tm_mon)
		return (1);
	else if (dbDate.tm_mon < refDate.tm_mon)
		return (-1);
	else if (dbDate.tm_mday > refDate.tm_mday)
		return (1);
	else if (dbDate.tm_mday < refDate.tm_mday)
		return (-1);
	return (0);
}


float exchangeResult(std::vector<btcData> const &database, btcData const &reference)
{
    if (dateComparison(database[0].date, reference.date) == 1)
		return (0);

	std::vector<btcData>::const_iterator it;

	for (it = database.begin(); it != database.end(); it++)
	{
		btcData db = *it;

		int cmp = dateComparison(db.date, reference.date);
		if (cmp == 0)
			return (db.amount * reference.amount);
		else if (cmp == 1) // if the database date is after the input date
		{
			it--;
			db = *it;
			return (db.amount * reference.amount);
		}
	}
	btcData lastValue = database.back();
	return (lastValue.amount * reference.amount);
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
        std::string tempDate;
	    std::string tempAmount;
	    std::string garbage;
        std::stringstream ss(line);
        
        std::getline(ss, tempDate, '|');
		tempDate = trimDate(tempDate);
        
		ss >> tempAmount;
        tmp.amount = std::atof(tempAmount.c_str());
		if (!checkDate(tmp, tempDate) || ss.fail())
		{
			std::cerr << "Error: Invalid date format." << line << std::endl;
			continue;
		}
        ss >> garbage;
		if (!ss.fail())
			std::cerr << "Garbage characters on line." << line << std::endl;
        else if (!checkAmount(tempAmount)){}
        
        else
        {
            
            std::cout << tempDate << " => ";
            std::cout << tmp.amount << " = ";
            std::cout << exchangeResult(btc, tmp) << std::endl;
        }


    }
    file.close();
}
