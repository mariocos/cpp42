#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {
private:
    std::map<std::string, float> _database;

    // Helper methods
    bool isValidDate(const std::string& date) const;
    bool isLeapYear(int year) const;
    float stringToFloat(const std::string& str, bool& success) const;
    void trim(std::string& str) const;

public:
    // Orthodox Canonical Form
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    // Main functionality
    bool loadDatabase(const std::string& filename);
    void processInputFile(const std::string& filename);
    float getExchangeRate(const std::string& date) const;
};

#endif

