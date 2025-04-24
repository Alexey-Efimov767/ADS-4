// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = *arr; i < len - 1; i++) {
    for (int j = 1; j < len - 1; j++) {
        if (arr[i] + arr[j] == value) {
            counter++;
        }
    }
  }
  return counter;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
    int pos = len;
    for (int i = 0; i < len; ++i) {
        if (arr[i] > value) {
            pos = i;
            break;
        }
    }
    for (int i = 0; i < pos; ++i) {
        for (int j = i + 1; j < pos; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (arr[i] > value)
            break;

        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        int first = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                first = mid;
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (first != -1) {
            int last = first;
            while (last + 1 < len && arr[last + 1] == target)
                ++last;
            count += (last - first + 1);
        }
    }
    return count;
}
