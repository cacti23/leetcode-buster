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

function removeStars(s: string): string {
    const l = s.length;
    const st = new Stack<string>();
    
    for(let i = 0; i < l; i++) {
        let char = s[i];
        if(char === "*") {
            st.pop();
        } else {
            st.push(char);
        }
    }
    
    return st.print();
};

// tc -> O(n) + O(n)
// sc -> O(1)
