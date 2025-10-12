#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <exception>
# include <limits>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
		
	public:
		// Orthodox Canonical Form
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		
		// Member functions
		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;
		
		// Bonus: add range of numbers using iterators
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			while (begin != end)
			{
				addNumber(*begin);
				++begin;
			}
		}
		
		// Getters
		unsigned int size() const;
		unsigned int maxSize() const;
		
		// Exceptions
		class FullException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Span is full, cannot add more numbers";
				}
		};
		
		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Not enough numbers to calculate span";
				}
		};
};

#endif

