#include <iostream>

void assign_without_pointer(int c) {
    c = c + 1;
}

void assign_with_pointer(int* c) {
    *c = *c + 1;
}

void assign_with_double_pointer(int** c) {
    **c = **c + 1;
}

void assign_with_hexa_pointer(int****** c) {
    // 와우... 정말 아름다운 별이네요...
    ******c = ******c + 1;
}

int main() {
    int a = 1;
    int* b = &a;
    std::cout << a << " " << *b << " " << b << std::endl; // 1 1 addr

    *b = 2;
    std::cout << a << " " << *b << " " << b << std::endl; // 2 2 addr

    assign_without_pointer(a);
    std::cout << a << " " << *b << std::endl; // 2 2

    assign_with_pointer(&a);
    std::cout << a << " " << *b << std::endl; // 3 3

    assign_with_pointer(b);
    std::cout << a << " " << *b << std::endl; // 4 4

    int** c = &b;
    assign_with_double_pointer(c);
    std::cout << a << " " << *b << " " << **c << std::endl; // 5 5 5

    assign_with_double_pointer(&b);
    std::cout << a << " " << *b << " " << **c << std::endl; // 6 6 6

    // 이중, 삼중, 사중, 그 이상도 다 가능합니다.
    int*** d = &c;
    int**** e = &d;
    int***** f = &e;
    assign_with_hexa_pointer(&f);
    std::cout << a << " " << *****f << std::endl; // 7 7

    int sample[5] = {1, 2, 3, 4, 5};

    // 배열 이름도 포인터에 주입할 수 있습니다.
    int* arr_ptr = sample;
    std::cout << *arr_ptr << " " << *(arr_ptr + 1) << " " << *(arr_ptr + 2) << " " << *(arr_ptr + 3) << " " << *(arr_ptr + 4) << std::endl;

    assign_with_pointer(sample);
    std::cout << sample[0] << " " << sample[1] << " " << sample[2] << " " << sample[3] << " " << sample[4] << std::endl;
    
    assign_with_pointer(sample+1);
    std::cout << sample[0] << " " << sample[1] << " " << sample[2] << " " << sample[3] << " " << sample[4] << std::endl;

    // + 1 연산이 정확히 1을 더해준다고 보기는 어렵습니다.
    // 실제로는 sizeof type 만큼 더해주어 의미론적으로 다음 위치를 향하게 만듭니다.
    assign_with_pointer((int *)(((char*)sample) + sizeof(int) * 2));
    std::cout << sample[0] << " " << sample[1] << " " << sample[2] << " " << sample[3] << " " << sample[4] << std::endl;

    // void*는 안전하지 않지만 문제없이 동작합니다.
    void* g = sample + 3;
    assign_with_pointer((int*)g);
    std::cout << sample[0] << " " << sample[1] << " " << sample[2] << " " << sample[3] << " " << sample[4] << std::endl;

    // 마지막 인덱스는 편하게 바꿔봅시다.
    sample[4] += 1;
    std::cout << sample[0] << " " << sample[1] << " " << sample[2] << " " << sample[3] << " " << sample[4] << std::endl;

    // iterator도 포인터입니다.
    for(int* it = std::begin(sample); it != std::end(sample); it++) {
        *it -= 1;
    }

    // 좀 더 편하게 순회도 가능합니다.
    for(int item : sample) {
        std::cout << item << " ";
    }
    return 0;
}
