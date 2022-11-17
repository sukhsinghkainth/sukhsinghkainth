// InfixToPostfix.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#define max 20
using namespace std;

class Stack
{
private:
	int pos;
	char a[max];

public:
	Stack()
	{
		a[max] == 0;
		pos = -1;
	}
	int empty()
	{
		if (pos == -1)
			return 1;
		else
			return 0;
	}
	void push(int value)
	{
		if (pos == 20)
			cout << "/nStack overflow./n";
		else
		{
			++pos;
			a[pos] = value;
		}
	}
	int pop()
	{
		if (pos == -1)
		{
			cout << "\nStack underflow.\n";
			return 0;
		}
		else
		{
			return a[pos--];
		}
	}
	int top()
	{
		return a[pos];
	}
};
class Expression
{
public:
	int p(char d)
	{
		if (d == '*' || d == '/')
			return 2;
		else if (d == '+' || d == '-')
			return 1;
	}
};
class InfixToPostfix
{
private:
	Expression e;
	int i, j;
	char final[max];
	Stack s1;

public:
	int infixToPostfix(string s)
	{
		j = 0;
		for (i = 0; i <= s.length(); i++)
		{
			switch (s[i])
			{
			case '+':
			case '-':
			case '*':
			case '/':
				if (s1.empty())
					s1.push(s[i]);
				else if (s1.top() == '(' || s1.top() == '[' || s1.top() == '{')
					s1.push(s[i]);
				else if (e.p(s[i]) <= e.p(s1.top()))
				{
					final[++j] = s1.pop();
					s1.push(s[i]);
				}
				else
				{
					// final[++j]=s1.pop();
					s1.push(s[i]);
				}
				break;
			case '(':
			case '[':
			case '{':
				s1.push(s[i]);
				break;
			case ')':
				while (s1.top() != '(')
				{
					final[++j] = s1.pop();
				}
				s1.pop();
				break;
			case ']':
				while (s1.top() != '[')
				{
					final[++j] = s1.pop();
				}
				s1.pop();
				break;
			case '}':
				while (s1.top() != '{')
				{
					final[++j] = s1.pop();
				}
				s1.pop();
				break;
			default:
				final[++j] = s[i];
				break;
			}
		}
		while (s1.empty() == 0)
		{
			final[j++] = s1.pop();
		}
		cout << "\nfinal=";
		for (i = 1; i < j; i++)
			cout << final[i];
		cout << "\n";
		return 0;
	}
};

int main()
{
	InfixToPostfix c;
	string s;
	cout << "\nEnter the expression->";
	cin >> s;
	c.infixToPostfix(s);
}
