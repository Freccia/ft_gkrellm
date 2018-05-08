/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:31:08 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/08 13:15:37 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

Contact::Contact(void){
	return;
}

Contact::~Contact(void){
	return;
}

void	Contact::printme(void){
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Login: " << login << std::endl;
	std::cout << "Postal code: " << postal << std::endl;
	std::cout << "Email: " << email << std::endl;
	std::cout << "Phone: " << phone << std::endl;
	std::cout << "Birthday: " << birthday << std::endl;
	std::cout << "Favourite meal: " << meal << std::endl;
	std::cout << "Underwear color: " << underwear << std::endl;
	std::cout << "Darkest secret: " << secret << std::endl;
	std::cout << std::endl;
}

Phonebook::Phonebook(void): ncont(0){
	return;
}

Phonebook::~Phonebook(void){
	return;
}

void	Phonebook::clear_eof(void){
	if(std::cin.eof()){
		std::cin.clear();
	}
}

int		Phonebook::ADD(void){
	if (this->ncont >= 8)
	{
		std::cout << "The Phonebook is full, sorry." << std::endl;
		return 1;
	}

	std::cout << "First Name: ";
	std::getline (std::cin, contacts[this->ncont].first_name);
	clear_eof();
	std::cout << "Last Name: ";
	std::getline (std::cin, contacts[this->ncont].last_name);
	clear_eof();
	std::cout << "Nickname: ";
	std::getline (std::cin, contacts[this->ncont].nickname);
	clear_eof();
	std::cout << "Login: ";
	std::getline (std::cin, contacts[this->ncont].login);
	clear_eof();
	std::cout << "Postal address: ";
	std::getline (std::cin, contacts[this->ncont].postal);
	clear_eof();
	std::cout << "Email address: ";
	std::getline (std::cin, contacts[this->ncont].email);
	clear_eof();
	std::cout << "Phone number: ";
	std::getline (std::cin, contacts[this->ncont].phone);
	clear_eof();
	std::cout << "Birthday date: ";
	std::getline (std::cin, contacts[this->ncont].birthday);
	clear_eof();
	std::cout << "Favourite meal: ";
	std::getline (std::cin, contacts[this->ncont].meal);
	clear_eof();
	std::cout << "Underwear color: ";
	std::getline (std::cin, contacts[this->ncont].underwear);
	clear_eof();
	std::cout << "Darkest secret: ";
	std::getline (std::cin, contacts[this->ncont].secret);
	clear_eof();

	std::cout << std::endl;
	std::cout << "Contact addedd to Phonebook." << std::endl;
	std::cout << std::endl;
	this->ncont++;

	return 0;
}

void	Phonebook::SEARCH(){
	std::cout << " n |";
	std::cout << "first name|";
	std::cout << "last name |";
	std::cout << " nickname |" << std::endl;

	if (this->ncont <= 0)
		return;

	size_t len;

	for (int i=0; i < this->ncont; i++)
	{
		std::cout << " " << i << " |";

		len = std::min(9, static_cast<int>(contacts[i].first_name.size()));
		std::cout.write(contacts[i].first_name.c_str(), len);
		if (len == 9)
			std::cout << ".|";
		else
			std::cout << std::string(10 - len, ' ') << "|";

		len = std::min(9, static_cast<int>(contacts[i].last_name.size()));
		std::cout.write(contacts[i].last_name.c_str(), len);
		if (len == 9)
			std::cout << ".|";
		else
			std::cout << std::string(10 - len, ' ') << "|";

		len = std::min(9, static_cast<int>(contacts[i].nickname.size()));
		std::cout.write(contacts[i].nickname.c_str(), len);
		if (len == 9)
			std::cout << ".|";
		else
			std::cout << std::string(10 - len, ' ') << "|";

		std::cout << std::endl;
	}
}

int		Phonebook::SELECT(int index) {
	if (index < 0 || index >= this->ncont)
	{
		std::cout << "Invalid index." << std::endl;
		return 1;
	}

	contacts[index].printme();
	return 0;
}

void	Phonebook::test(void)
{
	if(this->ncont > 4)
		return;
	contacts[this->ncont].first_name = "Lady";
	contacts[this->ncont].last_name = "Oscar";
	contacts[this->ncont].nickname = "Mom";
	contacts[this->ncont].login = "ldoscar";
	contacts[this->ncont].postal = "78";
	contacts[this->ncont].email = "oscarlady@mail.com";
	contacts[this->ncont].phone = "04 55 66 883";
	contacts[this->ncont].birthday = "04/1972";
	contacts[this->ncont].meal = "rose";
	contacts[this->ncont].underwear = "white";
	contacts[this->ncont].secret = "I like gurlz";
	this->ncont++;
	contacts[this->ncont].first_name = "Sudo";
	contacts[this->ncont].last_name = "Saudo";
	contacts[this->ncont].nickname = "Weed Dealer";
	contacts[this->ncont].login = "sudo";
	contacts[this->ncont].postal = "93";
	contacts[this->ncont].email = "sudo@93.fr";
	contacts[this->ncont].phone = "07 55 66 88 00";
	contacts[this->ncont].birthday = "420";
	contacts[this->ncont].meal = "pizza";
	contacts[this->ncont].underwear = "green";
	contacts[this->ncont].secret = "I sell drugs";
	this->ncont++;
	contacts[this->ncont].first_name = "Paulette";
	contacts[this->ncont].last_name = "Lafont";
	contacts[this->ncont].nickname = "Mamie";
	contacts[this->ncont].login = "mamiepaulette";
	contacts[this->ncont].postal = "4040";
	contacts[this->ncont].email = "mamiepaulette@home.tk";
	contacts[this->ncont].phone = "09 88 22 33 45";
	contacts[this->ncont].birthday = "1/1/1900";
	contacts[this->ncont].meal = "cookies";
	contacts[this->ncont].underwear = "shuld not ask";
	contacts[this->ncont].secret = "My cookies's recipe";
	this->ncont++;
}
