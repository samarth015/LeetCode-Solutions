#include<bits/stdc++.h>
using namespace std;

// seive
class Solution {
public:
    int countPrimes(int n) {
		if(n==0) return 0;
		vector<bool> isprime(n, true); 
		isprime[0] = isprime[1] = false;
		int p = 2, rt = sqrt(n);
		while(p <= rt){
			if(isprime[p])
				for(int i = p*p; i < n; i += p) isprime[i] = false;
			p++;
		}
		return std::count(isprime.begin(), isprime.end(), 1);
    }
};

// My orig sol
class Solution3 {
	private:
		set<int> primes;
		int counter;
	public:
		Solution3(): primes{ 2 }, counter{ 2 } {}
		int countPrimes(int n) {
			while(counter < n){
				bool is_prime {true};
				for(auto p : primes) {
					if(counter % p == 0){
						is_prime = false;
						break;
					}
				}
				if(is_prime){ 
					primes.insert(primes.end(), counter);
					cout << counter << endl;
				}
				counter++;
			}
			int cnt = 0;
			auto p {primes.begin()};
			while(p != primes.end() and *p < n) cnt++, p++;
			return cnt;
		}
};

// Bad Solution
class Solution2 {
	vector<int> count;
	private:
	bool isprime(int n){
		for(int i = 2; i < n; i++) if(n % i == 0) return false;
		return true;
	}
	public:
	Solution2(): count{0, 0} {} 
	int countPrimes(int n){
		if(n == 0) return 0;
		for(int i = count.size(); i <= n; i++){
			count.push_back( count.back() + isprime(i) );
			cout << count.back() << endl;
		}
		return count[n-1];
	}
};

int main(){
	Solution sol {} ;
	cout << sol.countPrimes( 499979);
}

