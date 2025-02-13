/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:10:42 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/13 11:32:59 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Base.hpp"

int main(void)
{
    std::srand(static_cast<unsigned>(std::time(NULL)));
	
	// Test multiple random generations
    for (int i = 0; i < 5; i++) {
        std::cout << "\nTest " << i + 1 << ":" << std::endl;
        
        // Generate random instance
        Base* ptr = generate();
        
        // Test pointer identification
        std::cout << "Pointer identification: ";
        identify(ptr);
        
        // Test reference identification
        std::cout << "Reference identification: ";
        identify(*ptr);
        
        // Clean up
        delete ptr;
    }
    
    return 0;
}