// since struct are pass by value hence we need to use pointer
type Node struct {
    key, val int
    prev, next *Node
}

// left and right will be treat as two extreme ends 
// left next will always be least recently used
// right prev will always be most recently used
type LRUCache struct {
    cap         int
    cache       map[int]*Node
    left, right *Node
}


func Constructor(capacity int) LRUCache {
    lru := LRUCache{
        cache: make(map[int]*Node),
        cap: capacity,
        left: &Node{},
        right: &Node{},
    }
    
    lru.left.next = lru.right
    lru.right.prev = lru.left
    return lru
}

func (lru *LRUCache) remove(node *Node) {
    prev, next := node.prev, node.next
    prev.next = next
    next.prev = prev
}

func (lru *LRUCache) insert(node *Node) {
    prev, next := lru.right.prev, lru.right
    // insert between prev and next
    prev.next = node
    next.prev = node
    node.next = next
    node.prev = prev
}


func (lru *LRUCache) Get(key int) int {
    cache := lru.cache
    if node, ok := cache[key]; ok {
        // update location make it most recent
        lru.remove(node)
        lru.insert(node)
        return node.val
    } 
    
    return -1 
}


func (lru *LRUCache) Put(key int, val int)  {
    left := lru.left
    cache := lru.cache
    cap := lru.cap
    // check if the element already exists
    if node, ok := cache[key]; ok {
        // remove this element
        delete(cache, key)
        lru.remove(node)
    }
    
    node := &Node{key: key, val: val}
    cache[key] = node
    lru.insert(node)
    
    if len(cache) > cap {
        // remove least recently used
        delete(cache, left.next.key)
        lru.remove(left.next)

    }
} 


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */