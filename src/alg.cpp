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
int countPairs(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                counter++;
            }
        }
    }
    return counter;
}

int countPairs3(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len - 1; ++i) {
        int targ = value - arr[i];
        int left = i + 1, right = len - 1;

        int low = len;
        int high = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == targ) {
                low = mid;
                right = mid - 1;
            } else if (arr[mid] < targ) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        left = i + 1;
        right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2; 
            if (arr[mid] == targ) {
                high = mid;
                left = mid + 1;
            } else if (arr[mid] < targ) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (low <= high && low < len && high >= 0) {
            counter += (high - low + 1);
        }
    }
    return counter;
}
