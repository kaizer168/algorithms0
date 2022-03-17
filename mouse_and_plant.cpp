#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int N, M;
    int x, y;
    int maxMouse = 0;
    int maxIndex = 0;
    int minIndex2 = 0;
    int minCandidate_xy = 0;
    int minCandidate_x = 0;
    bool gotPlant = false;
    vector<int> mouse_x = {};
    vector<int> mouse_y = {};
    vector<int> plant_x = {};
    vector<int> plant_y = {};
    vector<int> candidate_x = {};
    vector<int> candidate_y = {};
    vector<int> candidate2_x = {};
    vector<int> candidate2_y = {};
    string mouse_key = "";
    unordered_map<string, int> hm;
    string ans = "";

    cin >> N;
    cin >> M;

    for (int i = 0; i < N; i++) {
        cin >> x;
        cin >> y;
        mouse_x.push_back(x);
        mouse_y.push_back(y);
    }

    for (int j = 0; j < M; j++) {
        cin >> x;
        cin >> y;
        plant_x.push_back(x);
        plant_y.push_back(y);
    }

    for (int i = 0; i < mouse_x.size(); i++) {
        mouse_key = to_string(mouse_x[i]) + " " + to_string(mouse_y[i]);
        hm[mouse_key] += 1;
    }

    for (int i = 0; i < mouse_x.size(); i++) {
        mouse_key = to_string(mouse_x[i]) + " " + to_string(mouse_y[i]);
        gotPlant = false;
        for (int j = 0; j < plant_x.size(); j++) {
            if (mouse_x[i] == plant_x[j] && mouse_y[i] == plant_y[j]) {
                gotPlant = true;
            }
        }
        if (!gotPlant) {
            if (hm[mouse_key] >= maxMouse) {
                maxMouse = hm[mouse_key];
                maxIndex = i;
            }
        }
    }

    for (int i = 0; i < mouse_x.size(); i++) {
        mouse_key = to_string(mouse_x[i]) + " " + to_string(mouse_y[i]);
        gotPlant = false;
        for (int j = 0; j < plant_x.size(); j++) {
            if (mouse_x[i] == plant_x[j] && mouse_y[i] == plant_y[j]) {
                gotPlant = true;
            }
        }
        if (!gotPlant) {
            if (hm[mouse_key] == maxMouse) {
                candidate_x.push_back(mouse_x[i]);
                candidate_y.push_back(mouse_y[i]);
            }
        }
    }

    if (candidate_x.size() > 1) {
        for (int i = 0; i < candidate_x.size(); i++) {
            if (candidate_x[i] + candidate_y[i] <= minCandidate_xy) {
                candidate2_x.push_back(candidate_x[i]);
                candidate2_y.push_back(candidate_y[i]);
                minIndex2 = i;
            }
        }
        if (candidate2_x.size() > 1) {
            for (int i = 0; i < candidate2_x.size(); i++) {
                if (candidate2_x[i] <= minCandidate_x) {
                    ans = to_string(candidate2_x[i]) + " " + to_string(candidate2_y[i]);
                }
            }
        }
        else {
            ans = to_string(candidate_x[minIndex2]) + " " + to_string(candidate_y[minIndex2]);
        }
    }
    else {
        ans = to_string(mouse_x[maxIndex]) + " " + to_string(mouse_y[maxIndex]);
    }

    cout << ans << endl;

    return 0;
}

