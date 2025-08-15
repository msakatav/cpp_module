/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 03:32:34 by msakata           #+#    #+#             */
/*   Updated: 2025/08/15 23:32:09 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main()
{
	Fixed a;// ← これがインスタンス生成
	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	// maxが、staticのメンバ関数なので、インスタンスを経由しないで呼べる、
	// インスタンスとは？
	// クラス（設計図）から実際に作られた現物（オブジェクト）
	std::cout << Fixed::max(a, b) << std::endl;
}