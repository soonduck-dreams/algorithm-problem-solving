// 오랜만에 시작
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

int main(void) {
	fastio;
	//freopen("input.txt", "r", stdin);

	while (true) {
		vector<int> nums(3);

		for (int i = 0; i < 3; i++) {
			cin >> nums[i];
		}

		sort(nums.begin(), nums.end());

		if (nums[0] == 0 && nums[1] == 0 && nums[2] == 0)
			break;

		if (nums[0] * nums[0] + nums[1] * nums[1] == nums[2] * nums[2]) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}

	return 0;
}
