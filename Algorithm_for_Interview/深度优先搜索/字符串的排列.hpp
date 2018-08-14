/*
字符串的排列 https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
    输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
    输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

时间限制：1秒 空间限制：32768K 热度指数：180797
本题知识点： 字符串

解题思路：
    DFS 找出所有排列
    排序

提交记录：

*/
#pragma once

#include "../all.h"

class Solution {
    string s;
    string tmp;
    int strlen;
    vector<string> ret;
    vector<int> book;

    void dfs(int step) {
        if (step == strlen) {
            ret.push_back(tmp);
            return;
        }
        for (int i = 0; i<strlen; i++) {
            if (book[i] != 1) {
                tmp[step] = s[i];
                book[i] = 1;
                dfs(step + 1);
                book[i] = 0;
            }

        }
    }

public:
    vector<string> Permutation(string str) {
        s = str;
        strlen = str.length();
        tmp.resize(strlen, '\0');
        book.resize(strlen, 0);
        dfs(0);
        return ret;
    }

};

void solve() {
    Solution().Permutation("abc");
}