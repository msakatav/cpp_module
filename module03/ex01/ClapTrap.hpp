/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 00:11:50 by msakata           #+#    #+#             */
/*   Updated: 2025/08/17 10:48:05 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	// ScavTrap からアクセスできるように、基底クラスのメンバ変数は protected に変更しておきます。
	// privateとprotectedの違いは？
	protected:
		std::string _name;
		int _hit_points;
		int _energy_points;
		int _attack_damage;

	public:
		ClapTrap(const std::string &_name);
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &other);
		// vitual 仮想関数とは何か？
		// virtual をつけると 「動的ポリモーフィズム（多態性）」 が有効になります。
		// virtual デストラクタが必要な理由
		// 基底クラスをポインタで扱うとき、デストラクタを virtual にしないと 派生クラスのデストラクタが呼ばれない
		virtual ~ClapTrap();

		virtual void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif