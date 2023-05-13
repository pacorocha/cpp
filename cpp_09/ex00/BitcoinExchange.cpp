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
        if (!isValidDate(str_date))
            throw std::invalid_argument("Error: invalid date => " + str_date);
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
                return (--it)->second * amount;
            }
        }
		if (it == _price_list.end())
			return (--it)->second * amount;
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
		date_str = date_str.substr(0, date_str.size()-1);
        double value = this->calculateValue(date_str, amount);
		if (value != 0.0)
        	std::cout << date_str << "=> " << amount << " = " << value << std::endl;
    }
}

static bool isLeap(int year)
{
// Return true if year
// is a multiple of 4 and
// not multiple of 100.
// OR year is multiple of 400.
return (((year % 4 == 0) &&
         (year % 100 != 0)) ||
         (year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string& str_date) {
	std::string delimiter = "-";
	std::string year_str = str_date.substr(0, 4);
	std::string month_str = str_date.substr(5, 2);
	std::string day_str = str_date.substr(8, 2);
	int y, m, d;
	std::istringstream year_ss(year_str);
	std::istringstream month_ss(month_str);
	std::istringstream day_ss(day_str);

	if (str_date.length() != 10)
		return false;
	if (!(year_ss >> y) || !(month_ss >> m) || !(day_ss >> d)) {
		return false;
	}
	if (y > MAX_VALID_YR || y < MIN_VALID_YR)
		return false;
	if (m < 1 || m > 12)
		return false;
	if (d < 1 || d > 31)
		return false;
	if (m == 2) {
		if (isLeap(y))
			return (d <= 29);
		else
			return (d <= 28);
	}
	if (m == 4 || m == 6 || m == 9 || m == 11)
		return (d <= 30);
	return true;
}
