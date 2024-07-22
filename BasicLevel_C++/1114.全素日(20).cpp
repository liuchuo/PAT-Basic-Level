#include <iostream>
#include <string>
#include <cmath>

int isPrime(int n) {
	if (n < 2)
		return 0;
	for (int i = 2; i <= std::sqrt(n); i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main() {
	std::string date;
	std::cin >> date;
	int length = date.length();
	std::string s;
	int flag = 0;
	for (int i = 0; i < length; i++) {
		s = date.substr(i, length - i);
		int number = std::stoi(s);
		if (isPrime(number) == 1) {
			std::cout << s << " " << "Yes" << std::endl;
		} else {
			flag = 1;
			std::cout << s << " " << "No" << std::endl;
		}
	}
	if (flag == 0)
		std::cout << "All Prime!";
	
	return 0;
}

