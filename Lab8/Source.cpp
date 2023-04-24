#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>

using namespace std;
map<string, int> words;

class compare
{
public:
	bool operator()(const pair<string, int>& a, const pair<string, int>& b)
	{
		if (a.second == b.second)
			return a.first > b.first;
		else
			return a.second < b.second;
	}
};

void addToMap(string x)
{
	string::iterator it;
	for (it = x.begin(); it != x.end(); it++)
		*it = tolower(*it);
	map<string, int>::iterator i = words.find(x);
	if (i != words.end())
		i->second = i->second + 1;
	else
		words.insert(make_pair(x, 1));
}

int main()
{
	ifstream fd;
	fd.open("sentence.txt");

	string phrase;

	while (getline(fd, phrase))
	{
		size_t prev = 0, pos;
		while ((pos = phrase.find_first_of("!?., ", prev)) != string::npos)
		{
			if (pos > prev)
			{
				addToMap(phrase.substr(prev, pos - prev));
			}
			prev = pos + 1;
		}
		
		if (prev < phrase.length()) {
			
			addToMap(phrase.substr(prev, string::npos));
		}
	}

	fd.close();

	priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq(words.begin(), words.end());

	while (!pq.empty())
	{
		pair<string, int> word = pq.top();
		cout << word.first << " => " << word.second << '\n';
		pq.pop();
	}

}