#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <vector>

std::chrono::system_clock::time_point get_date();
std::string get_printable_date(std::chrono::system_clock::time_point date);

#endif