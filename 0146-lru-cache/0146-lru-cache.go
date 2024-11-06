type LRUCache struct {
    cache [][2]int
    capacity int
}


func Constructor(capacity int) LRUCache {
    return LRUCache{
        cache: make([][2]int, 0),
        capacity: capacity,
    }
}


func (this *LRUCache) Get(key int) int {
    // Retrieve the value, remove it from its current position, and add it to the end of the array.
    for i := range this.cache {
        if this.cache[i][0] == key {
            // get the array value in temp
            tmp := this.cache[i]
            // combine the array such that i index value is not present
            this.cache = append(this.cache[:i], this.cache[i + 1:]...)
            // now add the value at the end to follow the LRU principle
            this.cache = append(this.cache, tmp)
            return tmp[1]
        }
    }
    // if the key is not present
    return -1
}


func (this *LRUCache) Put(key int, value int)  {
    // Check if thhe key present already update with the given value
    for i := range this.cache {
        if this.cache[i][0] == key {
            // get the array value in temp
            tmp := this.cache[i]
            this.cache = append(this.cache[:i], this.cache[i+1:]...)
            tmp[1] = value
            // now add the value at the end to follow the LRU principle
            this.cache = append(this.cache, tmp)
            return
        }
    }
    
    // if the len is equal to cap then remove the first array
    if len(this.cache) == this.capacity {
        this.cache = this.cache[1:]
    }
    
    this.cache = append(this.cache, [2]int{key, value})
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */