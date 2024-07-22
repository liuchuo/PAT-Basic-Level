#include <iostream>
#include <string>
#include <algorithm>

int judge(const std::string& s) {
	int length = s.length();
	for (int i = 0; i < length; i++) {
		if (s[i] != s[length - i - 1])
			return 0;
	}
	return 1;
}

int main() {
	int n;
	std::cin >> n;
	
	std::string m[13] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	
	std::string mon;
	int day, month, year;
	
	for (int i = 0; i < n; i++) {
		std::cin >> mon;
		std::scanf("%d, %d", &day, &year);
		
		// Finding month
		for (int j = 0; j < 13; j++) {
			if (m[j] == mon) {
				month = j + 1;
				break;
			}
		}
		
		std::string date;
		if (100 <= year && year < 1000) {
			date += "0";
			date += std::to_string(year);
		} else if (10 <= year && year < 100) {
			date += "00";
			date += std::to_string(year);
		} else if (year < 10) {
			date += "000";
			date += std::to_string(year);
		} else {
			date += std::to_string(year);
		}
		
		if (month < 10) {
			date += "0";
		}
		date += std::to_string(month);
		
		if (day < 10) {
			date += "0";
		}
		date += std::to_string(day);
		
		if (judge(date) == 1) {
			std::cout << "Y " << date << std::endl;
		} else {
			std::cout << "N " << date << std::endl;
		}
	}
	
	return 0;
}

