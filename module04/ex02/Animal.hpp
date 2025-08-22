/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:32:28 by msakata           #+#    #+#             */
/*   Updated: 2025/08/22 05:48:30 by msakata          ###   ########TOKYO.jp  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		// = 0とは？　ー＞　純粋仮想関数のシンボル
		// これで、クラスは抽象クラスになる。
		// クラス内に 純粋仮想関数（pure virtual function） が1つでもあると、そのクラスは 抽象クラス になります。
		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif