class Foo {
public:
    Foo() : m_order(1) {}

    void first(function<void()> printFirst) {
        orderWait(1);
        printFirst();
        orderFinish(1);
    }

    void second(function<void()> printSecond) {
        orderWait(2);
        printSecond();
        orderFinish(2);
    }

    void third(function<void()> printThird) {
        orderWait(3);
        printThird();
        orderFinish(3);
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
    std::atomic<int> m_order;
};