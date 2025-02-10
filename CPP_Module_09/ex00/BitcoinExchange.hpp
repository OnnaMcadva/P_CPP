#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& database);
    ~BitcoinExchange();
    void loadDatabase(const std::string& database);
    void processInput(const std::string& inputFile);

private:
    std::map<std::string, float> exchangeRates;
    bool isValidDate(const std::string& date);
    bool isValidValue(float value);
    std::string findClosestDate(const std::string& date);
};

#endif