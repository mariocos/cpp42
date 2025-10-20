#include "BitcoinExchange.hpp"
#include <limits>

// Orthodox Canonical Form

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

// Helper methods

void BitcoinExchange::trim(std::string& str) const {
    size_t start = 0;
    size_t end = str.length();
    
    while (start < end && (str[start] == ' ' || str[start] == '\t' || str[start] == '\n' || str[start] == '\r')) {
        start++;
    }
    
    while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t' || str[end - 1] == '\n' || str[end - 1] == '\r')) {
        end--;
    }
    
    str = str.substr(start, end - start);
}

bool BitcoinExchange::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10) {
        return false;
    }
    
    if (date[4] != '-' || date[7] != '-') {
        return false;
    }
    
    // Extract year, month, day
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    
    // Check if all characters are digits
    for (size_t i = 0; i < yearStr.length(); i++) {
        if (!isdigit(yearStr[i])) return false;
    }
    for (size_t i = 0; i < monthStr.length(); i++) {
        if (!isdigit(monthStr[i])) return false;
    }
    for (size_t i = 0; i < dayStr.length(); i++) {
        if (!isdigit(dayStr[i])) return false;
    }
    
    int year = atoi(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());
    
    // Validate month
    if (month < 1 || month > 12) {
        return false;
    }
    
    // Days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    
    // Validate day
    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }
    
    // Check if year is reasonable (Bitcoin started in 2009)
    if (year < 2009 || year > 2024) {
        return false;
    }
    
    return true;
}

float BitcoinExchange::stringToFloat(const std::string& str, bool& success) const {
    success = true;
    char* end;
    float value = strtof(str.c_str(), &end);
    
    if (end == str.c_str() || *end != '\0') {
        success = false;
        return 0.0f;
    }
    
    return value;
}

// Main functionality

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return false;
    }
    
    std::string line;
    bool firstLine = true;
    
    while (std::getline(file, line)) {
        // Skip header line
        if (firstLine) {
            firstLine = false;
            continue;
        }
        
        if (line.empty()) {
            continue;
        }
        
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos) {
            continue;
        }
        
        std::string date = line.substr(0, commaPos);
        std::string valueStr = line.substr(commaPos + 1);
        
        trim(date);
        trim(valueStr);
        
        if (!isValidDate(date)) {
            continue;
        }
        
        bool success;
        float value = stringToFloat(valueStr, success);
        
        if (success && value >= 0) {
            _database[date] = value;
        }
    }
    
    file.close();
    
    if (_database.empty()) {
        std::cerr << "Error: database is empty or invalid." << std::endl;
        return false;
    }
    
    return true;
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
    // Try exact match first
    std::map<std::string, float>::const_iterator it = _database.find(date);
    if (it != _database.end()) {
        return it->second;
    }
    
    // Find closest earlier date using lower_bound
    it = _database.lower_bound(date);
    
    // If lower_bound returns begin(), the date is before all dates in database
    if (it == _database.begin()) {
        return -1.0f; // Indicate no valid earlier date
    }
    
    // Go back one position to get the closest earlier date
    --it;
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    bool firstLine = true;
    
    while (std::getline(file, line)) {
        // Skip header line
        if (firstLine) {
            firstLine = false;
            continue;
        }
        
        if (line.empty()) {
            continue;
        }
        
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 1);
        
        trim(date);
        trim(valueStr);
        
        // Validate date
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        // Parse value
        bool success;
        float value = stringToFloat(valueStr, success);
        
        if (!success) {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }
        
        // Validate value
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        // Get exchange rate
        float rate = getExchangeRate(date);
        
        if (rate < 0) {
            std::cerr << "Error: no data available for date => " << date << std::endl;
            continue;
        }
        
        // Calculate result
        float result = value * rate;
        
        // Display result
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    
    file.close();
}

