/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:37:20 by bazuara           #+#    #+#             */
/*   Updated: 2024/08/19 13:39:12 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
private:
    std::string _input;
    char _char;
    int _int;
    float _float;
    double _double;
    bool _isChar;
    bool _isInt;
    bool _isFloat;
    bool _isDouble;

public:
    ScalarConverter(std::string input);
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &copy);

    void convert();
    void printChar();
    void printInt();
    void printFloat();
    void printDouble();
};

#endif // SCALARCONVERTER_HPP