#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tạo mảng tạm thời
    std::vector<int> leftArr(n1), rightArr(n2);

    // Sao chép dữ liệu vào mảng tạm thời
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Trộn hai mảng tạm thời vào mảng chính arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của leftArr[], nếu có
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của rightArr[], nếu có
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Tìm điểm giữa mảng
        int mid = left + (right - left) / 2;

        // Gọi đệ quy để sắp xếp từng nửa
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Trộn hai nửa đã sắp xếp
        merge(arr, left, mid, right);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
