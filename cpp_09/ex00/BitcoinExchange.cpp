#include "BitcoinExchange.hpp"

// Constructors
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& csv_file, const std::string& input_file) {
	_buildPriceList(csv_file);
	_readFile(input_file);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	_date = copy._date;
	_value = copy._value;
	_price_list = copy._price_list;
}

// Destructor
BitcoinExchange::~BitcoinExchange(void) {
	_price_list.clear();
}


// Operators
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	if (this != &assign) {
		_date = assign._date;
		_value = assign._value;
		_price_list = assign._price_list;
	}
	return (*this);
}

// Methods
void BitcoinExchange::_buildPriceList(const std::string& csv_file) {
	std::ifstream file(csv_file.c_str());
	if (!file)
		throw std::runtime_error("Error: could not open data file " + csv_file);
	std::string line;
	getline(file, line);
	while (getline(file, line)) {
		std::istringstream iss(line);
		std::string str_date, str_value;
		getline(iss, str_date, ',');
		getline(iss, str_value);
		double value = atof(str_value.c_str());
		_price_list.push_back(std::make_pair(str_date, value));
	}
}

double BitcoinExchange::calculateValue(const std::string& str_date, double amount) {
    try {
        if (amount < 0)
            throw std::invalid_argument("Error: not a positive number.");
        PriceList::iterator it;
        for (it = _price_list.begin(); it != _price_list.end(); ++it) {
            double value = it->second * amount;
            if (value > std::numeric_limits<int>::max())
                throw std::overflow_error("Error: too large a number.");
            if (it->first == str_date)
                return value;
            if (it->first > str_date) {
                if (it == _price_list.begin())
                    throw std::invalid_argument("Error: bad input => " + str_date);
                --it;
                return it->second * amount;
            }
        }
        throw std::out_of_range("Error: could not find price for date " + str_date);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (0.0);
    }
}

void BitcoinExchange::_readFile(const std::string& input_file) {
	std::ifstream file(input_file.c_str());
    std::string line;
	getline(file, line);
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string date_str, value_str;
        getline(iss, date_str, '|');
        getline(iss, value_str, '|');
        double amount = atof(value_str.c_str());

        double value = this->calculateValue(date_str, amount);
		if (value != 0.0)
        	std::cout << date_str << "=> " << amount << " = " << value << std::endl;
    }
}
