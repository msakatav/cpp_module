/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 01:09:08 by msakata           #+#    #+#             */
/*   Updated: 2025/08/18 05:12:03 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		// DiamondTrap独自の名前。
		// これによるリスクは？
		// リスク1. 名前のシャドウイング（隠蔽）
		// どちらの _name を使いたいかを明示しないと曖昧になるリスクがあります
		// リスク2. -Wshadow 警告
		// GCC/Clang の -Wshadow フラグを有効にすると、
		// 基底クラスのメンバを派生クラスの同名変数が隠していると警告が出ます。
		std::string _name;

	public:
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &other);
		~DiamondTrap();

		void attack(const std::string &target);
		void whoAmI();
};

#endif