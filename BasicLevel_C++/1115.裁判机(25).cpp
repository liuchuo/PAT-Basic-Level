#include <cstdio>
#include <unordered_map>
#include <set>
#include <vector>

int matrix[15][1005] = {0};
int N, M;
std::unordered_map<int, std::set<int>> number2diff;
bool player[15] = {false};

int main(int argc, char const *argv[]) {
	int init1, init2;
	std::scanf("%d %d", &init1, &init2);
	std::set<int> st1, st2;
	if (init1 > init2)
		st1.insert(init1 - init2);
	else
		st2.insert(init2 - init1);
	number2diff.insert({init1, st1});
	number2diff.insert({init2, st2});
	std::scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			std::scanf("%d", &matrix[i][j]);
	for (int j = 1; j <= M; j++) {
		for (int i = 1; i <= N; i++) {
			int tmp = matrix[i][j];
			if (player[i] == true) continue;
			if (number2diff.find(tmp) != number2diff.end()) {
				std::printf("Round #%d: %d is out.\n", j, i);
				player[i] = true;
			} else {
				bool flag = false;
				for (auto &p : number2diff) {
					auto it = p.second.lower_bound(tmp);
					if (it != p.second.end() && *it == tmp) {
						flag = true;
						break;
					}
				}
				if (!flag) {
					std::printf("Round #%d: %d is out.\n", j, i);
					player[i] = true;
				} else {
					std::set<int> st;
					for (auto &p : number2diff) {
						if (p.first < tmp)
							st.insert(tmp - p.first);
					}
					number2diff.insert({tmp, st});
					for (auto &p : number2diff) {
						if (p.first > tmp) {
							p.second.insert(p.first - tmp);
						}
					}
				}
			}
		}
	}
	std::vector<int> winner;
	for (int i = 1; i <= N; i++) {
		if (player[i] == false) winner.push_back(i);
	}
	if (winner.size() == 0)
		std::printf("No winner.\n");
	else {
		std::printf("Winner(s):");
		for (int &i : winner)
			std::printf(" %d", i);
	}
	return 0;
}

