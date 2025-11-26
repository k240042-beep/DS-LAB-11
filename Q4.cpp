#include <iostream>
using namespace std;

struct PairSum {
    int a, b, sum;
    bool used;
};

int main() {
    int n;
    cin >> n;
    int arr[1000];
    for(int i = 0; i < n; i++) cin >> arr[i];

    PairSum store[100000];
    int idx = 0;
    bool found = false;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int s = arr[i] + arr[j];

            for(int k = 0; k < idx; k++) {
                if(store[k].sum == s) {
                    if(store[k].a != arr[i] && store[k].a != arr[j] &&
                       store[k].b != arr[i] && store[k].b != arr[j]) {
                        cout << "(" << store[k].a << ", " << store[k].b << ") and ("
                             << arr[i] << ", " << arr[j] << ")";
                        found = true;
                        break;
                    }
                }
            }
            if(found) break;

            store[idx].a = arr[i];
            store[idx].b = arr[j];
            store[idx].sum = s;
            store[idx].used = true;
            idx++;
        }
        if(found) break;
    }

    if(!found) cout << "No pairs found";
}
