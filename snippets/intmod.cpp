struct intMod {
	int32_t value = 0;
	static const ll modinf = 2e9*mod;
	intMod() {};
	
	intMod(const int32_t& a) : value(a) {
		while(value < 0) value += mod;
		while(value >= mod) value -= mod;
	}
	intMod(const ll& a) {
		if(-mod < a && a < mod) {
			value = a;
			while(value < 0) value += mod;
			while(value >= mod) value -= mod;
		}
		else {
			value = (modinf + a) % mod;
		}
	}
	
	intMod& operator+=(const int32_t& other) {
		this->value += other;
		while(this->value < 0) this->value += mod;
		while(this->value >= mod) this->value -= mod;
		return *this;
	}
	intMod& operator-=(const int32_t& other) {
		*this+=-other;
		return *this;
	}
	intMod& operator+=(const ll& other) {
		if(-mod < other && other < mod) *this+=(int32_t)other;
		else this->value = (modinf+ this->value + other) % mod;
		return *this;
	}
	intMod& operator-=(const ll& other) {
		*this+=-other;
		return *this;
	}
	intMod& operator++() {
		*this+=1;
		return *this;
	}
	intMod operator++(int32_t) {
		intMod ans = *this;
		*this+=1;
		return ans;
	}
	intMod& operator--() {
		*this-=1;
		return *this;
	}
	intMod operator--(int32_t) {
		intMod ans = *this;
		*this-=1;
		return ans;
	}
	
	intMod& operator*=(const int32_t& other) {
		while(this->value < 0) this->value += mod;
		while(this->value >= mod) this->value -= mod;
		this->value = (ll)this->value*other%mod;
		return *this;
	}
	intMod& operator*=(const ll& other) {
		if(-mod < other && other < mod) *this*=(int32_t)other;
		else this->value = (this->value*(other%mod))%mod;
		return *this;
	}
	
	
	intMod& operator+=(const intMod& other) {
		*this += other.value;
		return *this;
	}
	intMod& operator-=(const intMod& other) {
		*this += -other.value;
		return *this;
	}
	intMod& operator*=(const intMod& other) {
		*this *= other.value;
		return *this;
	}
	
	intMod operator+(intMod other) {
		other += *this;
		return other;
	}
	intMod operator-(intMod other) {
		other.value = (value - other.value);
		if(other.value < 0) other.value+=mod;
		return other;
	}
	intMod operator*(intMod other) {
		other *= *this;
		return other;
	}
	
	bool operator==(const intMod& other) {
		return this->value==other.value;
	}
	bool operator!=(const intMod& other) {
		return this->value!=other.value;
	}
	
	
	friend ostream& operator<<(ostream& os, const intMod& other) {
		os << other.value;
		return os;
	}
	friend bool operator<(const intMod& a, const intMod& b) { return a.value < b.value; }
	friend bool operator<=(const intMod& a, const intMod& b) { return a.value <= b.value; }
	friend bool operator>(const intMod& a, const intMod& b) { return a.value > b.value; }
	friend bool operator>=(const intMod& a, const intMod& b) { return a.value >= b.value; }
	
	friend intMod PowIntMod(intMod a, int b) {
		if(b == 0) return 1;
		intMod c = PowIntMod(a, b/2);
		c*=c;
		if(b % 2 == 1) c *= a;
		return c;
	}
	friend intMod inverse(const intMod& a) {
		return PowIntMod(a, mod-2);
	}
	intMod& operator/=(const int32_t& other) {
		*this *= inverse(intMod(other));
		return *this;
	}
	intMod& operator/=(const ll& other) {
		*this *= inverse(intMod(other));
		return *this;
	}
	intMod& operator/=(const intMod& other) {
		*this *= inverse(other);
		return *this;
	}
	intMod operator/(const intMod& other) {
		intMod ans = *this;
		ans /= other;
		return ans;
	}
};
