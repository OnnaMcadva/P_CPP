#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& database) {
    loadDatabase(database);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& database) {
    std::ifstream file(database.c_str());
    if (!file.is_open()) {
        std::cerr << "👿 Error: could not open database file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        std::string rateStr;
        if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
            float rate = std::atof(rateStr.c_str());
            exchangeRates[date] = rate;
        }
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) {

    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > 29 || (day == 29 && !isLeapYear)) {
            return false;
        }
    }

    return true;
}

bool BitcoinExchange::isValidValue(float value) {
    return value >= 0 && value <= 1000;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) {
    std::map<std::string, float>::iterator it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.begin()) {
        return it->first;
    }
    if (it == exchangeRates.end() || it->first != date) {
        --it;
    }
    return it->first;
}

void BitcoinExchange::processInput(const std::string& inputFile) {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cerr << "👿 Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // заголовок
    // std::cout << line << std::endl;
    while (std::getline(file, line)) {

        size_t separatorPos = line.find('|');
        if (separatorPos == std::string::npos) {
            std::cerr << "👿 Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, separatorPos);
        std::string valueStr = line.substr(separatorPos + 1);

        date.erase(0, date.find_first_not_of(' '));
        date.erase(date.find_last_not_of(' ') + 1);
        valueStr.erase(0, valueStr.find_first_not_of(' '));
        valueStr.erase(valueStr.find_last_not_of(' ') + 1);

        if (!isValidDate(date)) {
            std::cerr << "👿 Error: bad input => " << date << std::endl;
            continue;
        }

        float value = std::atof(valueStr.c_str());

        if (!isValidValue(value)) {
            if (value < 0) {
                std::cerr << "👿 Error: not a positive number." << std::endl;
            } else {
                std::cerr << "👿 Error: too large a number." << std::endl;
            }
            continue;
        }

        std::string closestDate = findClosestDate(date);
        float rate = exchangeRates[closestDate];
        std::cout << date << " \033[45m=>\033[0m " << value << " = " << value * rate << std::endl;
    }
    file.close();
}