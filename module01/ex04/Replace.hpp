/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 03:50:34 by msakata           #+#    #+#             */
/*   Updated: 2025/08/11 03:56:24 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <string>

class Replace
{
	private:
		std::string filename;
		std::string s1;
		std::string s2;
		
		std::string readFile();
		std::string replacAll(const std::string &content);
		bool writeFile(const std::string &content);

	public:
		Replace(const std::string &filename, const std::string &s1, const std::string &s2);
		bool process();
};

#endif
