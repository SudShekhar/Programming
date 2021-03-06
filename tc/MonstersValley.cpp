// BEGIN CUT HERE
// PROBLEM STATEMENT
// Manao is traversing a valley inhabited by monsters. During his journey, he will encounter several monsters one by one. The scariness of each monster is a positive integer. Some monsters may be scarier than others. The i-th (0-based index) monster Manao will meet has scariness equal to dread[i].

// Manao is not going to fight the monsters. Instead, he will bribe some of them and make them join him. To bribe the i-th monster, Manao needs price[i] gold coins. The monsters are not too greedy, therefore each value in price will be either 1 or 2.

// At the beginning, Manao travels alone. Each time he meets a monster, he first has the option to bribe it, and then the monster may decide to attack him. A monster will attack Manao if and only if he did not bribe it and its scariness is strictly greater than the total scariness of all monsters in Manao's party. In other words, whenever Manao encounters a monster that would attack him, he has to bribe it. If he encounters a monster that would not attack him, he may either bribe it, or simply walk past the monster.



// Consider this example: Manao is traversing the valley inhabited by the Dragon, the Hydra and the Killer Rabbit. When he encounters the Dragon, he has no choice but to bribe him, spending 1 gold coin (in each test case, Manao has to bribe the first monster he meets, because when he travels alone, the total scariness of monsters in his party is zero). When they come by the Hydra, Manao can either pass or bribe her. In the end, he needs to get past the Killer Rabbit. If Manao bribed the Hydra, the total scariness of his party exceeds the Rabbit's, so they will pass. Otherwise, the Rabbit has to be bribed for two gold coins. Therefore, the optimal choice is to bribe the Hydra and then to walk past the Killer Rabbit. The total cost of getting through the valley this way is 2 gold coins.

// You are given the vector<long long> dread and the vector <int> price. Compute the minimum price Manao will pay to safely pass the valley.

// DEFINITION
// Class:MonstersValley
// Method:minimumPrice
// Parameters:vector<long long>, vector <int>
// Returns:int
// Method signature:int minimumPrice(vector<long long> dread, vector <int> price)


// CONSTRAINTS
// -dread will contain between 1 and 50 elements, inclusive.
// -Each element of dread will be between 1 and 1,000,000,000,000 (10^12), inclusive.
// -price will contain the same number of elements as dread.
// -Each element of price will be either 1 or 2.


// EXAMPLES

// 0)
// {8, 5, 10}
// {1, 1, 2}

// Returns: 2

// The example from the problem statement.

// 1)
// {1, 2, 4, 1000000000}
// {1, 1, 1, 2}

// Returns: 5

// Manao has to bribe all monsters in the valley.

// 2)
// {200, 107, 105, 206, 307, 400}
// {1, 2, 1, 1, 1, 2}

// Returns: 2

// Manao can bribe monsters 0 and 3.

// 3)
// {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333}
// {2, 2, 1, 1, 1, 1, 2, 1, 2, 1}

// Returns: 5

// Bribing monsters 0, 1 and 5 is sufficient to pass safely.

// END CUT HERE

#line 67 "MonstersValley.cpp"

// Standard includes
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>

//Data Structures
#include<algorithm>
#include<vector>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)


class MonstersValley {
	
public:
int minimumPrice(vector<long long> dread, vector <int> price) {	
	long long int dp[100][201];
	memset(dp,0,sizeof dp);	
	bool fnd;
	for(int p=0;p<=100;p++){
		fnd=true;
		rep(i,dread.size()){
			if(fnd==false)
			{
				dp[i][p]=(1<<31);
				continue;
			}
			if(p==0)
				dp[i][p]=0;
			else{
				dp[i][p] = dp[i-1][p];
				if(p >= price[i])
					dp[i][p] = max(dp[i][p],dp[i-1][p-price[i]]+dread[i]);
			}
			if(dp[i][p] < dread[i])
				{
					dp[i][p] = (1<<31);
					fnd=false;
				}
		}
		if(fnd)
			return p;
	}
	
	}
};
