#include<bits/stdc++.h>
using namespace std;

stack <int> num;
stack<char> op;

//从 num 栈中取出两个数字 a 和 b
//从 op 栈中取出一个运算符 c
//根据运算符 c 进行相应的运算，并将结果 x 压入 num 栈中
void eval(){
    auto b = num.top(); num.pop();
    auto a = num.top(); num.pop();
    auto c = op.top();  op.pop();
    int x;
    if(c =='+') x = a + b;
    else if(c == '-')   x = a - b;
    else if(c == '*')   x = a * b;
    else    x = a / b;
    num.push(x);
}

int main()
{
    //用于存储运算符的优先级
    unordered_map<char,int> pr{{'+',1},{'-',1},{'*',2},{'/',2}};
    //读取用户输入的表达式，存储在字符串 str 中
    string str;
    cin>>str;

    for(int i = 0;i<str.size();i++){
        auto c = str[i];
        //使用 x 存储这个数字，可能是多位数（例如 123）
        //通过循环将所有连续的数字组合成一个整数，并将其压入 num 栈中
        if(isdigit(c)){
            int x = 0,j = i;
            while(j<str.size()&&isdigit(str[j])){
                x = x*10 + str[j] - '0';    //变为整型
                j++;
            }
            i = j-1;
            num.push(x);
        }else if(c == '('){
            op.push(c);
        }else if(c == ')'){     //如果当前字符是右括号 )，则不断调用 eval 函数，直到遇到对应的左括号 (，然后将左括号弹出
            while(op.top() != '('){ //确保所有在括号内的运算都被计算出来。只有在遇到 ( 时，才停止计算
                eval();
            }
            op.pop();
        }else{
            while(op.size()&&pr[op.top()]>=pr[c]){  //判断优先级
                eval();     
            }
            op.push(c);
        }
    }
    //在遍历完字符串后，可能还有未计算的运算符，继续调用 eval 进行计算
    while(op.size()){
        eval();
    }
    cout<<num.top()<<endl;
    return 0;
}