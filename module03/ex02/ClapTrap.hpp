/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 00:11:50 by msakata           #+#    #+#             */
/*   Updated: 2025/08/18 01:06:56 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string _name;
		int _hit_points;
		int _energy_points;
		int _attack_damage;

	public:
		ClapTrap(const std::string &_name);
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &other);
		// なぜ、デストラクタだけvirtual?
		// C++ の仕様上、コンストラクタは virtual にできません。
		// 理由は簡単で、オブジェクトの型は生成時に決まるからです。
		// じゃあコピーコンストラクタや operator= は？
		// 理由は同じで、コピーや代入されるオブジェクトの型はすでに確定しているから。
		virtual ~ClapTrap();

		virtual void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif