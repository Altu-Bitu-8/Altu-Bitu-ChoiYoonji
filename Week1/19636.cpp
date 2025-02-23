#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int initial_weight, initial_BMR, threshold;
    int days, daily_intake, daily_activity;
    // 입력 받기
    cin >> initial_weight >> initial_BMR >> threshold;
    cin >> days >> daily_intake >> daily_activity;
    // 기초 대사량 변화 고려 X
    int weight_no_BMR_change = initial_weight;
    int constant_BMR = initial_BMR;
    // 기초 대사량 변화 고려 O
    int weight_with_BMR_change = initial_weight;
    int variable_BMR = initial_BMR;
    // 체중 변화 시뮬레이션
    for (int i = 0; i < days; i++) {
        int daily_consumption_no_change = constant_BMR + daily_activity;
        int daily_consumption_with_change = variable_BMR + daily_activity;
        weight_no_BMR_change += daily_intake - daily_consumption_no_change;
        weight_with_BMR_change += daily_intake - daily_consumption_with_change;
        // 기초 대사량 변화 적용 (체중 변화 후 계산)
        int energy_gap = daily_intake - daily_consumption_with_change;
        if (abs(energy_gap) > threshold) {
            variable_BMR += floor(energy_gap / 2.0);
        }
    }
    // 기초 대사량 변화 X 결과 출력
    if (weight_no_BMR_change <= 0) {
        cout << "Danger Diet\n";
    } else {
        cout << weight_no_BMR_change << " " << constant_BMR << "\n";
    }
    // 기초 대사량 변화 O 결과 출력
    if (weight_with_BMR_change <= 0 || variable_BMR <= 0) {
        cout << "Danger Diet\n";
    } else {
        cout << weight_with_BMR_change << " " << variable_BMR << " ";
        if (constant_BMR > variable_BMR) {  // 기초 대사량 감소 여부로 요요 판별
            cout << "YOYO";
        } else {
            cout << "NO";
        }
    }
    return 0;
}