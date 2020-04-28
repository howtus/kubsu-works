let $button = document.getElementById('button');
let $input = document.getElementById('input');
let $output = document.getElementById('output');

$button.addEventListener('click', function () {
    
    let value = ($input.value || '').toLowerCase();
    
    if (value) {
        value = parseString(value);
        console.log("value: ", value);
        
        let rpn = getReversePolishNotation(value);
        console.log(rpn);
        output.innerHTML = "Запись в ОПН: " + rpn + "<br>";
        
        let result = calculate(rpn);
        console.log(result);
        output.innerHTML += "Ответ: " + result;
    }
    
});

function calculate(rpn) {
    
    let v1, v2;
    let value = null;
    let values = [];
    for (let i = 0; i < rpn.length; i++) {
        value = rpn[i];
        switch (value) {
            case '+':
                v2 = values.pop();
                v1 = values.pop();
                values.push(v1 + v2);
                break;
            case '-':
                v2 = values.pop();
                v1 = values.pop();
                values.push(v1 - v2);
                break;
            case '*':
                v2 = values.pop();
                v1 = values.pop();
                values.push(v1 * v2);
                break;
            case '/':
                v2 = values.pop();
                v1 = values.pop();
                values.push(v1 / v2);
                break;
            default:
                values.push(parseFloat(value));
        }
    }
    return values[0];
}

function getReversePolishNotation(p) {
    
    let operator = null;
    let operators = [];
    let output = [];
    let value = null;
    
    for (let i = 0; i < p.length; i++) {
        value = p[i];
        switch (value) {
            case '+':
            case '-':
                if (operators.length) {
                    operator = operators.pop();
                    while (operator && operator !== '(') {
                        output.push(operator);
                        operator = operators.pop();
                    }
                    if (operator) {
                        operators.push(operator);
                    }
                }
                operators.push(value);
                break;
            case '*':
            case '/':
                if (operators.length) {
                    operator = operators.pop();
                    while (operator && operator !== '(' && operator !== '+' && operator !== '-') {
                        output.push(operator);
                        operator = operators.pop();
                    }
                    if (operator) {
                        operators.push(operator);
                    }
                }
                operators.push(value);
                break;
            case '(':
                operators.push(value);
                break;
            case ')':
                operator = operators.pop();
                while (operator !== '(') {
                    if (!operator) {
                        throw "Brackets are inconsistent";
                    }
                    output.push(operator);
                    operator = operators.pop();
                }
                break;
            default:
                output.push(value);
        }
    }
    while (operators.length) {
        output.push(operators.pop());
    }
    return output;
}

function parseString(str) {
    
    str = str.replace(/\s+/g, '');
    
    let part = '';
    let parts = [];
    let prev = '';
    let value = '';
    
    for (let i = 0; i < str.length; i++) {
        
        value = str[i];
        
        switch (value) {
            case '+':
            case '*':
            case '/':
            case '(':
            case ')':
                if (part) {
                    parts.push(part);
                    part = '';
                }
                parts.push(value);
                break;
            case '-':
                if (part) {
                    parts.push(part);
                    part = '';
                    parts.push(value);
                } else {
                    if (i === 0 ||
                        prev === '+' ||
                        prev === '-' ||
                        prev === '*' ||
                        prev === '/' ||
                        prev === '('
                    ) {
                        part = value;
                    } else {
                        parts.push(value);
                    }
                }
                break;
            default:
                part = part + value;
        }
        
        prev = value;
    }
    
    if (part) {
        parts.push(part);
    }
    
    console.log("parts ");
    console.log(parts);
    return parts;
}
