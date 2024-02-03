#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int min_energy(const std::string& s, char c = 'a') {
    if (s.length() == 1) {
        return (s[0] == c) ? 0 : 1;
    }

    int mid = s.length() / 2;
    int left_count = std::count(s.begin(), s.begin() + mid, c);
    int right_count = std::count(s.begin() + mid, s.end(), c);

    return std::min(mid - left_count + min_energy(s.substr(mid), static_cast<char>(c + 1)),
                    mid - right_count + min_energy(s.substr(0, mid), static_cast<char>(c + 1)));
}

int main() {
    int no;
    std::cin >> no;

    std::vector<int> l;
    for (int i = 0; i < no; i++) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        int energy = min_energy(s);
        l.push_back((energy <= n) ? energy : -1);
    }

    for (int energy : l) {
        std::cout << energy << std::endl;
    }

    return 0;
}