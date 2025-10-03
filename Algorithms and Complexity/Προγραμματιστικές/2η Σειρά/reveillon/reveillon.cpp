#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	int N, K;	// N -> guests	K -> table capacity
	std::cin >> N >> K;
	int h[N];
	for(int i = 0; i < N; i++) {
		std::cin >> h[i];
	}

	std::vector<int> dp(N + 1);

	// find optimal hapinness for the first i guests
	// for each guest we check all possible seating arrangements
	for(int i = 1; i <= N; i++) {
		int result = 0;
		for (int j = 1; j <= K && i >= j; j++) {
			result = std::max(result, h[i - j]);
			dp[i] = std::max(dp[i], dp[i - j] + j * result);
		}
	}

	std::cout << dp[N] << std::endl;

return 0;	
}
