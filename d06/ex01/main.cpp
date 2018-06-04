/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:37:18 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/04 17:13:06 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void	*serialize(void) {
	char	alfa[] = "ABCDEFGHJIKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	char	*serial = new char[8 + sizeof(int) + 8];
	char	*ptr = serial;

	srand(std::time(0));
	for (int i=0; i < 8; i++) {
		*serial = alfa[rand() % (sizeof(alfa) - 1)];
		serial++;
	}
	*(reinterpret_cast<int*>(serial)) = rand() % std::numeric_limits<int>::max();
	serial += sizeof(int);
	for (int i=0; i < 8; i++) {
		*serial = alfa[rand() % (sizeof(alfa) - 1)];
		serial++;
	}
	return ptr;
}

Data	*deserialize(void *raw) {
	Data *data = new Data;

	char *ptr = reinterpret_cast<char *>(raw);
	data->s1.assign(ptr, 8);
	data->n = *(reinterpret_cast<int *>(&ptr[8]));
	data->s2.assign(ptr + 8 + sizeof(int), ptr + 8 + sizeof(int) + 8);
	return data;
}

int		main(void) {
	void	*ptr;
	Data	*data;

	ptr = serialize();
	data = deserialize(ptr);
	std::cout << "Ptr: " << ptr << std::endl;
	std::cout << "s1: <" << data->s1 << ">" << std::endl;
	std::cout << "n:  <" << data->n << ">" << std::endl;
	std::cout << "s2: <" << data->s2 << ">" << std::endl;
	return 0;
}
