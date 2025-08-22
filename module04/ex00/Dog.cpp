/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:03:20 by msakata           #+#    #+#             */
/*   Updated: 2025/08/19 04:23:00 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	// これは、基底クラスで"Animal"で初期化しているメンバ変数を上書きしている？
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
	/*
	なぜコンストラクタの方は、初期化で、来てクラスを呼び出すのを省略しているのに
	コピーコンストラクタの方は省略していないの？
	*/ 
	/*
	コピーコンストラクタでは、基底クラス部分をどうコピーするか を指定する必要がある。
	もし : Animal(other) を書かないと、
	自動的に Animal() デフォルトコンストラクタ が呼ばれてしまい、
	other の内容はコピーされない。
	*/
	: Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Dog class assigned" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}