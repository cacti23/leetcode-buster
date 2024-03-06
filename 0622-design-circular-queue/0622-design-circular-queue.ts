class MyCircularQueue {
    
    private data: number[];
    private front: number;
    private back: number;
    private currentSize: number;
    private maxSize: number;
    
    constructor(k: number) {
        this.data = new Array<number>(k);
        this.front = -1;
        this.back = -1;
        this.maxSize = k;
        this.currentSize = 0;
    }

    enQueue(value: number): boolean {
        if(this.isFull()) return false;
        
        if(this.front === -1) this.front = 0;
        this.back = (this.back + 1) % this.maxSize;
        this.data[this.back] = value;
        this.currentSize++;
        
        return true;
    }

    deQueue(): boolean {
        if(this.isEmpty()) return false;
        
        this.front = (this.front + 1) % this.maxSize;
        this.currentSize--;
        
        return true;
    }

    Front(): number {
        if(this.isEmpty()) return -1;
        return this.data[this.front];
    }

    Rear(): number {
        if(this.isEmpty()) return -1;
        return this.data[this.back];
    }

    isEmpty(): boolean {
        return this.currentSize === 0;
    }

    isFull(): boolean {
        return this.currentSize === this.maxSize;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * var obj = new MyCircularQueue(k)
 * var param_1 = obj.enQueue(value)
 * var param_2 = obj.deQueue()
 * var param_3 = obj.Front()
 * var param_4 = obj.Rear()
 * var param_5 = obj.isEmpty()
 * var param_6 = obj.isFull()
 */