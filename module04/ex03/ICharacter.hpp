/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 07:53:06 by msakata           #+#    #+#             */
/*   Updated: 2025/08/22 09:12:58 by msakata          ###   ########TOKYO.jp  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <string>

// なぜ、このような書き方にしている？
// なぜ、プロトタイプ宣言してるの？
class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		// この文法どういうこと？
		virtual std::string const &getName() const = 0;
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
};

#endif