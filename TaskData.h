#pragma once
#include <vector>
#include <memory>
#include "Interval.h"

using namespace std;

class TaskData
{
private:
	vector<int> _numbers;
	vector<Interval> _queries;

	vector<int> _GetReadNumbers () const;
	vector<Interval> _GetReadQueries () const;

	template<class T>
	vector<T> _GetReadSequence () const;

public:
	TaskData ();

	const int& Number (const int& index) const;
	const Interval& Query (const int& index) const;
	int NumberOfNumbers () const;
	int NumberOfQueries () const;
	int GetBeginOfInterval (const int& index) const;
	int GetEndOfInterval (const int& index) const;
};

