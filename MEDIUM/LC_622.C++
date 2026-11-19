class MyCircularQueue {
private:
    vector<int> data;
    int frontIndex;
    int size;
    int capacity;

public:
    MyCircularQueue(int k)
        : data(k), frontIndex(0), size(0), capacity(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;

        int index = (frontIndex + size) % capacity;
        data[index] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        frontIndex = (frontIndex + 1) % capacity;
        size--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : data[frontIndex];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return data[(frontIndex + size - 1) % capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
