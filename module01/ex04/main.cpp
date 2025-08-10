/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 00:12:46 by msakata           #+#    #+#             */
/*   Updated: 2025/08/11 04:18:03 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
		return 1;
	
	// std::string にはconst char*を受け取るコンストラクタがある。
	Replace replacer(argv[1], argv[2], argv[3]);
	if (!replacer.process())
		return 1;
}