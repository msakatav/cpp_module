/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 07:53:20 by msakata           #+#    #+#             */
/*   Updated: 2025/08/22 10:12:02 by msakata          ###   ########TOKYO.jp  */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		learned[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.learned[i])
			learned[i] = other.learned[i]->clone();
		else
			learned[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete learned[i];
			learned[i] = NULL;
			if (other.learned[i])
				learned[i] = other.learned[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete learned[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!learned[i])
		{
			learned[i] = m;
			return;
		}
	}
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (learned[i] && learned[i]->getType() == type)
			return learned[i]->clone();
	}
	return NULL;
}