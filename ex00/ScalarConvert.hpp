/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:20:05 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/11 12:23:44 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <limits>
# include <cmath>

class ScalarConverter {
private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &src);
    ScalarConverter &operator=(const ScalarConverter &src);
    ~ScalarConverter(void);

    static bool    isChar(const std::string &literal);
    static bool    isInt(const std::string &literal);
    static bool    isFloat(const std::string &literal);
    static bool    isDouble(const std::string &literal);

    static void    convertChar(const std::string &literal);
    static void    convertInt(const std::string &literal);
    static void    convertFloat(const std::string &literal);
    static void    convertDouble(const std::string &literal);

public:
    static void    convert(const std::string &literal);
};

#endif