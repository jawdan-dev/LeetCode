class FizzBuzz {
public:
	FizzBuzz(int n) :
		m_n(n), m_order(1) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	}

	void number(function<void(int)> printNumber) {
		for (int i = 1; i <= m_n; i++) {
			if (i % 3 == 0 || i % 5 == 0)
				continue;
			orderWait(i);
			printNumber(i);
			orderFinish(i);
		}
	}

	void fizz(function<void()> printFizz) {
		for (int i = 3; i <= m_n; i += 3) {
			if (i % 5 == 0)
				continue;
			orderWait(i);
			printFizz();
			orderFinish(i);
		}
	}

	void buzz(function<void()> printBuzz) {
		for (int i = 5; i <= m_n; i += 5) {
			if (i % 3 == 0)
				continue;
			orderWait(i);
			printBuzz();
			orderFinish(i);
		}
	}

	void fizzbuzz(function<void()> printFizzBuzz) {
		for (int i = 15; i <= m_n; i += 15) {
			orderWait(i);
			printFizzBuzz();
			orderFinish(i);
		}
	}

private:
	void orderWait(const int order) {
		int current;
		while ((current = m_order.load()) != order)
			m_order.wait(current);
	}

	void orderFinish(const int order) {
		m_order = order + 1;
		m_order.notify_all();
	}

private:
	int m_n;
	std::atomic<int> m_order;
};