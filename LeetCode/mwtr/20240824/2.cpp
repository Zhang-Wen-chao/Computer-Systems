#include <iostream>
#include <vector>
#include <cstdlib>  // for std::abs

using namespace std;

long min_cost_to_move_bottles(long a, long b, long c, long d, const vector<pair<long, long>>& bottles) {
    long total_cost = 0;
    long current_x = a, current_y = b;

    for (const auto& bottle : bottles) {
        long xi = bottle.first;
        long yi = bottle.second;
        
        // 移动到瓶子的位置
        long move_to_bottle = abs(current_x - xi) + abs(current_y - yi);
        // 再将瓶子移动到目标位置
        long move_to_target = abs(xi - c) + abs(yi - d);
        // 总代价
        total_cost += move_to_bottle + move_to_target;
        // 更新当前坐标为目标位置
        current_x = c;
        current_y = d;
    }

    return total_cost;
}

int main() {
    long a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int n;
    cin >> n;
    
    vector<pair<long, long>> bottles(n);
    for (int i = 0; i < n; ++i) {
        cin >> bottles[i].first >> bottles[i].second;
    }
    
    // 计算最小代价
    long result = min_cost_to_move_bottles(a, b, c, d, bottles);
    cout << result << endl;

    return 0;
}
