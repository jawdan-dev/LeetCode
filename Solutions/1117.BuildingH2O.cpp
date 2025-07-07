class H2O {
public:
    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
        const int index = m_hydrogenCount.fetch_add(1);
        const int waitIndex = ((index / 2) * 3) + (index % 2);
        orderWait(waitIndex);
        releaseHydrogen();
        orderFinish(waitIndex);
    }

    void oxygen(function<void()> releaseOxygen) {
        const int index = m_oxygenCount.fetch_add(1);
        const int waitIndex = (index * 3) + 2;
        orderWait(waitIndex);
        releaseOxygen();
        orderFinish(waitIndex);
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
	std::atomic<int> m_oxygenCount, m_hydrogenCount;
	std::atomic<int> m_order;
};