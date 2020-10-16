#include<bits/stdc++.h>
using namespace std;
using ll = long long;



class Trie
{
public:
	map<char, Trie*> m;
	bool end_of_word;

};


Trie* get_node()
{
	Trie * temp = new Trie();

	temp->end_of_word = false;

	return temp;



}


void insert(Trie * root, string key)
{

	Trie * curr = root;
	for (ll i = 0; i < key.size(); i++)
	{
		if (curr->m.count(key[i]) == 0)
		{

			curr->m[key[i]] = get_node();

		}


		curr = curr->m[key[i]];

		//	cout << curr << endl;

	}

	curr->end_of_word = true;


}


bool search(Trie * root, string key )
{
	Trie * curr = root;
	for (ll i = 0; i < key.size(); i++)
	{
		//cout << key[i] << " ";


		if (curr->m.count(key[i]) == 0)
		{
			return false;

		}

		curr = curr->m[key[i]];

	}
	if (curr != NULL && curr->end_of_word == true) return true;
	else return false;

}



int main()
{

	string keys[] = {"the", "a", "there",
	                 "answer", "any", "by",
	                 "bye", "their"
	                };
	int n = sizeof(keys) / sizeof(keys[0]);

	Trie *root = get_node();


	for (int i = 0; i < n; i++)
		insert(root, keys[i]);

	search(root, "their") ? cout << "Yes\n" :
	                             cout << "No\n";


	return 0;


}