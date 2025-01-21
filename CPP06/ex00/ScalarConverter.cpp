/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:11:38 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/21 22:55:47 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
    *this = copy;
}

ScalarConverter::~ScalarConverter(){}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy)
{
    if (this == &copy)
        return (*this);
    return (*this);
}



static bool isNanOrInf(std::string const &data)
{
    return(data == "nan" || data == "nanf" || data == "+inf" || data == "-inf" || data == "+inff" || data == "-inff" || data == "inf" || data == "inff");
}

static bool isPritable(std::string const &data)
{
    char c = data[0];
    if(c < 0 || (c >= 0 && c <= 31) || c >= 127)
        return (false);
    return (true);
    
        
}

static bool signalPos(std::string const &data)
{
    if(data.find_first_of(SIGNAL) == std::string::npos)
        return (true);
    if(data.find_first_of(SIGNAL) != 0 || data.find_last_of(SIGNAL) != 0)
            return (false);
    return (true);
}

static bool countSymbol(std::string const &data, char symbol)
{
    int count = 0;
    if(data.find_first_of(SIGNAL) == std::string::npos)
        return (true);
    for(size_t i = 0; i < data.length(); i++)
    {
        if(data[i] == symbol)
            count++;
    }
    if(count > 1)
        return (false);
    return (true);
}

static bool checkSymbolPosition (std::string const &data, char symbol)
{
    if(symbol == 'f')
    {
        int pos = data.find_first_of(symbol);
        
        if(data.find_first_of(symbol) != data.length() -1)
            return (false);
        if(data[pos - 1] == '.')
            return (false);
    }
    if(symbol == '.')
    {
        if(data[0] == symbol || data[data.length()] == symbol)
            return (false);
        if(data[1] == symbol && data.find_first_of(SIGNAL) == 0)
            return (false);
    }
    return (true);
}
static bool parseData(std::string const &data, int type)
{
    if(type == INT && signalPos(data))
        return (true);
    if(type == FLOAT && signalPos(data) && countSymbol(data, '.') && countSymbol(data, 'f') && checkSymbolPosition(data, 'f') && checkSymbolPosition(data, '.')) 
        return (true);
    if(type == DOUBLE && signalPos(data) && countSymbol(data, '.') && checkSymbolPosition(data, '.'))
        return (true);
    
       
    return(false);
}

static bool isChar(std::string const &data)
{
    return (data.length() == 1 && isPritable(data));
}

static bool isInt(std::string const &data)
{
    return (data.find_first_not_of(INT_SET) == std::string::npos);
}

static bool isFloat(std::string const &data)
{
    return (data.find_first_not_of(FLOAT_SET) == std::string::npos);
}

static bool isDouble(std::string const &data)
{
    return (data.find_first_not_of(DOUBLE_SET) == std::string::npos);
}

int ScalarConverter::_inputParser(std::string const &input)
{
    if(isNanOrInf(input))
        return (INF_NAN);
    else if(isInt(input) && parseData(input, INT))
        return (INT);
    else if(isChar(input))
        return (CHAR);
    else if(isFloat(input) && parseData(input, FLOAT))
        return (FLOAT);
    else if (isDouble(input) && parseData(input, DOUBLE))
        return (DOUBLE);
        
    return (ERROR);
}




void ScalarConverter::_printData(int i, char c, float f, double d, int type)
{
  
}

void ScalarConverter::_convertData(std::string const &data, int type)
{
    int i = 0;
    char c = 0;
    float f = 0;
    double d = 0;

    if(type == INF_NAN)
    {
        ScalarConverter::_printData(i, c, f, d, INF_NAN);
        return;
    }
    else
    {
        switch (type)
        {
        case INT:
            i = std::atoi(data.c_str());
            c = static_cast<unsigned char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            break;
        case CHAR:
            c = static_cast<unsigned char>(data[0]);
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break;
        
        case FLOAT:
            f = std::atof(data.c_str());
            d = static_cast<double>(f);
            i = static_cast<int>(f);
            c = static_cast<unsigned char>(f);
            break;
        
        case DOUBLE:
            d = static_cast<double>(std::atof(data.c_str()));
            f = static_cast<float>(d);
            i = static_cast<int>(d);
            c = static_cast<char>(d);
            break;
        }
        ScalarConverter::_printData(i, c, f, d, type);
    }
}

void ScalarConverter::convert(const std::string &data)
{
    int type = _inputParser(data);
    
    switch (type)
    {
        case INF_NAN:
            
            
    }
}

