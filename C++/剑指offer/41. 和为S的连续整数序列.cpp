#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > allRes;
        int plow = 1, phigh = 2;

        while (phigh > plow) {
            int cur = (phigh + plow) * (phigh - plow + 1) / 2;
            if (cur < sum) {
                phigh++;
            } else if (cur > sum) {
                plow++;
            } else {
                vector<int> res;
                for (int i = plow; i <= phigh; i++) {
                    res.push_back(i);
                }
                allRes.push_back(res);
                plow++;
            }
        }
        return allRes;
    }
};

int main() {
    Solution solution;
    int s = 15;
    vector<vector<int> > res = solution.FindContinuousSequence(s);
    for (auto &seq : res) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
