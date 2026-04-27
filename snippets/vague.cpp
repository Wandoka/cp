const int VagueLimit = 26;
struct Vague {
	map<string, int> Map;
	Vague() {
	}
	Vague(int i) {
		if(i >= VagueLimit) {
			cout << "ADDED A VALUE THAT IS TO LARGE TO VAGUE" << endl;
			exit(1);
		}	
		string s;
		s.push_back('a' + i);
		Map[s] = 1;
	}
	Vague(map<string, int> &Map) : Map(Map) {};
	
	friend Vague operator +(Vague a, Vague b) {
		Vague c;
		//both
		for(auto p : a.Map) {
			if(b.Map.find(p.ff) != b.Map.end()) {
				c.Map[p.ff] = p.ss+b.Map[p.ff];
			}
		}
		//a
		for(auto p : a.Map) {
			if(b.Map.find(p.ff) == b.Map.end()) {
				c.Map[p.ff] = p.ss;
			}
		}
		for(auto p : b.Map) {
			if(a.Map.find(p.ff) == a.Map.end()) {
				c.Map[p.ff] = p.ss;
			}
		}
		return c;
	}
	friend Vague operator -(Vague a, Vague b) {
		Vague c;
		//both
		for(auto p : a.Map) {
			if(b.Map.find(p.ff) != b.Map.end()) {
				c.Map[p.ff] = p.ss-b.Map[p.ff];
			}
		}
		//a
		for(auto p : a.Map) {
			if(b.Map.find(p.ff) == b.Map.end()) {
				c.Map[p.ff] = p.ss;
			}
		}
		for(auto p : b.Map) {
			if(a.Map.find(p.ff) == a.Map.end()) {
				c.Map[p.ff] = -p.ss;
			}
		}
		return c;
	}
	friend Vague operator *(Vague a, Vague b) {
		Vague c;
		//both
		for(auto pa : a.Map) {
			for(auto pb : b.Map) {
				string sc = pa.ff + pb.ff;
				sort(all(sc));
				c.Map[sc] += pa.ss*pb.ss;
			}
		}
		return c;
	}
	Vague& operator+=(const Vague& a) {
		*this = *this + a;
		return *this;
	} 
	Vague& operator-=(const Vague& a) {
		*this = *this - a;
		return *this;
	} 
	Vague& operator*=(const Vague& a) {
		*this = *this * a;
		return *this;
	} 
};
std::ostream& operator <<(std::ostream& stream, Vague& v) {
	stream << "[";
	int first = 1;
	for(auto p : v.Map) {
		if(first == 0) {
			stream << " + ";
		}
		else {
			first = 0;
		}
		stream << p.ss << p.ff;
	}
	stream << "]";
	return stream;
}
vector<Vague> Fill(int n) {
	vector<Vague> A(n);
	fori(n) {
		A[i] = i;
	}
	return A;
}
