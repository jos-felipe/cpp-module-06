/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:31:09 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/11 14:42:58 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
    (void)src;
    return *this;
}

ScalarConverter::~ScalarConverter(void) {}

bool ScalarConverter::isChar(const std::string &literal) {
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isInt(const std::string &literal) {
    size_t i = 0;
    
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    while (i < literal.length()) {
        if (!isdigit(literal[i]))
            return false;
        i++;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string &literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;
        
    size_t i = 0;
    bool hasDecimal = false;
    
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    while (i < literal.length() - 1) {
        if (literal[i] == '.') {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (!isdigit(literal[i]))
            return false;
        i++;
    }
    return (literal[literal.length() - 1] == 'f' && hasDecimal);
}

bool ScalarConverter::isDouble(const std::string &literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;
        
    size_t i = 0;
    bool hasDecimal = false;
    
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    while (i < literal.length()) {
        if (literal[i] == '.') {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (!isdigit(literal[i]))
            return false;
        i++;
    }
    return hasDecimal;
}

void ScalarConverter::convertChar(const std::string &literal) {
    char c = literal[1];
    
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertInt(const std::string &literal) {
    long value = std::atol(literal.c_str());
    
    if (value > std::numeric_limits<int>::max() || 
        value < std::numeric_limits<int>::min()) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    int i = static_cast<int>(value);
    if (i < 32 || i > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convertFloat(const std::string &literal) {
    float f;
    
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literal == "nanf") {
            f = std::numeric_limits<float>::quiet_NaN();
        } else if (literal == "+inff") {
            f = std::numeric_limits<float>::infinity();
        } else {
            f = -std::numeric_limits<float>::infinity();
        }
    } else {
        f = std::atof(literal.c_str());
        if (f < 32 || f > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        if (f > std::numeric_limits<int>::max() || 
            f < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(f) << std::endl;
    }
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertDouble(const std::string &literal) {
    double d;
    
    if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literal == "nan") {
            d = std::numeric_limits<double>::quiet_NaN();
        } else if (literal == "+inf") {
            d = std::numeric_limits<double>::infinity();
        } else {
            d = -std::numeric_limits<double>::infinity();
        }
    } else {
        d = std::atof(literal.c_str());
        if (d < 32 || d > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        if (d > std::numeric_limits<int>::max() || 
            d < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
    if (literal.empty()) {
        std::cout << "Error: empty input" << std::endl;
        return;
    }
    
    if (isChar(literal))
        convertChar(literal);
    else if (isInt(literal))
        convertInt(literal);
    else if (isFloat(literal))
        convertFloat(literal);
    else if (isDouble(literal))
        convertDouble(literal);
    else
        std::cout << "Error: invalid input" << std::endl;
}