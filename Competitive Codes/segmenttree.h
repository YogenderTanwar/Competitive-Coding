#ifndef SEGMENTTRE_H
#define SEGMENTTRE_H
#include <vector>
#include <math.h>
using namespace std;
using ll = long long;

// 0-based indexing
template<class T>


class SegmentTree
{

public :
	// call constructor
	SegmentTree(vector<T> data, T value,  T (*combine)(T obj1, T obj2));

	SegmentTree(T ar[], T n, T value, T (*combine)(T obj1, T obj2));

	T query(ll l, ll r);

	void update(T val, ll pos);

private:


	vector<ll> stree;

	ll sizeofarray;

	T valueofextra;



	void build(vector<T> data);

	T (*combine)(T obj1, T obj2);

};


template<class T >  SegmentTree<T>::SegmentTree(vector<T> data, T value,   T (*combine)(T obj1, T obj2))
{
	this->combine = combine;
	sizeofarray = (data.size());

	valueofextra = value;
	build(data);

}


template<class T >  SegmentTree<T>::SegmentTree(T ar[], T n, T value,   T (*combine)(T obj1, T obj2))
{
	this->combine = combine;
	sizeofarray = (n);

	vector<ll> data;

	for (ll i = 0; i < n; i++) data.push_back(ar[i]);

	valueofextra = value;
	build(data);

}

template<class T> void SegmentTree<T>::build(vector<T> data)
{

	stree.resize(sizeofarray * 2);


	ll n = data.size();

	for (ll i = 0; i < n; i++)
	{
		stree[n + i] = data[i];
	}


	for (ll i = n - 1; i >= 1; i--)
	{
		stree[i] = combine(stree[2 * i], stree[2 * i + 1]);
	}




}


template<class T> T SegmentTree<T>:: query(ll l, ll r) // [l,r) always increase r
{
	l += sizeofarray;
	r += sizeofarray;

	T ans = valueofextra;

	if (l == r) return stree[l];





	while (r > l)
	{

		if (l % 2) ans = combine(ans, stree[l]) , l++;

		if (r % 2) r--, ans = combine(ans, stree[r]) ;




		l = l / 2;

		r = r / 2;



	}


	return ans;




}

template<class T> void SegmentTree<T>::update(T val, ll pos)
{
	pos += sizeofarray;

	stree[pos] = val;

	while (pos > 1)
	{
		pos = pos / 2;

		stree[pos] = combine(stree[2 * pos], stree[2 * pos + 1]);
	}
}

#endif