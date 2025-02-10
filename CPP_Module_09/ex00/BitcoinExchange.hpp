#pragma once

#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& database);
    ~BitcoinExchange();
    void loadDatabase(const std::string& database);
    void processInput(const std::string& inputFile);
    bool isDatabaseLoaded() const;

private:
    std::map<std::string, float> exchangeRates;
    bool databaseLoaded;
    bool isValidDate(const std::string& date);
    bool isValidValue(float value);
    std::string findClosestDate(const std::string& date);
};
