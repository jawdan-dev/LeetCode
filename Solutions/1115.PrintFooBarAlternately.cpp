class FooBar {
private:
	int m_n;
	std::atomic<int> m_order;

public:
	FooBar(int n) :
		m_n(n), m_order(0) {}

	void foo(function<void()> printFoo) {
		for (int i = 0; i < m_n; i++) {
			orderWait(0);
			printFoo();
			orderFinish(0);
		}
	}

	void bar(function<void()> printBar) {
		for (int i = 0; i < m_n; i++) {
			orderWait(1);
			printBar();
			orderFinish(1);
		}
	}

private:
	void orderWait(const int order) {
		int current;
		while ((current = m_order.load()) != order)
			m_order.wait(current);
	}

	void orderFinish(const int order) {
		m_order = order == 0 ? 1 : 0;
		m_order.notify_all();
	}
};