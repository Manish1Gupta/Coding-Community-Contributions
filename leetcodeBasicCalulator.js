//Leetcode ID : 224                                        Problem Name :  Basic Calculator
//Level : Hard

/**
 * @param {string} s
 * @return {number}
 */
const precedence = (op) => {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}
const isCharacterAnOperand = (character) => {
    return (character.charCodeAt() >= 'a'.charCodeAt() && character.charCodeAt() <= 'z'.charCodeAt())
        || (character.charCodeAt() >= 'A'.charCodeAt() && character.charCodeAt() <= 'Z'.charCodeAt());
}

Array.prototype.isEmpty = function() {
    return !this || !this.length;
}

Array.prototype.peek = function() {
    return this[this.length-1];
}

const infixToPostfix = (string) => {
    const resultArr = [];
    const stack = [];

    for(const character of string) {
        if(isCharacterAnOperand(character)) {
            resultArr.push(character);
        } else {
            /*
                1. it can be open parenthesis
                2. it can be closing parenthesis
                3. it can have an operator - check for precedence
            */
            if(character == '(') {
                stack.push(character);
            } else if(character == ')') {
                while(stack.peek() !== '(') {
                    resultArr.push(stack.pop());
                }
                stack.pop();
            } else {
                while(!stack.isEmpty() && precedence(stack.peek()) >= precedence(character)) {
                    resultArr.push(stack.pop());
                }
                stack.push(character);
            }
        }
    }
    while(!stack.isEmpty()) {
        resultArr.push(stack.pop());
    }
    return resultArr;
}
var calculate = function(s) {
  
};
