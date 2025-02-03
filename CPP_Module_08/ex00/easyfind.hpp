#pragma once

#include <iterator>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int value);

#include "easyfind.tpp"
