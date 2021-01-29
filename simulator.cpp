#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {

    srand (static_cast <unsigned> (time(0)));

    int buckets[5] = {0};
    double probs[5] = {0.1, 0.2, 0.2, 0.2, 0.3};
    double prefs[5];
    double sum;

    prefs[0] = probs[0];
    for (int k = 1; k < 5; k++) { 
        prefs[k] = prefs[k-1] + probs[k];
    }

    for (int i = 0; i < 100000; i++) {
        double r = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
        for (int j = 0; j < 5; j++) {
            if (r <= prefs[j]) {
                buckets[j]++;
                for (int k = 0; k < 5; k++) { 
                    probs[k] *= 6;
                }
                probs[j] /= 36;

                prefs[0] = probs[0];
                for (int k = 1; k < 5; k++) { 
                    prefs[k] = prefs[k-1] + probs[k];
                }

                for (int k = 0; k < 5; k++) { 
                    probs[k] /= prefs[4];
                    prefs[k] /= prefs[4];
                }
                break;
            }
        }
    }

    for (int k = 0; k < 5; k++) { 
        cout << buckets[k] << endl;
    }
}
