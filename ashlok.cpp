#include<bits/stdc++.h>
using namespace std;
class Life {
public:
    Life(const std::string& message) {
        std::cout << message << std::endl;
    }
};

int main() {
    std::string messages[] = {
        "Life is full of Hard Working",
        "You must never give up",
        "Fight till your last breadth",
        "Always ask youself why you start this",
        "made mistakes but always tend to learn something."
    };

    int numMessages = sizeof(messages) / sizeof(messages[0]);

    while (true) {
        for (int i = 0; i < numMessages; ++i) {
            Life life(messages[i]);
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
    }

    return 0;
}
