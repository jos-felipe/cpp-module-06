/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:23:34 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/11 16:24:23 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(void) {
    // Create a Data object
    Data originalData;
    originalData.id = 42;
    originalData.name = "Hello, World!";
    
    // Print original data
    std::cout << "Original - Address: " << &originalData << std::endl;
    std::cout << "Original - ID: " << originalData.id << std::endl;
    std::cout << "Original - Name: " << originalData.name << std::endl;
    
    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(&originalData);
    std::cout << "\nSerialized value: " << serialized << std::endl;
    
    // Deserialize back to pointer
    Data *deserialized = Serializer::deserialize(serialized);
    
    // Print deserialized data
    std::cout << "\nDeserialized - Address: " << deserialized << std::endl;
    std::cout << "Deserialized - ID: " << deserialized->id << std::endl;
    std::cout << "Deserialized - Name: " << deserialized->name << std::endl;
    
    // Compare pointers
    std::cout << "\nPointers are ";
    std::cout << (&originalData == deserialized ? "equal" : "different");
    std::cout << std::endl;
    
    return (0);
}