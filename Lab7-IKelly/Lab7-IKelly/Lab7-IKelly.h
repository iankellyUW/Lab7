#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
#include <iterator>

using namespace std;

#ifndef HEADERS_H_
#define HEADERS_H_

//sorts 2300 in 4s
void bubbleSort(vector<double>::iterator &begin, vector<double>::iterator &end) {
	bool swap = true;
	while (begin != end-- && swap) {
		swap = false;
		for (auto i = begin; i != end; ++i) {
			if (*(i + 1) < *i) {
				std::iter_swap(i, i + 1);
				swap = true;
			}
		}
	}
};

bool isSmaller(double s1, double s2) {
	if (s1 < s2) {
		return true;
	}
	else {
		return false;
	}
}

// sorts 75000 in 4s
void insertionSort(vector<double>::iterator begin, vector<double>::iterator end) {
	bool smaller = false;
	vector<double>::iterator p;
	for (auto i = begin; i != end; ++i) {
		rotate(upper_bound(begin, i, *i, isSmaller), i, i + 1);
	}
};

// sorts 14600 in 4s
void selectionSort(vector<double>::iterator begin, vector<double>::iterator end) {
	for (auto i = begin; i != end; ++i) {
		std::iter_swap(i, std::min_element(i, end));
	}
};

// sorts 800000 in 4s
void mergeSort(vector<double>::iterator begin, vector<double>::iterator end) {
	if (end - begin > 1)
	{
		vector<double>::iterator middle = begin + (end - begin) / 2;
		mergeSort(begin, middle);
		mergeSort(middle, end);
		inplace_merge(begin, middle, end);
	}
};

// Sorts 70000 in 4s
void quickSort(vector<double> &A, vector<double>::iterator begin, vector<double>::iterator end) {
	if (A.size() <= 1)
		return;

	double pivot = A.at(A.size() / 2);

	vector<double> less;
	vector<double> equal;
	vector<double> greater;

	for (vector<double>::iterator i = begin; i != end; i++) {
		if (*i < pivot)
			less.push_back(*i);
		if (*i == pivot)
			equal.push_back(*i);
		if (*i > pivot)
			greater.push_back(*i);
	}
	quickSort(less, less.begin(), less.end());
	quickSort(greater, greater.begin(), greater.end());
	A.clear();
	A.insert(A.end(), less.begin(), less.end());
	A.insert(A.end(), equal.begin(), equal.end());
	A.insert(A.end(), greater.begin(), greater.end());
};

#endif