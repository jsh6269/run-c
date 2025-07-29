#include <iostream>
#include <vector>

int* make_arr() {
    int arr[3] = {1, 2, 3};
    return arr;
}

int* make_arr_malloc() {
    int* arr = (int*)malloc(sizeof(int) * 3);
    *arr = 1;
    *(arr + 1) = 2;
    *(arr + 2) = 3;
    return arr;
}

int* make_arr_modern() {
    int* arr = new int[3]{1, 2, 3};
    return arr;
}

std::vector<int> make_vector() {
    std::vector<int> vec = {1, 2, 3};
    return vec;
}

int main() {
    // segmentation fault
    // make_arr 내부에서 생성된 arr 배열은 함수가 종료되면 메모리에서 해제됩니다.
    // 따라서 함수가 종료된 이후에 make_arr가 반환한 주소를 접근하면 원하는 값을 찾을 수 없습니다.
    // int* arr_ptr = make_arr();
    // std::cout << *arr_ptr << std::endl;

    // malloc을 통해 메모리를 할당 받고 그 주소를 반환 받는 방식을 사용하면,
    // 함수가 종료된 이후에도 해당 주소가 가리키는 값은 존재합니다.
    int* arr_ptr_malloc = make_arr_malloc();
    for(int i = 0; i < 3; i++) {
        std::cout << *(arr_ptr_malloc + i) << " ";
    }
    std::cout << std::endl;
    
    // 근데 함수가 종료되어도 메모리에 남아있다면...
    // 누가 메모리에서 데이터를 해제할까요...
    // 메모리는 한정적이므로 까먹고 남겨두면 컴퓨터가 아파합니다.
    // 이제 arr_ptr_malloc에게 자유를 선사해줍시다.
    free(arr_ptr_malloc);

    int* arr_ptr_modern = make_arr_modern();
    for(int i = 0; i < 3; i++) {
        // 사실 *(arr_ptr_modern + i)는 arr_ptr_modern[i]와 동일합니다.
        std::cout << arr_ptr_modern[i] << " ";
    }
    std::cout << std::endl;

    // 자유를 찾아 떠나는 메모리
    delete[] arr_ptr_modern;

    // 사실 벡터를 쓰면 마음이 편해집니다.
    // 얘는 스코프를 벗어나면 (정확히는 소임을 다하면) 알아서 자유를 찾아 떠납니다.
    std::vector<int> vec = make_vector();
    for(int val : vec) {
        std::cout << val << " ";
    }
    return 0;
}
