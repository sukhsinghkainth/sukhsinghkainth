// postfix evaluation
#include <iostream>

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

class InfixToPostfix
{
private:
	
	int i,x,a,b,c, j;
	int final[max];
	Stack s1;

public:
	int infixToPostfix(string s)
	{
		j = 0;
		for (i = 0; i <= s.length(); i++)
		if(s[i]>='0'&& s[i]<='9')
		{
			x=s[i]-48;
			s1.push(x);
		}
		else if( s[i]=='+' || s[i]=='*' || s[i]=='-'||s[i]=='/')
	{
		a=s1.pop();
		b=s1.pop();
	
		
	 switch(s[i])
	 {
		 case '+' :
		 c=b+a;
		 s1.push(c);
		 break;
		  case '-' :
		  c=b-a;
		   s1.push(c);
		   break;
		   case '*' :
		   c=b*a;
		    s1.push(c);
			break;
		    case '/' :
			c=b/a;
			 s1.push(c);
			 break;
			

	 }
	}
	
	
			final[j++] = s1.pop();
		
		cout << "\nfinal=";
		for (i = 0; i < j; i++)
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