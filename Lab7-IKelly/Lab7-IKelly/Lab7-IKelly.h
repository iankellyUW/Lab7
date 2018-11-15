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

/*
void quickSort(vector<double>::iterator begin, vector<double>::iterator end) {
	if (end - begin > 1)
	{
		vector<double>::iterator split = partition(begin + 1, end, bind2nd(order, *begin));
		iter_swap(begin, split - 1);
		quickSort(begin, split - 1, order);
		quickSort(split, end, order);
	}
};
*/

void swap(int i, int j, vector<double> split) {
	double temp = split.at(i);
	split.at(i) = split.at(j);
	split.at(j) = temp;
};

void quickSort(int begin, int end, vector<double> split) {
	if (end - begin > 1)
	{
		int middle = (begin + end) / 2;
		int i = begin;
		int j = end;


		double pivot = split.at(middle);

		while (begin < j || i < end) {
			while (split.at(i) < pivot) {
				i++;
			}
			while (split.at(j) > pivot) {
				j--;
			}
			
			if (i <= j) {
				swap(i, j, split);
				i++;
				j--;
			}
			else {
				if (begin < j) {
					quickSort(begin, j, split);
				}
				if (i < end) {
					quickSort(i, end, split);

				}
				return;
			}
		}
	}
};

#endif