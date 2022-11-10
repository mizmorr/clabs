#include <iostream>
#include <vector>
#include <set>
#include <string.h>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

vector<set<int>> firm;
vector<set<int>> conflicts;
vector<vector<pair<int, string>>> ash;
vector<vector<pair<int, string>>> ach;

bool IsContain(set<int>& s, int elt) {
    return (find(s.begin(), s.end(), elt) != s.end());
}

vector<string> split(string line) {
    vector<string> result = vector<string>();

    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            result.push_back(line.substr(0, i));
            vector<string> tail = split(line.substr(i + 1, line.size() - i - 1));
            result.insert(result.end(), tail.begin(), tail.end());
            break;
        }
    }

    if (result.size() == 0) {
        result.insert(result.begin(), line);
    }

    return result;
}

int getFirm(int forObject) {
    for (int i = 0; i < firm.size(); i++) {
        if (IsContain(firm[i], forObject)) {
            return i;
        }
    }
    return -1;
}

int getInterestGroup(int forObject) {
    int firm = getFirm(forObject);

    for (int i = 0; i < conflicts.size(); i++) {
        if (IsContain(conflicts[i], firm)) {
            return i;
        }
    }

    return -1;
};

void printFirmObjects(int firmIndex) {
    for (set<int>::iterator i = firm[firmIndex].begin(); i != firm[firmIndex].end(); i++) {
        cout << *i << ", ";
        i++;
    }
    cout << endl;
}

void printReportForSubject(int subjectIndex) {
    for (int i = 0; i < ash[subjectIndex].size(); i++) {
        cout << "access " << ash[subjectIndex][i].second << " with object " << ash[subjectIndex][i].first << " in firm " << getFirm(ash[subjectIndex][i].first);
    }
}

void printReportForObject(int objectIndex) {
    for (int i = 0; i < ach[objectIndex].size(); i++) {
        cout << "access " << ach[objectIndex][i].second << " with object " << ach[objectIndex][i].first << " in firm " << getFirm(ach[objectIndex][i].first);
    }
}

bool canRead(int subjectIndex, int objectIndex) {
    int interestGroup = getInterestGroup(objectIndex);
    int objectFirm = getFirm(objectIndex);

    set<int> accessGroups = set<int>();
    set<int> firmGroups = set<int>();

    for (int i = 0; i < ash[subjectIndex].size(); i++) {
        accessGroups.insert(getInterestGroup(ash[subjectIndex][i].first));
        firmGroups.insert(getFirm(ash[subjectIndex][i].first));
    }

    return !IsContain(accessGroups, interestGroup) || IsContain(firmGroups, objectFirm);
}

bool canWrite(int subjectIndex, int objectIndex) {
    int objectFirm = getFirm(objectIndex);
    int objectInterest = getInterestGroup(objectIndex);
    bool isReadFromAnoutherFirm = false;

    set<int> readedfirm = set<int>();

    for (int i = 0; i < ash[subjectIndex].size(); i++) {
        if (ash[subjectIndex][i].second == "r" &&
            getFirm(ash[subjectIndex][i].first) != objectFirm &&
            getInterestGroup(ash[subjectIndex][i].first) == objectInterest) {
            isReadFromAnoutherFirm = true;
            break;
        }
    }

    return canRead(subjectIndex, objectIndex) && !isReadFromAnoutherFirm;
}

void read(int subjectIndex, int objectIndex) {
    if (canRead(subjectIndex, objectIndex)) {
        ash[subjectIndex].push_back(pair<int, string>(objectIndex, "r"));
        ach[objectIndex].push_back(pair<int, string>(subjectIndex, "r"));
        cout << "accepted" << endl;
    }
    else {
        cout << "refused" << endl;
    }
}

void write(int subjectIndex, int objectIndex) {
    if (canWrite(subjectIndex, objectIndex)) {
        ash[subjectIndex].push_back(pair<int, string>(objectIndex, "w"));
        ach[objectIndex].push_back(pair<int, string>(subjectIndex, "w"));
        cout << "accepted" << endl;
    }
    else {
        cout << "refused" << endl;
    }
}

void setUpChinaWall(int objCount, int subjCount, int firmCount, int interCount) {
    firm = vector<set<int>>(firmCount, set<int>());
    conflicts = vector<set<int>>(interCount, set<int>());

    ash = vector<vector<pair<int, string>>>(subjCount);
    ach = vector<vector<pair<int, string>>>(objCount);
}

void doCommand(string command) {
    vector<string> words = split(command);

    if (words[0] == "start") {
        ash = vector<vector<pair<int, string>>>(ash.size());
        ach = vector<vector<pair<int, string>>>(ach.size());
    }
    else if (words[0] == "read") {
        int subjectIndex = stoi(words[1]);
        int objectIndex = stoi(words[2]);
        read(subjectIndex, objectIndex);
    }
    else if (words[0] == "write") {
        int subjectIndex = stoi(words[1]);
        int objectIndex = stoi(words[2]);
        write(subjectIndex, objectIndex);
    }
    else if (words[0] == "report_subject") {
        int subjectIndex = stoi(words[1]);
        printReportForSubject(subjectIndex);
    }
    else if (words[0] == "report_object") {
        int objectIndex = stoi(words[1]);
        printReportForObject(objectIndex);
    }
    else if (words[0] == "brief_case") {
        int firmIndex = stoi(words[1]);
        printFirmObjects(firmIndex);
    }
    else {
        cout << "invalid command" << endl;
    }

    cout << endl;
}

int main() {
    // 0 - 0 
    // 1 - 1, 2, 3
    // 2 - 4, 5 
    
    // 0 - 0, 1
    // 1 - 2
    setUpChinaWall(6, 1, 4, 2);

    firm[1].insert(1);
    firm[1].insert(2);
    firm[2].insert(4);

    firm[2].insert(5);
    firm[3].insert(6);

    firm[3].insert(7);

    conflicts[0].insert(1);
    conflicts[0].insert(3);

    conflicts[1].insert(2);

    //// reading test
    //cout << "test 1:" << endl;
    //"read 0 0" // ok
    //"read 0 3" // ошибка - объект в другой фирме и в том же конфликте интересов
    //"read 0 5" // ок - объект из другого конфликта интересов

    //cout << "test 2:" << endl;
    //"start"
    //"read 0 3" // ок
    //"read 0 4" // ок - тот же конфликт интересов, но та же фирма

    //cout << "test 3:" << endl;
    //"start"
    //"write 0 0" // ок
    //"write 0 1" // ок - объект в той же фирме
    //"write 0 3" // ошибка - объект в другой фирме и в том же конфликте интересов
    //"write 0 5" // ок - объект в другой фирме, но в другом конфликте интересов
    while (true) {
        string s;
        cin >> s;
        int i, j;
        cin >> i >> j;
        if (s == "read") {
            doCommand("read " + to_string(i) + ' ' + to_string(j));
        }
        else {
            doCommand("write " + to_string(i) + ' ' + to_string(j));
        }
    }
}