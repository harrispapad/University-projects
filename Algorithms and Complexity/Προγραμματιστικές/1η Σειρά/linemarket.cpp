#include <iostream>
#include <tuple>
#include <vector>
#include <fstream>
#include <algorithm> 

using namespace std;

bool can_place(int d, int N, const vector<tuple<int, int>>& regions) 
{
    int count = 0;
    int prev_pos = 0;

    for (int i = 0; i <= regions.size(); i++) {
        int start = get<0>(regions[i]);
        int end = get<1>(regions[i]);

        int position;

        if (i == 0) {
            position = start;
        } else {
            position = max(start, prev_pos + d);
        }
        while (position <= end && count < N) {
            count++;
            prev_pos = position;
            position += d; 
        }

    }

    int ret = (count >= N) ? true : false;
    
    return ret;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        cerr << "Usage: ./test <input_file>" << endl;
        return 1;
    }

    ifstream infile(argv[1]);
    if (!infile.is_open()) {
        cerr << "Error: Could not open file " << argv[1] << endl;
        return 1;
    }

    vector<tuple<int, int>> regions;

    int N, M;
    infile >> N >> M; 

    int s, f;
    for (int i = 0; i < M; i++) { 
        infile >> s >> f;
        regions.emplace_back(s, f); // si, fi of each region
    }

    infile.close(); 

    sort(regions.begin(), regions.end());

    int i = 1; 
    int j = 1000000000; 
    int result = 0;

    while (i <= j) {
        int mid = (i + j) / 2;

        if (can_place(mid, N, regions)) {
            result = mid;      
            i = mid + 1;    
        } 
        else {
            j = mid - 1;   
        }
    }

    cout << result << endl;

    return 0;
}
