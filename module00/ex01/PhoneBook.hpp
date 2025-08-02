/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:37:02 by msakata           #+#    #+#             */
/*   Updated: 2025/07/30 07:22:06 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook
{
	private:
		Contact contacts[MAX_CONTACTS];
		int 	current_contacts;
		int		contacts_count;
		
		bool safe_getline(std::string &input) const;
		void add_command();
		void add_first_name(std::string &input);
		void add_last_name(std::string &input);
		void add_nickname(std::string &input);
		void add_phone_number(std::string &input);
		void add_darkest_secret(std::string &input);
		bool is_valid_name(const std::string &input) const;
		bool is_valid_phone_number(const std::string &input) const;
		void search_command() const;
		std::string print_contacts_string(const std::string &str) const;
		bool is_valid_index(std::string &index) const;
		bool is_only_spaces(const std::string &str) const;
		
	public:
		PhoneBook();
		void run();
};

#endif