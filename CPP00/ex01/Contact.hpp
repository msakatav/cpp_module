/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 03:19:38 by msakata           #+#    #+#             */
/*   Updated: 2025/07/30 06:30:26 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		Contact();
		void set_first_name(const std::string &fn);
		void set_last_name(const std::string &ln);
		void set_nickname(const std::string &nn);
		void set_phone_number(const std::string &pn);
		void set_darkest_secret(const std::string &ds);

		std::string get_first_name() const;
		std::string get_last_name() const;
		std::string get_nickname() const;
		std::string get_phone_number() const;
		std::string get_darkest_secret() const;
		
		void display_contact() const;
};

#endif