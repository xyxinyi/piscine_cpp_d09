/*
** EPITECH PROJECT, 2018
** CPP Pool Day 14
** File description:
** WaterReclaimer class definition
*/

#ifndef WATER_RECLAIMER_HPP_
	#define WATER_RECLAIMER_HPP_

	#include <cstddef>
	#include "BaseComponent.hpp"

class WaterReclaimer : public BaseComponent {
public:
	WaterReclaimer();
	virtual ~WaterReclaimer() {}

	void start();
	void generateWater();
	void useWater(int water);

private:
	int _water;
	bool _started;
};

#endif // WATER_RECLAIMER_HPP_
