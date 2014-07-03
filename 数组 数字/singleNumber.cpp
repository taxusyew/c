// 放在find1in3.cpp中，替换int find1in3(int * a, int len)函数
// 摘自http://www.cnblogs.com/wei-li/p/SingleNumberII.html
// 真正按位算，O(n)

// ones&t 保留t中已经在其他数字中出现一次的bit，也就是两次
// twos |= 保存这些bit
// ones ^= t 新出现的bit保留，已经出现过的第二次bit，也先期保留在twos里了
// ones & twos 同时出现的是三次
// ~threes 三次取反，留空白
// ones &= 用三次的空白擦除一次中重负的bit
// twos &= 擦除两次中重复的

int singleNumber(int A[], int n) {
    int ones = 0;//记录只出现过1次的bits
    int twos = 0;//记录只出现过2次的bits
    int threes;
    for(int i = 0; i < n; i++){
        int t = A[i];
        twos |= ones&t;//要在更新ones前面更新twos
        ones ^= t;
        threes = ones&twos;//ones和twos中都为1即出现了3次
        ones &= ~threes;//抹去出现了3次的bits
        twos &= ~threes;
    }
    return ones;
}
