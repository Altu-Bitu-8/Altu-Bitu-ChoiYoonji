#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int T;  // 테스트 케이스 수
    cin >> T;
    while (T--) {
        int N;  // 지원자 수
        cin >> N;
        vector<pair<int, int>> applicants(N);
        // 지원자의 서류 성적과 면접 성적 입력
        for (int i = 0; i < N; ++i) {
            cin >> applicants[i].first >> applicants[i].second;
        }
        // 서류 성적을 기준으로 정렬
        sort(applicants.begin(), applicants.end());
        int count = 0;
        int max_interview_rank = N + 1;  // 면접 성적의 최댓값보다 큰 초기값
        // 면접 성적을 기준으로 선발
        for (int i = 0; i < N; ++i) {
            if (applicants[i].second < max_interview_rank) {
                count++;
                max_interview_rank = applicants[i].second;
            }
        }
        // 결과 출력
        cout << count << endl;
    }
    return 0;
}