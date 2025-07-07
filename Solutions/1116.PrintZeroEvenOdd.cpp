class ZeroEvenOdd {
public:
	ZeroEvenOdd(int n) :
		m_n(n * 2), m_order(0) {}

	// printNumber(x) outputs "x", where x is an integer.
	void zero(function<void(int)> printNumber) {
		for (int i = 0; i < m_n; i += 2) {
			orderWait(i);
			printNumber(0);
			orderFinish(i);
		}
	}

	void even(function<void(int)> printNumber) {
		for (int i = 3; i < m_n; i += 4) {
			orderWait(i);
			printNumber((i + 1) / 2);
			orderFinish(i);
		}
	}

	void odd(function<void(int)> printNumber) {
		for (int i = 1; i < m_n; i += 4) {
			orderWait(i);
			printNumber((i + 1) / 2);
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