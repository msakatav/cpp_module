/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 00:46:09 by msakata           #+#    #+#             */
/*   Updated: 2025/07/31 01:05:55 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostram>
#include <string>

int main()
{
	std::string brain = "HI THIS IS BRAIN";

	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "Memory address of brain          : " << &brain << std::endl;
	std::cout << "Memory address held by stringPTR : " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF : " << &stringREF << std::endl;

	std::cout << "Value of brain                 : " << brain << std::endl;
	std::cout << "Value pointed to by stringPTR  : " << *stringPTR << std::endl;
	std::cout << "Value referred to by stringREF : " << stringREF << std::endl;
	
	return 0;
}