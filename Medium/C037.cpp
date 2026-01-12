#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> fib;

string addNum(string num1, string num2)
{
	string result;
	int sum = 0;

	while (!num1.empty() || !num2.empty() || sum)
	{
		if (num1 != "")
		{
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (num2 != "")
		{
			sum += num2.back() - '0';
			num2.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}

	reverse(result.begin(), result.end());
	return result;
}

bool compare(string &str1, string &str2)
{
	if (str1.length() == str2.length())
	{
		for (int i = 0; i < str1.length(); i++)
		{
			if (str1[i] != str2[i])
			{
				return str1[i] > str2[i];
			}
		}
	}

	return str1.length() > str2.length();
}

void addFib()
{
	long long len = fib.size();
	fib.push_back(addNum(fib[len - 1],fib[len - 2]));
}

int binary_search(int start, int end, string target)
{
	int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if ( compare(target, fib[mid]) )
		{
			start = mid + 1;
		}
		else if (compare(fib[mid] , target))
		{
			end = mid - 1;
		}
		else
		{
			break;
		}
	}

	return mid;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fib.push_back("1");
	fib.push_back("2");


	while (true)
	{
		string a, b; cin >> a >> b;

		if (a == "0" && b == "0")
		{
			break;
		}

		while (compare(b, fib.back()))
		{
			addFib();
		}

		unsigned int len = fib.size();
		int index1 = binary_search(0, len - 1, b), index2 = binary_search(0, len - 1, a);
		
		if (compare(fib[index1], b))
		{
			index1--;
		}
		if (compare(a,fib[index2]) )
		{
			index2++;
		}


		//cout << "index2 : " << index2 << " index1 : " << index1 << endl;
		unsigned long long result = index1 - index2 + 1;
		


		cout << result << "\n";
	}
	
	return 0;
}