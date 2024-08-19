/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:39:18 by bazuara           #+#    #+#             */
/*   Updated: 2024/08/19 13:51:05 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string input)
{
    _input = input;
    _char = 0;
    _int = 0;
    _float = 0;
    _double = 0;
    _isChar = false;
    _isInt = false;
    _isFloat = false;
    _isDouble = false;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    if (this != &copy)
    {
        this->_input = copy._input;
        this->_char = copy._char;
        this->_int = copy._int;
        this->_float = copy._float;
        this->_double = copy._double;
        this->_isChar = copy._isChar;
        this->_isInt = copy._isInt;
        this->_isFloat = copy._isFloat;
        this->_isDouble = copy._isDouble;
    }
    return *this;
}

void ScalarConverter::convert()
{
    if (_input.length() == 1 && !isdigit(_input[0]))
    {
        _char = _input[0];
        _isChar = true;
    }
    else
    {
        try
        {
            _int = std::stoi(_input);
            _isInt = true;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        try
        {
            _float = std::stof(_input);
            _isFloat = true;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        try
        {
            _double = std::stod(_input);
            _isDouble = true;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

void ScalarConverter::printChar()
{
    if (_isChar)
        std::cout << "char: '" << _char << "'" << std::endl;
    else if (_isInt && _int >= 32 && _int <= 126)
        std::cout << "char: '" << static_cast<char>(_int) << "'" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
}

void ScalarConverter::printInt()
{
    if (_isChar)
        std::cout << "int: " << static_cast<int>(_char) << std::endl;
    else if (_isInt)
        std::cout << "int: " << _int << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::printFloat()
{
    if (_isChar)
        std::cout << "float: " << static_cast<float>(_char) << ".0f" << std::endl;
    else if (_isInt)
        std::cout << "float: " << static_cast<float>(_int) << ".0f" << std::endl;
    else if (_isFloat)
        std::cout << "float: " << _float << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
}

void ScalarConverter::printDouble()
{
    if (_isChar)
        std::cout << "double: " << static_cast<double>(_char) << ".0" << std::endl;
    else if (_isInt)
        std::cout << "double: " << static_cast<double>(_int) << ".0" << std::endl;
    else if (_isFloat)
        std::cout << "double: " << static_cast<double>(_float) << ".0" << std::endl;
    else if (_isDouble)
        std::cout << "double: " << _double << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}
