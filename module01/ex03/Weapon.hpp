/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 03:57:33 by msakata           #+#    #+#             */
/*   Updated: 2025/08/10 21:36:05 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <string>

class Weapon
{
	private:
		std::string type;
	
	public:
		Weapon(const std::string &type);
		const std::string &getType() const;
		void setType(const std::string &new_type);
};

#endif