struct DSU {
	int n = 1;
	vector<int> Rank;
	vector<int> Parent;
	DSU(int N) {
		n = N+1;
		Rank.assign(n, 0);
		Parent.assign(n, 0);
		
		fori(n) {
			Parent[i] = i;
		}
	}
	
	int getparent(int a) {
		if(a == Parent[a]) return a;
		Parent[a] = getparent(Parent[a]);
		return Parent[a];
	}
	
	bool check(int a, int b) {
		a = getparent(a);
		b = getparent(b);
		return a == b;
	}
	
	bool Unite(int a, int b) {
		a = getparent(a);
		b = getparent(b);
		if(a == b) return false;
		
		if(Rank[a] < Rank[b]) swap(a, b);
		if(Rank[a] == Rank[b]) ++Rank[a];
		Parent[b] = a;
		return true;
	}
};

