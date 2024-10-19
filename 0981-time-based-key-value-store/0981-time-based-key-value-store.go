type ValStamp struct {
    val string
    time int
}

type TimeMap struct {
    store map[string][]ValStamp
}


func Constructor() TimeMap {
    return TimeMap{store: make(map[string][]ValStamp)}
}


func (tm *TimeMap) Set(key string, value string, timestamp int)  {
    if _, ok := tm.store[key]; !ok {
        tm.store[key] = make([]ValStamp, 0)
    }
    
    tm.store[key] = append(tm.store[key], ValStamp{value, timestamp})
}


func (tm *TimeMap) Get(key string, timestamp int) string {
    var res string
    var values []ValStamp
    if _, ok := tm.store[key]; ok {
        values = tm.store[key]
    }
    
    l, r := 0, len(values) - 1
    
    for l <= r {
        m := (l + r) / 2
        
        t := values[m].time
        v := values[m].val
        
        if t <= timestamp {
            res = v
            l = m + 1
        } else {
            r = m - 1
        }
    }
    
    return res
}


/**
 * Your TimeMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Set(key,value,timestamp);
 * param_2 := obj.Get(key,timestamp);
 */