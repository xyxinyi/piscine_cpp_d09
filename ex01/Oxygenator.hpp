/*
** EPITECH PROJECT, 2018
** CPP Pool Day 14
** File description:
** Oxygenator class definition
*/

#ifndef OXYGENATOR_HPP_
	#define OXYGENATOR_HPP_

	#include "BaseComponent.hpp"

class Oxygenator : public BaseComponent {
public:
	Oxygenator();
	virtual ~Oxygenator() {}

	void generateOxygen();
	void useOxygen(int quantity);

private:
	int _quantity;
};

#endif // OXYGENATOR_HPP_
