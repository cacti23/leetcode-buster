/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        return "Hello World";
    }
};

// does not take single commas input string

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */