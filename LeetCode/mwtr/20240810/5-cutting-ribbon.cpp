#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 200005

int colors[MAXN], fenwickTree[MAXN], lastOccurrence[MAXN], result[MAXN];
int n, q, currentL, currentR;
char direction;

struct Query {
    int l, r;
    int index;
};

Query queries[MAXN];

bool compare(Query a, Query b) {
    return a.r < b.r;
}

int lowbit(int x) {
    return x & (-x);
}

void updateFenwickTree(int index, int value) {
    while (index <= n) {
        fenwickTree[index] += value;
        index += lowbit(index);
    }
}

int queryFenwickTree(int index) {
    int sum = 0;
    while (index > 0) {
        sum += fenwickTree[index];
        index -= lowbit(index);
    }
    return sum;
}

int main() {
    cin >> n >> q;

    // Read the initial ribbon colors
    for (int i = 1; i <= n; i++) {
        cin >> colors[i];
    }

    // Extend the ribbon to handle the circular nature
    for (int i = n + 1; i <= 2 * n; i++) {
        colors[i] = colors[i % n];
    }

    currentL = 0;
    currentR = 2 * n;

    for (int i = 1; i <= q; i++) {
        int x;  // Declare x here
        cin >> direction >> x;
        if (direction == 'L') {
            currentL = currentL % n;
            if (x >= n) {
                queries[i].l = 0;
                queries[i].r = n;
                queries[i].index = i;
                currentL += (x % n);
            } else {
                queries[i].l = currentL;
                queries[i].r = currentL + (x % n);
                queries[i].index = i;
                currentL += (x % n);
            }
        } else {
            currentR = (currentR % n) + n;
            if (x >= n) {
                queries[i].l = 0;
                queries[i].r = n;
                queries[i].index = i;
                currentR = currentR - (x % n) + n;
            } else {
                queries[i].l = currentR - x;
                queries[i].r = currentR;
                queries[i].index = i;
                currentR = currentR - x;
            }
        }
    }

    sort(queries + 1, queries + 1 + q, compare);

    int next = 1;
    for (int i = 1; i <= q; i++) {
        for (int j = next; j <= queries[i].r; j++) {
            if (lastOccurrence[colors[j]]) {
                updateFenwickTree(lastOccurrence[colors[j]], -1);
            }
            updateFenwickTree(j, 1);
            lastOccurrence[colors[j]] = j;
        }
        next = queries[i].r + 1;
        result[queries[i].index] = queryFenwickTree(queries[i].r) - queryFenwickTree(queries[i].l);
    }

    for (int i = 1; i <= q; i++) {
        cout << result[i] << endl;
    }

    return 0;
}
