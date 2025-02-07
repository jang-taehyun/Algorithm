#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int calculate_charge(int hour, int minute, int duration) {
    int total_cost = 0;
    
    while (duration > 0) {
        if (hour >= 7 && hour < 19) {
            total_cost += 10;
        } else {
            total_cost += 5;
        }
        
        // 시간 증가
        minute++;
        if (minute == 60) {
            minute = 0;
            hour = (hour + 1) % 24; // 24시간 형식 유지
        }
        duration--;
    }
    
    return total_cost;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    
    int total_cost = 0;
    
    for (int i = 0; i < N; i++) {
        string input;
        getline(cin, input);
        
        stringstream ss(input);
        string time_str;
        int duration;
        
        ss >> time_str >> duration;
        
        int hour = stoi(time_str.substr(0, 2));
        int minute = stoi(time_str.substr(3, 2));
        
        total_cost += calculate_charge(hour, minute, duration);
    }
    
    cout << total_cost << endl;
    
    return 0;
}
