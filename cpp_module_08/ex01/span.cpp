/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:26:04 by slee2             #+#    #+#             */
/*   Updated: 2021/11/24 19:44:11 by slee2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

const char*	Span::DataFullException::what() const throw() {
	return "Data already Full";
}

const char* Span::JustOneDataException::what() const throw() {
	return "There is only one data or no data";
}

Span::Span(): data(0, 0) {
	(this->data).reserve(0);
}

Span::Span(unsigned int N): data(0, 0) {
	(this->data).reserve(N);
}

Span::Span(const Span& s): data(0, 0) {
	(this->data).reserve(s.getData().capacity());
	std::copy(s.getData().begin(), s.getData().end(), back_inserter(this->data));
}

Span&	Span::operator=(const Span& s) {
	(this->data).clear();
	(this->data).reserve(s.getData().capacity());
	std::copy(s.getData().begin(), s.getData().end(), back_inserter(this->data));
	return *this;
}

std::vector<int>	Span::getData() const {
	return this->data;
}

void	Span::addNumber(int n) {
	if ((this->data).capacity() == (this->data).size())
		throw DataFullException();
	(this->data).push_back(n);
}

int	Span::shortestSpan() {
	if ((this->data).size() < 2)
		throw JustOneDataException();
	std::vector<int>	sort_data;
	sort_data.reserve((this->data).capacity());
	std::copy((this->data).begin(), (this->data).end(), back_inserter(sort_data));
	std::sort(sort_data.begin(), sort_data.end());
	std::adjacent_difference(sort_data.begin(), sort_data.end(), sort_data.begin());
	sort_data.erase(sort_data.begin());
	return (*min_element(sort_data.begin(), sort_data.end()));
}

int	Span::longestSpan() {
	if ((this->data).size() < 2)
		throw JustOneDataException();
	return (*max_element((this->data).begin(), (this->data).end()) - \
		*min_element((this->data).begin(), (this->data).end()));
}

Span::~Span() {}