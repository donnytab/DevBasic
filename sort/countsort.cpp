class Solution
{
public:
    void coutSort(int* data, int length)
    {
        if (data == nullptr || length <= 0)
            return;

        //确定数列最大值
        int max = data[0];
        for (int i = 1; i < length; ++i)
        {
            if (data[i] > max)
                max = data[i];
        }

        // 确定统计数组长度并进行初始化
        int* coutData = new int[max + 1];
        for (int i = 0; i <= max; ++i)
            coutData[i] = 0;
        // 遍历数组，统计每个数出现的次数
        for (int i = 0; i < length; ++i)
            ++coutData[data[i]];
        // 排序数组，某个数出现了几次，便在data里累计输出几次
        int index = 0;
        for (int i = 0; i <= max; ++i)
        {
            for (int j = 0; j < coutData[i]; ++j)
            {
                data[index++] = i;
            }
        }
    }
};
