#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <list>
# include <algorithm>
# include <limits>

const int MAX_VALID_YR = 2023;
const int MIN_VALID_YR = 2009;

class BitcoinExchange
{
	public:
		// Constructors
		BitcoinExchange(void);
		BitcoinExchange(const std::string& csv_file, const std::string& input_file);
		BitcoinExchange(const BitcoinExchange &copy);

		// Destructor
		~BitcoinExchange(void);

		// Operators
		BitcoinExchange & operator=(const BitcoinExchange &assign);

		// Methods
		double calculateValue(const std::string& str_date, double amount);
		bool isLeap(int year);
		bool isValidDate(const std::string& str_date);

	private:
		// Attributes
		typedef std::pair<std::string, double> Price;
		typedef std::list<Price> PriceList;
		PriceList	_price_list;
		std::string _date;
		double		_value;

		// Methods
		void _buildPriceList(const std::string& csv_file);
		void _readFile(const std::string& input_file);
};

#endif