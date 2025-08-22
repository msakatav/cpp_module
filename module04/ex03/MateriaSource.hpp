/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 07:53:24 by msakata           #+#    #+#             */
/*   Updated: 2025/08/22 09:52:18 by msakata          ###   ########TOKYO.jp  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *learned[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & other);
		MateriaSource& operator=(MateriaSource const & other);
		~MateriaSource();

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif