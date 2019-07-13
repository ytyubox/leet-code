#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int calculate(string s);
void printArr(vector<char> x);
void printCArr(vector<char> x);

/**
 * Implement the eval(), input a string math operaition expression, calculate it.
 * 
 * - Using 2 vector to store data, operands and others(oprators, '(' & ')' )
 * - When meet the ')', pop out 2 operands and one operator
 *      - Notice that the direction is REVERSE order when poping out the operands.
 *      - Handle the '-' (minus) operation additionally
 *          - EX: 35 - 25 - 55, the following is the order to be poped 
 *              -> 25 - 55 => -30 (But actually the value should be -25-55 = -80)
 *              -> [ Modify the summation value if meet the second '-' (minus) ]
 *              -> [x]: 35 - (-30)
 *                 [o]: 35 + modified value, modified value = -30 - 2*lastRightValue = -30 - 2*(25) = -80
 *                      So it will get the correct value 35 + (-80)
 *      - Poping out the operands if there still exists some operator
 *          - Compared to the stack between "()", this is a simple forward order
 *          - pop 2 elements and operate both of them, insert the result.
 * 
 * OS: So tired to solve this problem and debug it ...
 */

int main() {
    string expr = "(9-(10-(10-0-(3+(8+(0+(8-(10-8-(7-(2+(5+(6+(10+(3+(8+(3-(9+(1+(10+(1-(1+(6-2+0+(10-(9-(3-(3-9-(1-(7+(4-(2+(2-(10+(3+(7-(1-(4+(1+(1-(10-(5-(9+(9-4-(5-(1+8-(2-(1+(1-10-(4-(1+(4-(7)-(3-(8)+(5+5-(5-(9-(8+(8-4-1+(0-(1+(1+(10-(7+(2-(5-(4-(6+(2+(1-(2-(9+8+(2+(9-(9-(7+(10+1+(5)))-(2-(8+3+(5-(7-(3+(9)+(10+(0+(8-(1-(9)-(0+10-(3+(9-(0-(5-(7-(4-4+1+(7)-(10+(5+(9-(3+(5+(6-(0-(7-(1-(4+(6+(4-2-(4+(9-(6+9-8+1+(5+(7-9+3)+(10-(10+(2+(0-(5-(2+(10-(4-5-(7-(4-(7+(4)+6+10+(2-(7+(2))+(1)+(5-(7)-(10-(5+(7-(6-(2+(1-4)+(10-(5)+(4+(10+(4+(0+(10+(8-(8+(6+5-(1-(6-(1-(2+(4+(9-(3+(1+(10+(4)+(0+(3-(2-(9-(2-(3-(4-(2+(7-(6-(5+(7+(5+(5-(4+(0-(7+(2-(7+(9)-(6-(10)+(7+(2-(9-(9)+(4+(1-(8+(2-0-(2+(2+10)-(7-9-(9+(8-(5-8-(5)+(6+(10-(3-(2-(2+(7-2+(9+(3+(9+(2-(8+(5-(4+(4-(1-(9+(0+(6-(4-(3+(5-(2-(4-(6+(0+(4+3)-(8-(6+(9+(1+(2)-(8-(1+1+(5+(4-(3-(1-(7-4+(6+(9+(1+(4)+(6+(4+(2+(7-(1+(4-(8+(6+(8-(9-(2)-3-(0-(0)+(5+(7-(8)+(8-(2+(1)+1+(3+(6-(10-(2-4-(2-(2)+(8)+(3-(1-(1)+(6+(1+(9+(9+(5)-(4+(9+(10)+(0-(3+(3+0)+(6)-(6+(6)+(4-(8-1-5-(6)-(0))-(3)+(3-(3-(8-(10-(0-(4+(7)+(6-4))+1-(2-(1-(0-(0+(1-(0)-0+(5+(10-(2-(9-(9-10)+(3+(5-(6-(6-9-(5+5))+(7+(0)-(2-(7+2+(7-(2+(7+(4-(10+(4+(10-(3-(0-2+(9+(4-4-(3-(2)+(8+(5)+(1+1-(7+(3+(10+5-(0+(10-(9+(8-(0-(0+(8-(1+(0)+(6+(5+(5+(9)))+(4-(1-(3+(7+(9+(8-(1-8-(8+(0+(1+(1-(1)+(7+(6-(7-(8+(10)+1+(0-(10)+(8+(7+(10+(6+(10+(6)-(2+(2+(10-(8)-(5)))+(9-(1)+(4)+(5)-(6-(9)-(1+(6-(9+(10)+2-(4+(9-(4+1)-(0-(9)-(3)+(0)+(10)))+9)+(6+4+(6))+(5-(9))-(9-(2-(6+(7))-(6-(3+(5+(5-(0)-(5+(6-(5+(9-(2+(9+(1+(0+2+(7)-(3-(5+(2)+(4)+(6+(7-(3-(4)+(10+(4))+(3))-(3-(2)-(2+(2+(10+(3)+(3+(5)-(3-(0+(1)+(6+(4-(4)-(7-(9-(9)+(1)+(4)+(7))-(9))))-(3-(1+5-7-(7))-(4+(3+(7-(9+(8)-(9+(8-(3)+(10-(1)+(5)-(2-(4)+(0-(10-(7-(10+(1)+(1)-(4)-(10)))+(7)+(4-4)+0+9-(6))-(6+(5)))))-(8-(6)-(10+(5-(8)-(10+(3+(0+(6-(9)-(1)))-(0)-(9+(0+(1+(8+2-(4-(9-(4+(3+4)-(10+(1-(5)+(10-(4-(6-(4-(2+(4)-(9)-(4))))-3))))+(9)+(9+(0-(1+(5-(5+(7)-6-(8-(3-(3+(1)-(9-(7-(6)))-(2+(1))-(1+(2+(10))))+(6)+(0+(9-(1)-(10)))+(10-(1-(1)))-(0+(0-(2-(4-(6+(1))+(0)+(5)-(5+(5)-(4+(6)-(5)+(1-(7))))+(8)-(7))-3))-(7+(7+(9+(0+(10)-(7-(0-(2)-(6))-(2+(10)))+(7)+(3))+(8-(8+(10)-(8)+(0+(6-(2)-(1))+(3+(10+(10-(4+(7-(2)-(9-(2+(8))))+(7)-(7+10+(9-(2)+(0))-(6+(1)))+(10)+(2)-(7)-(4)-(10+(3-(6))))+(8-(1))-(10)))+(5+(3-(0-(1-(2+(3-(6-(4)-(1)+(4+(7+(3)-(7)+(4-(9))+(0-(4)+(9+(3-(9)+(4-(10+(6+(4)))+(4))+(10+(0-3-(8+(0-(6))-(5))-(9))-(6))))+2))+6+(6)+(1-(6))-(7-(1))-(8)+(9-(8))+(4)))-(0+7-(1)))-(2))+(0)))+(4-(7))-(5)-(8)-4+(1-(3-(8+(2+0)+(7)))))))-(4-(2))+(9))))+(7)-(2-(10+(4)-(8+(7)+(5-(4)-(6+6))-(2+(6)-(2+(4-(2-(8-(4)-(7+(5)-(10-(7)))))-(10+(9+(8)-(10)+(3-(7+(4+(2+(5)-(10+7+(2-(10)-(10+(3))+(0-(10+(8+(4+(7-(2)+(3+9))))+(7-(6+(2)-(2)+7+(5+(7+(10+(5-(4)-2+(5)+(1))+(0))))-(9))-5-(8)-(9-(4)-(10))-(8-(5)-(10)-7)+(5))-(4)))))+6+3+(3+(6+(9)))-10+(6)+(0)))))+(7)))+(1-(5)+(3-(3+6))+(5)+(7)-(9-(1))+(4+(1))+(2)))-(3))-(10)+(1)))))))))+(3)+2+(8-(4)))-(1))+(6-(8-(0)-(8-(0))-(2-(4+2)))-(9+1)))-(8-(8+(1-8-(7))))+7-(5+(5+(6+(10)+(8)))))))-(4))))-(4)-(6)+(10)-(5)))+(0+(2+(4))-(4-(2)+(0-(10-(4))))))+3-(10)))-(9+(9-(8-(7)-4))))+(6))-(4-(9))))-(1))+(10))))-(0+(9+7-(1)))))-(7)-(4)))-(9))))-7))))+(9))+(10))-(8-(9)))+(8))-(6)-(4)-(8)))))))))))))-(7)))))+(2-(6)-(0))))-(0)-(5+(9)+(9))+(3-(9))))+(8))))))))-(0-(0))+(7-(2))))))))-(6))-(8+(9))-(9+(2))-(2)+(9))-(4))+(7)-(1)-(6))-(2-0)))))))-(0)))))-(8+(0-(5))))+(9)-(1-(0)-(3)))-(3)-(0)))+(4)+(6))))-(5)+(1-(5)))))+(10))))-(5)+(0))))))-(6)))))))+(1))))))))-(5)))))))))+(8))))))))))))))))))-(7)+(10)))))))))))))-(4))))))-(10)-(4))+(1)+(3))-(1))))+(9))))))))+(2-(7-(4-(3+(0))))-(10)))))+0))))+(10)))))+(4)))))))))))+(3)))))))-(5)))))+(3)))))))))))))-(7)-(5-(2+(9))-(0))+(4)))+(10)))))-(1)))-(0))+(1))-(8+(10))))))-(10)-(10+(9)+(2))))-(1)))-(2))))+(4+(5))))))+(8))))))))))))))))))))))-(7)))-(3)))))))+(1))))-(7)-(3)+(4))))))-(6)))))))-(9-(3)))))))))))+(8))))))))))+(6))))))))))))))))))))))))))))))))))+(5))+(7))))))))))))))))))))))))-(10))))))+9)))))))";
    cout << calculate(expr);
    int r = 0, l = 0;
}
void printArr(vector<int> x) {
    for (int i = 0; i < x.size(); i++)
        cout << x[i] << " ";
    cout << "\n";
}

void printCArr(vector<char> x) {
    for (int i = 0; i < x.size(); i++)
        cout << x[i] << " ";
    cout << "\n";
}

int calculate(string s) {
    int i, right, left, digit = 1, lastLeftValue, tmp, modifyValue;
    bool FIRST = true;
    char op = ' ';
    vector<int> operandValue;
    vector<char> others;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;
        if (s[i] == '+' || s[i] == '-' || s[i] == '(') {
            digit = 1;
            others.push_back(s[i]);
        } else if (s[i] == ')') {
            digit = 1;
            op = others[others.size() - 1];
            while (others[others.size() - 1] != '(') {
                right = operandValue[operandValue.size() - 1];
                operandValue.pop_back();
                left = operandValue[operandValue.size() - 1];
                operandValue.pop_back();
                op = others[others.size() - 1];
                others.pop_back();
                if (op == '-') {
                    modifyValue = right - 2 * lastLeftValue;
                    if (!FIRST)
                        operandValue.push_back(left + modifyValue);
                    else {
                        operandValue.push_back(left - right);
                    }
                } else if (op == '+') {
                    operandValue.push_back(left + right);
                }
                lastLeftValue = left;
                FIRST = false;
            }
            FIRST = true;
            others.pop_back();
        } else {
            if (digit == 1)
                operandValue.push_back((s[i] - '0'));
            else {
                operandValue[operandValue.size() - 1] = operandValue[operandValue.size() - 1] * digit + (s[i] - '0');
            }
            digit = 10;
        }
    }
    while (others.size() != 0) {
        left = operandValue[0];
        operandValue.erase(operandValue.begin());
        right = operandValue[0];
        operandValue.erase(operandValue.begin());
        op = others[0];
        others.erase(others.begin());
        if (op == '-') {
            operandValue.insert(operandValue.begin(), left - right);
        } else if (op == '+') {
            operandValue.insert(operandValue.begin(), left + right);
        }
    }
    return operandValue[0];
}