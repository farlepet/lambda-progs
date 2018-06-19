void causePageFault(int n) {
    if(n <= 0) {
        *(char *)0x00000000 = 1;
    } else {
        causePageFault(n-1);
    }
}

void func3() {
    causePageFault(4);
}

void func2() {
    func3();
}

void func1() {
    func2();
}

int main() {
    func1();

    return 0;
}
