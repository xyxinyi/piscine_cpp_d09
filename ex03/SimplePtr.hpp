/*
** EPITECH PROJECT, 2018
** CPP Pool Day 14
** File description:
** SimplePtr class definition
*/

#ifndef SIMPLE_PTR_HPP_
	#define SIMPLE_PTR_HPP_

	#include "BaseComponent.hpp"

class SimplePtr {
public:
	explicit SimplePtr(BaseComponent *rawPtr);
	~SimplePtr();
	BaseComponent *get() const;

private:
	// Make the class non copyable
	SimplePtr(SimplePtr const &);
	SimplePtr &operator=(SimplePtr const &);

	BaseComponent *_rawPtr;
};

#endif // SIMPLE_PTR_HPP_
