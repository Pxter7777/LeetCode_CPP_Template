#include <iostream>
#include <string>
#include <vector>

struct TestCase
{
    std::vector<int> nums1;
    int m;
    std::vector<int> nums2;
    int n;
};

TestCase t1 = {
    {1, 2, 3, 0, 0, 0}, // nums1
    3,                  // m
    {2, 5, 6},          // nums2
    3                   // n
};

class Solution
{
  public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        if (m == 0)
        {
            nums1 = nums2;
            return;
        }
        nums1 = std::vector<int>(nums1.begin(), nums1.begin() + m);
        int i = 0, j = 0;
        while (i - j < m && j < n)
        {
            if (nums1[i] > nums2[j])
            {
                nums1.insert(nums1.begin() + i, nums2[j]);
                j++;
            }
            i++;
        }
        if (j < n)
        {
            nums1.insert(nums1.begin() + i, nums2.begin() + j, nums2.end());
        }
    }
    void test(TestCase &t)
    {
        merge(t.nums1, t.m, t.nums2, t.n);
        // Print result
        /*
        for (int num : t.nums1)
        {
            std::cout << num << " ";
        }
        */
        std::cout << std::endl;
    }
};

int main()
{
    Solution s;
    s.test(t1);
    return 0;
}
