interface IStack<T> {
  push(item: T): void;
  pop(): T | undefined;
  peek(): T | undefined;
  size(): number;
  clear(): void;
  isEmpty(): boolean;
  print(): string;
}

class Stack<T> implements IStack<T> {
  private _stack: T[];

  constructor() {
    this._stack = [];
  }

  push(value: T) {
    this._stack.push(value);
  }

  pop() {
    if(this.isEmpty()) {
      return undefined;
    }
    return this._stack.pop();
  }

  peek() {
    if(this.isEmpty()) {
      return undefined;
    }
    return this._stack[this._stack.length - 1];
  }

  size() {
    return this._stack.length;
  }

  clear() {
    this._stack = [];
  }

  isEmpty() {
    return this._stack.length === 0;
  }

  print() {
    if(this.isEmpty()) return '';

    return this._stack.join('');
  }
}

function asteroidCollision(as: number[]): number[] {
    // using array as stack 
    const l = as.length;
    // will treat st as stack
    const st = [];
    // to track the elements inside the stack
    let j = 0;
    let temp = 0;
    
    for(let i = 0; i < l; i++) {
        temp = as[i];
        // if any positive value comes just insert it
        if(as[i] > 0) {
            st[j++] = temp;
        } else {
            // for negative values
            // if the positive values in stack is less then the negative value then we keep popping the positive element
            while(!(st.length === 0) && st[j - 1] > 0 && st[j - 1] < Math.abs(temp)) {
                st.pop();
                j--;
            }
            
            // now inside the stack can be empty or number at top can be negative or positive greater than the current element
            
            // if the number is positive but same as the current element
            if(!(st.length === 0) && st[j - 1] === Math.abs(temp)) {
                st.pop();
                j--;
                
            // we will insert the asteroid only when the stack is empty or the number is negative so there is not chance for collision
            } else if(st.length === 0 || st[j - 1] < 0) {
                st[j++] = temp;
            }
        }
    }
    
    return st;
    
};

// tc -> O(n + n)
// sc -> O(n)