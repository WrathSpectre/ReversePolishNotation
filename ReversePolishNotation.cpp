#include <iostream>
#include <stack>
#include <array>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string parseEquation(const string equation);
unsigned getPrecedence(const char sign);
void evaluateEquation(vector<string> postfix);

int main()
{
    string equation = "";

    cout << "Type equation: ";
    cin >> equation;

    parseEquation(equation);

}

unsigned getPrecedence(const char sign)
{
    switch(sign)
    {
      case '+': return 1;
      case '-': return 1;
      case '*': return 2;
      case '/': return 2;
      case '^': return 3;
      default: return 0;
    }
}

string parseEquation(const string equation)
{
    const array<char, 7> operators = {'+', '-', '*', '/', '^', '(', ')'};

    vector<string> postfix;
    stack<char> operands;

    string buffer = "";

    for(unsigned i = 0; i < equation.length(); i++)
    {
      if(find(operators.begin(), operators.end(), equation[i]) != operators.end() == false)
          buffer += equation[i];

      else if(equation[i] == '(')
      {
          operands.push('(');
      }

      else if(equation[i] == ')')
      {
          if(buffer.length() >0){ postfix.push_back(buffer);
          buffer = "";}

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
        if(buffer.length() >0){ postfix.push_back(buffer);
        buffer = "";}

          while(operands.empty() == false && operands.top() != '(' && [&](char a, char b)-> bool {
              return getPrecedence(a) >= getPrecedence(b) ? true : false;
              } (operands.top(), equation[i]))
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

    for(auto V: postfix)
    {
      cout<<"> "<<V<<endl;
    }

    cout<<endl<<endl;

    evaluateEquation(postfix);
}

int PerformOperation(string operation, int operand1, int operand2)
{
	if(operation == "+") return operand1 + operand2;
	else if(operation == "-") return operand2 - operand1;
	else if(operation == "*") return operand1 * operand2;
	else if(operation == "/") return operand2 / operand1;

	else cout<<"Unexpected Error \n";
	return -1;
}

 void evaluateEquation(vector<string> postfix)
 {
    const array<string, 5> operators = {"+", "-", "*", "/", "^"};

    stack<int> operands;

    //stringstream convert;
    int buffer = 0;

    for(auto V: postfix)
    {



      if(V == "+" || V == "-" || V == "*" || V == "/")
        {
            int a = operands.top();
            operands.pop();
            int b = operands.top();
            operands.pop();

            int res = PerformOperation(V, a, b);

            operands.push(res);
        }

        else
        {
          //Scout<<V<<endl;
          stringstream convert;
          convert << V;
          convert >> buffer;
          //cout<<buffer<<endl;

          operands.push(buffer);
        }
    }

    cout<<operands.top()<<endl;
 }













































    /*for(const auto V: postfix)
    {
        if(find(operators.begin(), operators.end(), V) != operators.end() == false)
        {
          stringstream convert;
          convert << V;
          convert >> buffer;
          cout<<buffer<<endl;
          operands.push(buffer);
        }

        else
        {
          if(V == "+")
          {
            val_1 = operands.top();
            operands.pop();
            val_2 = operands.top();
            operands.pop();
            int c = 0;
            c = val_1 + val_2;
            operands.push(c);
          }

          if(V == "-")
          {
            val_1 = operands.top();        //cout<<buffer<<endl;

            operands.pop();
            val_2 = operands.top();
            operands.pop();
            int c = 0;
            c = val_2 - val_1;
            operands.push(c);
          }

          if(V == "*")
          {
            val_1 = operands.top();        //cout<<buffer<<endl;

            operands.pop();
            val_2 = operands.top();
            operands.pop();
            int c = 0;
            c = val_1 * val_2;
            operands.push(c);
          }

          if(V == "/")
          {
            val_1 = operands.top();
            operands.pop();
            val_2 = operands.top();
            operands.pop();
            int c = 0;
          c = val_2 / val_1;
          operands.push(c);
          }
}
    }
    //cout<<q;
    cout<<operands.top()<<endl;
}*/


    /*
    const array<string, 7> operators = {"+", "-", "*", "/", "^"};

    stack<int> operands;

    //stringstream convert;
    int a, b, buffer;

    for(const auto V: postfix)
    {
        if(find(operators.begin(), operators.end(), V) != operators.end() == false)
          {
          stringstream convert;
        if(find(operators.begin(), operators.end(), V) != operators.end() == false)
        {
          stringstream convert;
          convert << V;
          convert >> buffer;
          cout<<buffer<<endl;

          operands.push(buffer);

        }

        else
        {
          if(V == "+")
          {
              a = operands.top();
              operands.pop();
              b = operands.top();
              operands.pop();
              int c = a+b;
              //cout<<c<<endl;
              operands.push(a + b);
          }

          if(V == "-")
          {
              a = operands.top();
              operands.pop();
              b = operands.top();
              operands.pop();
              int c = a+b;
    /*stack<int> operands;

    //stringstream convert;
    int a, b, buffer;

    stack<int> operands;

    //stringstream convert;
    int a, b, buffer;

    for(const auto V: postfix)
    {
        if(find(operators.begin(), operators.end(), V) != operators.end() == false)
        {
          stringstream convert;
          convert << V;
          convert >> buffer;
          cout<<buffer<<endl;

          operands.push(buffer);

        }

        else
        {
          if(V == "+")
          {
              a = operands.top();
              operands.pop();
              b = operands.top();
              operands.pop();
              int c = a+b;
            //cout<<c<<endl;
          operands.push(a + b);
*/
