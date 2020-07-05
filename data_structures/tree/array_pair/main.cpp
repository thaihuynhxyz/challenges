#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
long solve(vector<int> &arr) {
  if (arr.size() < 2) return 0;

  // Max
  auto mid_index = arr.size() / 2;
  auto max_index = mid_index;
  auto max_value = arr[mid_index];
  for (auto i = 1, sign = 1; i < arr.size() + 1; i++, sign *= -1) {
    auto index = mid_index + sign * i / 2;
    if (max_value < arr[index]) {
      max_index = index;
      max_value = arr[max_index];
    }
  }

  // Split
  auto left_size = max_index == 0 ? 1 : max_index;
  vector<int> left(arr.begin(), arr.begin() + left_size);
  vector<int> right(arr.begin() + left_size, arr.end());
  long count = solve(left) + solve(right);

  // Merge
  for (auto i = 0, l = 0, r = 0; l < left.size() || r < right.size(); i++) {
    if (l < left.size() && (left[l] <= right[r] || r == right.size())) {
      auto left_value = left[l++];
      arr[i] = left_value;
    } else {
      arr[i] = right[r++];
    }
  }

  // Ignore
  auto it1_start = -1;
  auto it1_end = -1;
  for (auto i = 0; i < left.size(); i++) {
    auto left_value = left[i];
    if (left_value == 1) {
      count += right.size();
      if (it1_start == -1) it1_start = i;
      it1_end = i + 1;
    } else if (left_value > 1) {
      break;
    }
  }
  if (it1_start != -1) left.erase(left.begin() + it1_start, left.begin() + it1_end);
  it1_start = -1;
  it1_end = -1;
  for (auto i = 0; i < right.size(); i++) {
    auto right_value = right[i];
    if (right_value == 1) {
      count += left.size();
      if (it1_start == -1) it1_start = i;
      it1_end = i + 1;
    } else if (right_value > 1) {
      break;
    }
  }
  if (it1_start != -1) right.erase(right.begin() + it1_start, right.begin() + it1_end);

  // Count
  for (auto left_value : left) {
    long l = 0;
    long r = (long) right.size() - 1;
    while (l <= r) {
      long m = l + (r - l) / 2;

      auto condition = (long) left_value * right[m] <= max_value;
      // Check if x is present at mid
      if (condition && (m == r || (long) left_value * right[m + 1] > max_value)) {
        count += (m + 1);
        break;
      }

      // If x greater, ignore left half
      if (condition)
        l = m + 1;

        // If x is smaller, ignore right half
      else
        r = m - 1;
    }
    if (l > r) return count;
  }
  return count;
}

int main() {
  int arr_count;
  cin >> arr_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split_string(arr_temp_temp);

  vector<int> arr(arr_count);

  for (int i = 0; i < arr_count; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  long result = solve(arr);

  cout << result << "\n";

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
    return x == y and x == ' ';
  });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
