#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "SegmentTree.h"

/* internal functions declaration */
int create_st_util(int arr[], int ss, int se, int *st, int si);
void update_value_util(int *st, int ss, int se, int i, int diff, int index);
int get_sum_util(int *st, int ss, int se, int qs, int qe, int index);
int getMid(int s, int e);


int 
getMid(int s, int e) {
	return s + (e-s)/2;
}
int 
create_st_util(int arr[], int ss, int se, int *st, int si) {
	if (ss == se) {
		st[si] = arr[ss];
		return arr[ss];
	}

	int mid = getMid(ss, se);
	st[si] = create_st_util(arr, ss, mid, st, si*2+1) +
					create_st_util(arr, mid+1, se, st, si*2+2);
	return st[si];
}

int*
create_segment_tree(int arr[], int n) {
	int h = (int)(ceil(log2(n))); // height of segment tree
	int max_size = 2*(int)pow(2, h) - 1; // maximum size of segment tree
	int *st = malloc(sizeof(int)*max_size);	
	create_st_util(arr, 0, n-1, st, 0);
	return st;
}


int 
get_sum_util(int *st, int ss, int se, int qs, int qe, int index) {
	if (qs <= ss && qe >= se) { // {qs[ss se]qe}
		return st[index];
	}
	if (se < qs || ss > qe) {
		return 0;
	}
	int mid = getMid(ss, se);
	return get_sum_util(st, ss, mid, qs, qe, 2*index+1) +
		get_sum_util(st, mid+1, se, qs, qe, 2*index+2);
}

int 
get_sum(int *st, int n, int qs, int qe) {
	if (qs < 0 || qe > n - 1 || qs > qe) {
		printf("Invalid Input");
		return -1;
	}
	return get_sum_util(st, 0, n-1, qs, qe, 0);
}
void 
update_value_util(int *st, int ss, int se, int i, int diff, int index) {
	if (i < ss || i > se) {
		return;
	}	
	st[index] = st[index] + diff;
	if (se != ss) {
		int mid = getMid(ss, se);
		update_value_util(st, ss, mid, i, diff, 2*index + 1);
		update_value_util(st, mid+1, se, i, diff, 2*index + 2);
	}
}
void update_value(int arr[], int *st, int n, int i, int new_val) {
	if (i < 0 || i > n-1) {
		printf("Invalid Input");
		return;
	}
	int diff = new_val - arr[i];
	arr[i] = new_val;
	update_value_util(st, 0, n-1, i, diff, 0);
}

