#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 톱니바퀴를 한 칸 회전시키는 함수
// direction이 1이면 시계 방향, -1이면 반시계 방향으로 회전
string rotateGear(const string &gear, int direction) {
    string rotated = gear;
    if(direction == 1) {
        // 시계 방향: 마지막 문자를 앞으로 이동
        rotated = gear.back() + gear.substr(0, gear.size()-1);
    } else if(direction == -1) {
        // 반시계 방향: 첫 문자를 뒤로 이동
        rotated = gear.substr(1) + gear.front();
    }
    return rotated;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<string> gears(T);
    // 톱니바퀴 상태 입력 (각 톱니바퀴는 8자리 문자열)
    for (int i = 0; i < T; i++){
        cin >> gears[i];
    }
    
    int K;
    cin >> K;
    // K번의 회전 명령 처리
    for (int k = 0; k < K; k++){
        int gearNum, dir;
        cin >> gearNum >> dir;
        // gearNum은 1번부터 시작하므로 인덱스 0부터 시작하도록 조정
        gearNum -= 1;
        
        // 각 톱니바퀴가 회전하는 방향을 저장하는 배열 (0이면 회전 없음)
        vector<int> rotate(T, 0);
        rotate[gearNum] = dir;
        
        // 왼쪽 톱니바퀴에 대해 회전 전파
        for (int i = gearNum - 1; i >= 0; i--){
            // 현재 톱니바퀴(i)와 오른쪽 톱니바퀴(i+1)의 맞닿은 극을 확인
            // 맞닿은 부분: i번 톱니바퀴의 2번 인덱스와 (i+1)번의 6번 인덱스
            if (rotate[i+1] != 0 && gears[i][2] != gears[i+1][6])
                rotate[i] = -rotate[i+1]; // 반대 방향으로 회전
            else
                break; // 같은 극이면 더 이상 회전 전파 없음
        }
        
        // 오른쪽 톱니바퀴에 대해 회전 전파
        for (int i = gearNum + 1; i < T; i++){
            // 맞닿은 부분: (i-1)번 톱니바퀴의 2번 인덱스와 i번의 6번 인덱스
            if (rotate[i-1] != 0 && gears[i-1][2] != gears[i][6])
                rotate[i] = -rotate[i-1];
            else
                break;
        }
        
        // 모든 톱니바퀴에 대해 결정된 회전 방향으로 회전시킴
        for (int i = 0; i < T; i++){
            if (rotate[i] != 0)
                gears[i] = rotateGear(gears[i], rotate[i]);
        }
    }
    
    // 12시 방향 (인덱스 0)이 S극(1)인 톱니바퀴 개수를 센다.
    int countS = 0;
    for (int i = 0; i < T; i++){
        if (gears[i][0] == '1') countS++;
    }
    
    cout << countS << "\n";
    
    return 0;
}
