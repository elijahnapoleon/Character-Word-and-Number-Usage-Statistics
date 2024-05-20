

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <algorithm>

using namespace std;

void ReadData(map<char,int>& c, unordered_map<string,int>& word, unordered_map<string,int>& num)
{
	ifstream file;
	ofstream outfile;
	string filename="data1902";
	pair<unordered_map<string,int>::iterator, bool> ret;
	pair<map<char,int>::iterator,bool> ret2;
	pair<string,int> p;
	pair<char,int> c2;
	word.max_load_factor(200);
	num.max_load_factor(200);

	outfile.open(filename);

	if(outfile)
	{
		string data;
		while(getline(cin,data))
		{
		outfile << data;
		if(cin.bad())
		{
			break;
		}
		}
		outfile.close();
	}
	
	file.open(filename);


	if (file)
	{
		char a;
	
		while (file.get(a))
		{	
			c2.first = a;
			c2.second = 1;
			ret2 = c.insert(c2);
			
			if(!ret2.second)
			{
				ret2.first->second++;
			}
		}

		file.clear();
		file.seekg(0);

		string b;

			//input words
			while (file.get(a))
			{
				if(isalpha(a))
				{
					a = tolower(a);
					b = b + a;
				}
				else
				{
					if(!b.empty())
					{
						p.first = b;
						p.second = 1;

						if(word.find(b) != word.end())
						{
							word.find(b)->second++;
						}
						else
						{
							word.insert(word.end(), p);
						}
						
					}
					b.clear();
				}
			}

			if(!b.empty())
					{
						p.first = b;
						p.second = 1;
						ret = word.insert(p);

						if(!ret.second)
						{
							ret.first->second++;
						}
					}
					b.clear();

			file.clear();
			file.seekg(0);

			//input numbers
			while (file.get(a))
			{
				
				if(isdigit(a))
				{
					b = b + a;
				}
				else
				{
					if(!b.empty())
					{
						p.first = b;
						p.second = 1;

						if(num.find(b) != num.end())
						{
							num.find(b)->second++;
						}
						else
						{
							num.insert(num.end(), p);
						}
						
					}
					b.clear();
				
			
				}

				
			}

			

			if(!b.empty())
					{
						p.first = b;
						p.second = 1;
						ret = num.insert(p);

						if(!ret.second)
						{
							ret.first->second++;
						}
					}
					b.clear();
		
				file.close();
	}
}


bool cmp(pair<string, int>& a,  pair<string,int>& b) 
{  
    return a.second > b.second; 
}

bool cmp2(pair<char, int>& a, pair<char, int>& b)
{
	if(a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second > b.second;
}

void mapsort(unordered_map<string,int> &m)
{
    vector<pair<string, int>> temp; 
 
    for (auto& x : m) 
	{ 
        temp.insert(temp.begin(),x); 
    }

	vector<pair<string,int>> temp2 = temp;
	
	sort(temp.begin(), temp.end(), cmp);

	int i =0;

	for (auto& it : temp) 
	{ 
			cout << "No. " << i << ": " <<left << setw(12) << it.first << it.second << endl;
			i++; 
			if(i==10){break;}
    } 
}

void mapsort(map<char,int> &m)
{
    vector<pair<char, int>> temp; 
 
    for (auto& x : m) 
	{ 
        temp.push_back(x); 
    } 
  
    sort(temp.begin(), temp.end(), cmp2); 
 
	int i =0;

	for (auto& it : temp) 
	{ 
		if(it.first == '\n')
		{
			cout << "No. " << i << ": " << '\\' <<left << setw(11) << 'n' << it.second << endl;
			i++;
		}
		else if(it.first == '\t')
		{
			cout << "No. " << i << ": " << '\\' <<left << setw(11) << 't' << it.second << endl;
			i++;
		}
		else
		{
        cout << "No. " << i << ": " <<left << setw(12) << it.first << it.second << endl;
		i++;
		}
		if(i == 10){break;} 
    } 
}

int main()
{	
	map<char,int> c;
	unordered_map<string,int> word;
	unordered_map<string,int> num;
	
	ReadData(c, word, num);

	int max = 10;
	if(c.size() < 10)
	{
		max = c.size();
	}

	cout << "Total " << c.size() << " different characters, " << max << " most used characters:\n";

	mapsort(c);

	max = 10;
	if(word.size() < 10)
	{
		max = word.size();
	} 

	cout << "Total " << word.size() << " different words, " << max << " most used words:\n";

	mapsort(word);

	max=10;
	if(num.size() < 10)
	{
		max = num.size();
	}

	cout << "Total " << num.size() << " different numbers, " << max << " most used numbers:\n";

	mapsort(num);
	
}
