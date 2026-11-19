class MinStack {
private:
    stack<pair<int, int>> values; // value, minimum so far

public:
    MinStack() {}

    void push(int val) {
        int currentMin = values.empty()
            ? val
            : min(val, values.top().second);
        values.push({val, currentMin});
    }

    void pop() {
        values.pop();
    }

    int top() {
        return values.top().first;
    }

    int getMin() {
        return values.top().second;
    }
};
