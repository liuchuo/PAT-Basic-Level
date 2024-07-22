#include <iostream>

int main() {
	int N, T;
	std::cin >> N >> T;
	int left = 0, right = 0, maxNum = -1;
	int temp, flag = false;
	
	for (int i = 0; i < N; i++) {
		std::cin >> temp;
		maxNum = std::max(maxNum, temp);
		if (temp > T && flag) {
			right = i;
		} else if (temp > T && !flag) {
			left = right = i;
			flag = true;
		} else if (temp <= T && flag) { // 注意是 "<="!
			std::cout << "[" << left << ", " << right << "]" << std::endl;
			flag = false;
			maxNum = 1001;
		}
	}
	
	// 如果循环结束，还在计数区间内，也要输出
	if (flag) {
		std::cout << "[" << left << ", " << right << "]" << std::endl;
		return 0;
	}
	
	if (maxNum < 1001) {
		std::cout << maxNum;
	}
	
	return 0;
}

