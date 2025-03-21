#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Employee {
    int D, H, idx, order;
    bool operator<(const Employee& other) const {
        if (D != other.D) return D < other.D;  // 근무일 수 높은 순
        if (H != other.H) return H < other.H;  // 화장실 급한 순
        return idx > other.idx;  // 줄 번호 작은 순
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<queue<Employee>> lines(M);
    priority_queue<Employee> pq;
    int decaLine = 0, decaPos = 0;

    // 입력을 받고 M개의 줄에 사원을 나눈다.
    for (int i = 0; i < N; i++) {
        int D, H;
        cin >> D >> H;
        int lineIdx = i % M;  // M개의 줄에 순서대로 배치
        lines[lineIdx].push({D, H, lineIdx, i});

        if (i == K) {
            decaLine = lineIdx;  // 데카가 속한 줄 저장
            decaPos = lines[lineIdx].size() - 1;
        }
    }

    // 각 줄에서 첫 번째 사원을 우선순위 큐에 삽입
    for (int i = 0; i < M; i++) {
        if (!lines[i].empty()) {
            pq.push(lines[i].front());
            lines[i].pop();
        }
    }

    int count = 0;
    while (!pq.empty()) {
        Employee current = pq.top();
        pq.pop();
        
        if (current.idx == decaLine && decaPos == 0) {
            cout << count << "\n";
            return 0;
        }

        count++;

        // 현재 사람이 나갔으니 데카의 줄에서 앞으로 한 칸 당겨짐
        if (current.idx == decaLine) {
            decaPos--;
        }

        // 현재 줄에 사람이 더 있으면 새로운 선두를 큐에 추가
        if (!lines[current.idx].empty()) {
            pq.push(lines[current.idx].front());
            lines[current.idx].pop();
        }
    }

    return 0;
}
