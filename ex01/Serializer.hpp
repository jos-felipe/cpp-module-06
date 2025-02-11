/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:12:50 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/11 16:13:26 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

class Serializer {
private:
    Serializer(void);
    Serializer(const Serializer &src);
    Serializer &operator=(const Serializer &rhs);
    ~Serializer(void);

public:
    static uintptr_t    serialize(Data *ptr);
    static Data        *deserialize(uintptr_t raw);
};

#endif