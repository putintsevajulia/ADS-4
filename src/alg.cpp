// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;
    while (left < right) {
        if (arr[left] + arr[right] == value) {
            count++;
            while (left < right && arr[left] == arr[left + 1]) {
                left++;
            }
            while (left < right && arr[right] == arr[right - 1]) {
                right--;
            }
            left++;
            right--;
        } else if (arr[left] + arr[right] < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        int need = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == need) {
                ++count;
                break;
            } else if (arr[mid] < need) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return count;
}
