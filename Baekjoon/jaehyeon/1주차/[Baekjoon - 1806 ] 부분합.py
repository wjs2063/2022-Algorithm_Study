#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Sep  4 21:04:58 2022

@author: pn_jh
"""

import sys
input = sys.stdin.readline
n, s = map(int,input().split())
arr =[0] + list(map(int,input().split()))]

for i in range(1,len(arr)):
    arr[i] += arr[i - 1]

l, r = 0,1
# arr[r] - arr[l] 의 의미 l + 1 부터 arr[r] 까지의 부분합
answer = float('inf')

for i in range(len(arr)):
    
    while r < len(arr) - 1 and arr[r] - arr[i] < s:
        r += 1
    if arr[r] - arr[i] >= s:
        answer = min(answer,r - i)
if answer == float('inf'):
    print(0)
else:
    print(answer)
    