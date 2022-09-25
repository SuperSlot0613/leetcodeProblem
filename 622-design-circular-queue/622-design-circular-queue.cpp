class MyCircularQueue {
public:
    int *arr ;
    int front, rear;
    int n;
    int maxsize;
    MyCircularQueue(int k) {
        arr = new int[k];
        maxsize = k;
        n = 0;
        front = 0;
        rear = maxsize - 1;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1)% maxsize;
        arr[rear] = value;
        n++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % maxsize;
        n--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return n == 0;
    }
    
    bool isFull() {
        return n == maxsize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */