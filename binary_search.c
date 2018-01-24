// binary search là tên một thuật toán, mà input của nó là một list các phần tử đã được sắp xếp. Nó sẽ trả về vị trí của phần tử bạn đang tìm kiếm nếu có trong list và null nếu không.

// với binary search trường hợp xấu nhất để tìm ra một phần tử trong một list có n phần tử là log 2 của n (bước)

// log là phép tính ngược của lũy thừa ví dụ 10 mũ 2 bằng 100 => log 10 của 100 bằng 2

#include <stdio.h>

int main() {
    int items[] = {1, 3, 5, 7, 9};
    int size = (int)sizeof(items) / sizeof(int);
    int position = binary_search(items, size, 7);
    printf("%d\n", position);
    return 0;
}

int binary_search(int items[], int items_size, int item) {
    int low = 0;
    int high = items_size - 1;
    int mid, guess;
    while (low <= high)
    {
        mid = (low + high) / 2;
        guess = items[mid];
        if (guess == item)
        {
            return mid;
        }
        if (guess > item) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
};
