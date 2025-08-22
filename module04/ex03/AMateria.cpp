/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 07:52:37 by msakata           #+#    #+#             */
/*   Updated: 2025/08/22 10:09:34 by msakata          ###   ########TOKYO.jp  */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
	: type(type)
{}

AMateria::~AMateria()
{}

std::string const &AMateria::getType() const
{
	return type;
}

// なぜ、voidで返す必要がある？
void AMateria::use(ICharacter &target)
{
	(void)target;
}