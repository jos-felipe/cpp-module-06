/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:15:42 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/11 16:17:17 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {
}

Serializer::Serializer(const Serializer &src) {
    (void)src;
}

Serializer &Serializer::operator=(const Serializer &rhs) {
    (void)rhs;
    return (*this);
}

Serializer::~Serializer(void) {
}

uintptr_t Serializer::serialize(Data *ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}