#include<bits/stdc++.h>
#include <pthread.h>
using namespace std;

class Solution {
	unordered_map<int,int> memo;
	const int INFINITE;

public:
	Solution(): INFINITE{numeric_limits<int>::max()} {}

    int coinChange(vector<int>& coins, int amount) {
		if(amount == 0) return 0;
		if(amount < 0) return -1;

		auto it = memo.find(amount);
		if(it == memo.end()){
			int min_coins = INFINITE;

			for(auto coin: coins){
				int ncoins = coinChange(coins, amount-coin);
				if(ncoins != -1)
					min_coins = min(min_coins, ncoins+1);
			}
			
			if(min_coins == INFINITE)
				min_coins = -1;
			it = memo.insert({amount, min_coins}).first;
		}
		return it->second;
    }
};


class Solution {

private:
	vector<int> possible_num_of_coins;
	void coinChange(vector<int> coins, int amount, int res){
		if(amount == 0) possible_num_of_coins.push_back(res);
		for(int i = 0; i < coins.size(); i++){
			int coin = coins[i];
			if(coin <= amount){
				vector<int> remaining_coins;
				for(int j = 0; j < coins.size(); j++) if(j!=i) remaining_coins.push_back(coins[j]);
				coinChange(move(remaining_coins), amount % coin, res + amount / coin);
			}
		}
	}

public:
    int coinChange(vector<int>& coins, int amount) {
		coinChange(coins, amount, 0);
		if(possible_num_of_coins.empty()) return -1;
		else return *std::min_element(possible_num_of_coins.begin(), possible_num_of_coins.end());
	}
};

class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
		sort(coins.begin(), coins.end(), std::greater<int>());
		int res = 0;
		for(auto coin : coins){
			res += amount / coin;
			amount -= (amount > coin ? amount % coin : 0);
		}
		return (amount == 0 ? res : -1);
    }
};

int main(){
}

