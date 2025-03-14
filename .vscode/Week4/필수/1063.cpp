#include <iostream>
#include <string>
#include <map>

using namespace std;

// 체스판에서 이동 방향을 정의
map<string, pair<int, int>> moves = {
    {"R", {0, 1}}, {"L", {0, -1}}, {"B", {-1, 0}}, {"T", {1, 0}},
    {"RT", {1, 1}}, {"LT", {1, -1}}, {"RB", {-1, 1}}, {"LB", {-1, -1}}
};

// 좌표 변환 함수
pair<int, int> toPosition(string pos) {
    return {pos[1] - '1', pos[0] - 'A'};
}

// 체스판 좌표를 문자열로 변환하는 함수
string toChessNotation(pair<int, int> pos) {
    return string(1, 'A' + pos.second) + to_string(pos.first + 1);
}

// 주어진 위치가 체스판 안에 있는지 확인
bool isInside(pair<int, int> pos) {
    return pos.first >= 0 && pos.first < 8 && pos.second >= 0 && pos.second < 8;
}

int main() {
    string kingPos, stonePos;
    int n;
    cin >> kingPos >> stonePos >> n;

    pair<int, int> king = toPosition(kingPos);
    pair<int, int> stone = toPosition(stonePos);

    for (int i = 0; i < n; i++) {
        string move;
        cin >> move;
        pair<int, int> nextKing = {king.first + moves[move].first, king.second + moves[move].second};

        // 킹이 이동할 위치가 체스판 안에 있는지 확인
        if (!isInside(nextKing)) continue;

        // 킹이 이동한 곳에 돌이 있을 경우 돌도 같은 방향으로 이동
        pair<int, int> nextStone = stone;
        if (nextKing == stone) {
            nextStone = {stone.first + moves[move].first, stone.second + moves[move].second};
            // 돌이 체스판 밖으로 나가면 이동하지 않음
            if (!isInside(nextStone)) continue;
        }

        // 이동 반영
        king = nextKing;
        stone = nextStone;
    }

    cout << toChessNotation(king) << "\n";
    cout << toChessNotation(stone) << "\n";
    return 0;
}
