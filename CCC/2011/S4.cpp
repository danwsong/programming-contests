#include <bits/stdc++.h>

using namespace std;

int main() {
    int blood[8], patients[8];
    for (int i = 0; i < 8; i++)
        cin >> blood[i];
    for (int i = 0; i < 8; i++)
        cin >> patients[i];

    int maxPatients = 0, p;
    
    // O negative
    p = min(blood[0], patients[0]);
    maxPatients += p;
    blood[0] -= p;
    patients[0] -= p;
    
    // O positive
    p = min(blood[1], patients[1]);
    maxPatients += p;
    blood[1] -= p;
    patients[1] -= p;
    p = min(blood[0], patients[1]);
    maxPatients += p;
    blood[0] -= p;
    patients[1] -= p;
    
    // A negative
    p = min(blood[2], patients[2]);
    maxPatients += p;
    blood[2] -= p;
    patients[2] -= p;
    p = min(blood[0], patients[2]);
    maxPatients += p;
    blood[0] -= p;
    patients[2] -= p;
    
    // A positive
    p = min(blood[3], patients[3]);
    maxPatients += p;
    blood[3] -= p;
    patients[3] -= p;
    p = min(blood[2], patients[3]);
    maxPatients += p;
    blood[2] -= p;
    patients[3] -= p;
    p = min(blood[1], patients[3]);
    maxPatients += p;
    blood[1] -= p;
    patients[3] -= p;
    p = min(blood[0], patients[3]);
    maxPatients += p;
    blood[0] -= p;
    patients[3] -= p;
    
    // B negative
    p = min(blood[4], patients[4]);
    maxPatients += p;
    blood[4] -= p;
    patients[4] -= p;
    p = min(blood[0], patients[4]);
    maxPatients += p;
    blood[0] -= p;
    patients[4] -= p;
    
    // B positive
    p = min(blood[5], patients[5]);
    maxPatients += p;
    blood[5] -= p;
    patients[5] -= p;
    p = min(blood[4], patients[5]);
    maxPatients += p;
    blood[4] -= p;
    patients[5] -= p;
    p = min(blood[1], patients[5]);
    maxPatients += p;
    blood[1] -= p;
    patients[5] -= p;
    p = min(blood[0], patients[5]);
    maxPatients += p;
    blood[0] -= p;
    patients[5] -= p;
    
    // AB negative
    p = min(blood[6], patients[6]);
    maxPatients += p;
    blood[6] -= p;
    patients[6] -= p;
    p = min(blood[4], patients[6]);
    maxPatients += p;
    blood[4] -= p;
    patients[6] -= p;
    p = min(blood[2], patients[6]);
    maxPatients += p;
    blood[2] -= p;
    patients[6] -= p;
    p = min(blood[0], patients[6]);
    maxPatients += p;
    blood[0] -= p;
    patients[6] -= p;
    
    // AB positive
    p = min(blood[7], patients[7]);
    maxPatients += p;
    blood[7] -= p;
    patients[7] -= p;
    p = min(blood[6], patients[7]);
    maxPatients += p;
    blood[6] -= p;
    patients[7] -= p;
    p = min(blood[5], patients[7]);
    maxPatients += p;
    blood[5] -= p;
    patients[7] -= p;
    p = min(blood[4], patients[7]);
    maxPatients += p;
    blood[4] -= p;
    patients[7] -= p;
    p = min(blood[3], patients[7]);
    maxPatients += p;
    blood[3] -= p;
    patients[7] -= p;
    p = min(blood[2], patients[7]);
    maxPatients += p;
    blood[2] -= p;
    patients[7] -= p;
    p = min(blood[1], patients[7]);
    maxPatients += p;
    blood[1] -= p;
    patients[7] -= p;
    p = min(blood[0], patients[7]);
    maxPatients += p;
    blood[0] -= p;
    patients[7] -= p;
    
    cout << maxPatients << endl;
    
    return 0;
}
