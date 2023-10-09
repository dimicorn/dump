#include <iostream>
struct StrangeMatrix {
    int first_line[3];
    int second_line[3];
    int third_line[3];
};
StrangeMatrix transpose(StrangeMatrix m){
    StrangeMatrix n;
    n.first_line[0] = m.first_line[0];
    n.first_line[1] = m.second_line[0];
    n.first_line[2] = m.third_line[0];
    n.second_line[0] = m.first_line[1];
    n.second_line[1] = m.second_line[1];
    n.second_line[2] = m.third_line[1];
    n.third_line[0] = m.first_line[2];
    n.third_line[1] = m.second_line[2];
    n.third_line[2] = m.third_line[2];
    return n;
}
int main() {
    return 0;
}
