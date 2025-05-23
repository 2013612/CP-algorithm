#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int n, ans, a[200006], b[200006], c[200006], d[200006];
pair<int, int> p[200006];
map<pair<int, int>, int> m;

bool f(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return b.second < a.second;
	}
	return a.first < b.first;
}

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
          int right);
 
/* This function sorts the
   input array and returns the
number of inversions in the array */
int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 
/* An auxiliary recursive function
  that sorts the input array and
returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        /* Divide the array into two parts and
        call _mergeSortAndCountInv()
        for each of the parts */
        mid = (right + left) / 2;
 
        /* Inversion count will be sum of
        inversions in left-part, right-part
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
 
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
 
/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
int merge(int arr[], int temp[], int left, int mid,
          int right)
{
    int i, j, k;
    int inv_count = 0;
 
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
 
            /* this is tricky -- see above
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }
 
    /* Copy the remaining elements of left subarray
(if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    /* Copy the remaining elements of right subarray
       (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];
 
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n; i++) {
		p[i] = {a[i], b[i]};
		m[p[i]]++;
	}
	sort(p, p + n, f);
	for (int i = 0; i < n; i++) {
		c[i] = p[i].second;
	}
//	for (int i = 0; i < n; i++) {
//		printf("%d ", p[i].first);
//	}
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		printf("%d ", p[i].second);
//	}
//	cout << endl;
	int ans = mergeSort(c, n);
	//cout << ans << endl;
//	int ind = 1;
//	d[0] = p[0].second;
//	for (int i = 1; i < n; i++) {
//		if (p[i].first != p[i - 1].first) {
//			ans += (ind * (ind + 1) / 2) - mergeSort(d, ind);
//			ind = 0;
//		}
//		d[ind] = p[i].second;
//		ind++;
//	}
//	ans += (ind * (ind + 1) / 2) - mergeSort(d, ind);
//	ind = 0;
	for (auto x : m) {
		ans += x.second * (x.second + 1) / 2;
 	}
	printf("%d\n", ans);
	return 0;
}
