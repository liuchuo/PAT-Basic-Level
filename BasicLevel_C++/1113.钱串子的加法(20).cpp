#include <iostream>
#include <string>
#include <algorithm>

int main() {
	std::string a, b;
	std::cin >> a >> b;
	char m[31] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e',
		'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'
	};
	
	int len1 = a.length();
	int len2 = b.length();
	std::string s;
	if (len1 > len2) {
		for (int i = 0; i < len1 - len2; i++)
			s += "0";
		b = s + b;
	} else {
		for (int i = 0; i < len2 - len1; i++)
			s += "0";
		a = s + a;
	}
	int len = a.length();
	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());
	int k = 0;
	std::string result = "";
	int carry = 0;
	while (k < len) {
		int x1, x2;
		for (int i = 0; i < 31; i++) {
			if (m[i] == a[k])
				x1 = i;
			if (m[i] == b[k])
				x2 = i;
		}
		int sum = x1 + x2 + carry;
		if (sum >= 30) {
			carry = 1;
			sum = sum - 30;
		} else {
			carry = 0;
		}
		result += m[sum];
		k++;
	}
	std::reverse(result.begin(), result.end());
	int index = 0;
	for (int i = 0; i < static_cast<int>(result.length()); i++) {
		if (result[i] != '0') {
			index = i;
			break;
		}
	}
	for (int i = index; i < static_cast<int>(result.length()); i++)
		std::cout << result[i];
	
	return 0;
}

