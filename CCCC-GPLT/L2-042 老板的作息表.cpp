#include <iostream>
#include <set>
using namespace std;
set<pair<string, string> > record;
string work_start_time, work_end_time, last_start = "00:00:00";
int main() {
    cin >> work_start_time;
    while (cin >> work_start_time >> work_end_time >> work_end_time) record.insert({work_start_time, work_end_time});
    record.insert({"23:59:59", ""});
    for (auto ite : record) {
        if (last_start < ite.first) cout << last_start << " - " << ite.first << '\n';
        last_start = ite.second;
    }
    return 0;
}