#include <iostream>
#include <array>
#include <stack>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> parseEquation(const string equation);
int evaluateEquation(const vector<string> postfix);

int main()
{
    string equation = "";

    cout << "Type equation: ";
    cin >> equation;

    vector<string> postfix = parseEquation(equation);
    int result = evaluateEquation(postfix);

    cout << result;
}

vector<string> parseEquation(const string equation)
{
    const array<char, 7> operators = {'+', '-', '*', '/', '^', '(', ')'};

    map<char, int> precedence;
    precedence.insert(pair<char, int> ('+', 1));
    precedence.insert(pair<char, int> ('-', 1));
    precedence.insert(pair<char, int> ('*', 2));
    precedence.insert(pair<char, int> ('/', 2));
    precedence.insert(pair<char, int> ('^', 3));

    vector<string> postfix;
    stack<char> operands;

    string buffer = "";

    for(unsigned i = 0; i < equation.length(); i++)
    {
      if(find(operators.begin(), operators.end(), equation[i]) == operators.end())
          buffer += equation[i];

      else if(equation[i] == '(')
          operands.push('(');

      else if(equation[i] == ')')
      {
          if(buffer.length() > 0)
          {
              postfix.push_back(buffer);
              buffer = "";
          }

          while(operands.empty() || operands.top() != '(')
          {
              buffer = operands.top();
              postfix.push_back(buffer);
              operands.pop();
              buffer = "";
          }

          operands.pop();
      }

      else
      {
          if(buffer.length() > 0)
          {
              postfix.push_back(buffer);
              buffer = "";
          }

          while(operands.empty() == false && operands.top() != '(' && [&](char a, char b)-> bool {
              return precedence.at(a) >= precedence.at(b) ? true : false;} (operands.top(), equation[i]))
          {
              buffer = operands.top();
              postfix.push_back(buffer);
              operands.pop();
              buffer = "";
          }

          operands.push(equation[i]);
      }
    }

    if(buffer.empty() == false)
        postfix.push_back(buffer);

    while(!operands.empty())
    {
        buffer = operands.top();
        postfix.push_back(buffer);
        operands.pop();
        buffer = "";
    }

    return postfix;
}

 int evaluateEquation(const vector<string> postfix)
 {
    const array<string, 5> operators = {"+", "-", "*", "/", "^"};

    stack<int> operands;
    int num_1, num_2, buffer;

    for(auto V: postfix)
    {
        if(find(operators.begin(), operators.end(), V) != operators.end())
        {
            num_1 = operands.top();
            operands.pop();
            num_2 = operands.top();
            operands.pop();

            if(V == "+") buffer = num_1 + num_2;
            else if(V == "-") buffer = num_2 - num_1;
            else if(V == "*") buffer = num_1 * num_2;
            else if(V == "/") buffer = num_2 / num_1;

            operands.push(buffer);
        }

        else
        {
            stringstream convert;
            convert << V;
            convert >> buffer;

            operands.push(buffer);
        }
    }

    return operands.top();
 }
