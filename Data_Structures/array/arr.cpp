#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

void benchmark_vector(vector<int>& vec, const string& label) {
    cout << label << ":\n";

    // Access benchmark
    auto start = high_resolution_clock::now();
    volatile int temp = vec[vec.size() / 2]; // prevent optimization
    auto end = high_resolution_clock::now();
    cout << "  Access: " << duration<double, micro>(end - start).count() << " us\n";

    // Insert benchmark
    start = high_resolution_clock::now();
    vec.insert(vec.begin() + vec.size() / 2, -1);
    end = high_resolution_clock::now();
    cout << "  Insert: " << duration<double, micro>(end - start).count() << " us\n";

    // Delete benchmark
    start = high_resolution_clock::now();
    vec.erase(vec.begin() + vec.size() / 2);
    end = high_resolution_clock::now();
    cout << "  Delete: " << duration<double, micro>(end - start).count() << " us\n\n";
}

int main() {
    array<int, 5> arr1 = {1, 2, 3, 4, 5}; // or int arr1[5] = {1, 2, 3, 4, 5}; for C-style array, both are fixed size
    array<int, 50> arr2; 
    array<int, 100> arr3;
    iota(arr2.begin(), arr2.end(), 1); // Fill arr2 with values from 1 to 50
    iota(arr3.begin(), arr3.end(), 1); // Fill arr3 with values from 1 to 100

    cout << arr1.size() << endl; // Output: 5
    cout << arr2.size() << endl; // Output: 50
    cout << arr3.size() << endl; // Output: 100

    vector<int> vec1(500); // vevtors are dynamic size arrays
    vector<int> vec2(5000);
    vector<int> vec3(500000);

    iota(vec1.begin(), vec1.end(), 1);
    iota(vec2.begin(), vec2.end(), 1);
    iota(vec3.begin(), vec3.end(), 1);

    benchmark_vector(vec1, "Vector of size 500");
    benchmark_vector(vec2, "Vector of size 5000");
    benchmark_vector(vec3, "Vector of size 500000");


    return 0;
}