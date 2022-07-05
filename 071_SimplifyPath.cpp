
#include <iostream>
#include <string>
#include <deque>

// 71. Simplify Path

using namespace std;

string simplifyPath(string path) {
    auto prev = 0;
    auto i = path.find("/", 1);

    std::deque<string> s{};
    while (prev != -1) {
        auto p = path.substr(prev, i - prev);
        if (p == "/..") {
            if (!s.empty())
                s.pop_front();
        }
        else if (p != "/." && p != "/")
            s.push_front(p);

        prev = i;
        i = path.find('/', i + 1);
    }

    string out;
    while (!s.empty()) {
        out.append(s.back());
        s.pop_back();
    }

    return (out.empty()) ? "/" : out;
}

int main()
{
    std::cout << simplifyPath("/home") << "\r\n";
    std::cout << simplifyPath("/home/") << "\r\n";
    std::cout << simplifyPath("/../") << "\r\n";
    std::cout << simplifyPath("/home//foo/") << "\r\n";
    std::cout << simplifyPath("/a/./b/../../c/") << "\r\n";
    std::cout << simplifyPath("/.") << "\r\n";
}

