#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    queue<int> q;
    
    // 1부터 N까지의 카드 번호를 큐에 삽입
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }
    
    // 카드가 한 장 남을 때까지 반복
    while (q.size() > 1) {
        q.pop(); // 제일 위의 카드 버리기
        q.push(q.front()); // 그 다음 카드를 아래로 옮기기
        q.pop();
    }
    
    // 마지막으로 남은 카드 출력
    cout << q.front() << "\n";
    return 0;
}
