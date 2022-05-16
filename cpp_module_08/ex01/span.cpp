#include "span.hpp"

Span::Span(): _vec(0, 0)
{
	(this->_vec).reserve(0);
}

Span::Span(unsigned int N): _vec(0, 0)
{
	(this->_vec).reserve(N);
}

Span::Span(const Span& s): _vec(0, 0)
{
	(this->_vec).reserve(s.getVector().capacity());
	std::copy(s.getVector().begin(), s.getVector().end(), back_inserter(this->_vec));
}

Span& Span::operator=(const Span& s)
{
	(this->_vec).clear();
	(this->_vec).reserve(s.getVector().capacity());
	std::copy(s.getVector().begin(), s.getVector().end(), back_inserter(this->_vec));
	return *this;
}

std::vector<int> Span::getVector() const
{
	return (this->_vec);
}

void Span::addNumber(int n)
{
	if ((this->_vec).capacity() == (this->_vec).size())
		throw DataFullException();
	(this->_vec).push_back(n);
}

int	Span::shortestSpan()
{
	if ((this->_vec).size() < 2)
		throw OneDataException();
	std::vector<int> sort_data;
	sort_data.reserve((this->_vec).capacity());
	std::copy((this->_vec).begin(), (this->_vec).end(), back_inserter(sort_data));
	std::sort(sort_data.begin(), sort_data.end());
	std::adjacent_difference(sort_data.begin(), sort_data.end(), sort_data.begin());
	sort_data.erase(sort_data.begin());
	return (*min_element(sort_data.begin(), sort_data.end()));
}

int	Span::longestSpan()
{
	if ((this->_vec).size() < 2)
		throw OneDataException();
	return (*max_element((this->_vec).begin(), (this->_vec).end()) - *min_element((this->_vec).begin(), (this->_vec).end()));
}

void Span::addMaxNumber(int n)
{
	if ((this->_vec).capacity() == (this->_vec).size())
		throw DataFullException();
	for (int i = this->getVector().size(); i < n; i++)
		addNumber(i);
}

const char*	Span::DataFullException::what() const throw() {
	return "vector is full";
}

const char* Span::OneDataException::what() const throw() {
	return "There is only one data.";
}

Span::~Span() {}