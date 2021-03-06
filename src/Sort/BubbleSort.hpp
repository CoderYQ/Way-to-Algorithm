﻿// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once
#include <utility>


/**
 * @brief BubbleSort 冒泡排序
 * @param s[MAX]    无序序列
 * @param beg       序列s的起始下标
 * @param end       序列s是左闭右开区间[beg, end)
 */

void BubbleSort(int *s, int beg, int end) {
  for (int i = end-1; i >= beg; --i)
    for (int j = beg; j < i; ++j)
      if (s[j] > s[j+1])
        std::swap(s[j], s[j+1]);
}
