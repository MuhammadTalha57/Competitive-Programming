#include <bits/stdc++.h>
using namespace std;

// Problem Link: https://cses.fi/problemset/task/1671


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<long long, long long>>> adjList(n + 1);
	long long u, v, c;
	for(int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		adjList[u].push_back({v, c});
	}
	vector<long long> res(n + 1, LONG_MAX);
	res[1] = 0;
	set<pair<long long, int>> q;
	q.insert({0, 1});
	while(q.size()) {
		auto [c, u] = *q.begin();
		q.erase(q.begin());
		for(auto [v, w]: adjList[u]) {
			if((c + w) < res[v]) {
				q.erase({res[v], v});
				res[v] = c + w;
				q.insert({res[v], v});
			}
		}	
	}
	for(int i = 1; i <= n; i++) {
		cout << res[i] << ' ';
	}
}
