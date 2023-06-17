/*
Design a struct “DayInfo” which contains two enumeration types as its member. The first is an enum “Day” for (Sunday, Monday, ...), and the second is an enum “Weather” for (Sunny, Rainy, ...).

Define a boolean function “bool canTravel( DayInfo )” . It will return true if the day is at weekend and the weather is good.

Call function canTravel() in main().
*/

#include <iostream>

// Enumeration for days of the week
enum class Day {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

// Enumeration for weather conditions
enum class Weather {
    Sunny,
    Rainy,
    Cloudy,
    Snowy
};

// Struct to hold day and weather information
struct DayInfo {
    Day day;
    Weather weather;
};

// Function to check if it's a good day for travel
bool canTravel(DayInfo dayInfo) {
    // Check if it's a weekend and the weather is good
    if (dayInfo.day == Day::Saturday || dayInfo.day == Day::Sunday) {
        if (dayInfo.weather == Weather::Sunny) {
            return true;
        }
    }
    return false;
}

int main() {
    // Create a DayInfo object
    DayInfo dayInfo;
    dayInfo.day = Day::Saturday;
    dayInfo.weather = Weather::Sunny;

    // Call the canTravel function and check the result
    if (canTravel(dayInfo)) {
        std::cout << "You can travel on this day!" << std::endl;
    } else {
        std::cout << "It's not a good day for travel." << std::endl;
    }

    return 0;
}
