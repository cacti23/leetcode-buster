/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
    this.max = capacity;
    this.cache = new Map();
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    let item = this.cache.get(key);
        
    if(item !== undefined) {
        this.cache.delete(key);
        this.cache.set(key, item);
    } else {
        return -1;
    }
    
    return item;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    
    // if the key is already present delete it
    if(this.cache.has(key)) this.cache.delete(key);
    // before inserting the new key check the size of the 
    else if(this.cache.size === this.max) {
    // here the least recently used key will be at top hence we are deleting the first key
        const firstKey = this.cache.keys().next().value;
            
        this.cache.delete(firstKey);
    }
    
    // insert the new key 
    this.cache.set(key, value);
    
    return null;
};
