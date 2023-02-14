#include <iostream>

#include <vector>

#include <string>


using namespace std;

bool isLeapYear(int year){

    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

}

int dayOfYear(string date) {

    int year = stoi(date.substr(0,4));

    int month = stoi(date.substr(5,2));

    int day = stoi(date.substr(8,2));

    vector<int> daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31};

    int dayCount = 0;

    for(int i = 1; i < month; i++){

        dayCount += daysInMonth[i-1];

        if(i == 2 && isLeapYear(year)){

            dayCount += 1;

        }

    }

    dayCount += day;

    return dayCount;

}

int main() {

    string date;

    cout << "Iveskite data siuo formatu YYYY-MM-DD: ";

    cin >> date;

    int day = dayOfYear(date);

    cout << "Diena metuose: " << day << endl;

    return 0;

}
