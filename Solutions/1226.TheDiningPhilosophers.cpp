class DiningPhilosophers {
public:
	DiningPhilosophers() :
		m_order(0) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	}

	void wantsToEat(int philosopher,
					function<void()> pickLeftFork,
					function<void()> pickRightFork,
					function<void()> eat,
					function<void()> putLeftFork,
					function<void()> putRightFork) {
		orderWait(philosopher);
		//
		pickLeftFork();
		pickRightFork();
		eat();
		putLeftFork();
		putRightFork();
		//
		orderFinish(philosopher);
	}

private:
	void orderWait(const int order) {
		int current;
		while ((current = m_order.load()) != order)
			m_order.wait(current);
	}

	void orderFinish(const int order) {
		m_order = order + 1;
		if (m_order >= 5)
			m_order = 0;
		m_order.notify_all();
	}

private:
	std::atomic<int> m_order;
};