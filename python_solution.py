"""
leet code solutions

By Xuan Liu
"""
import math

#Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

        
class Solution:        
    # problem 1
    def twoSum(num, target):
        store = {}
        for i in range(0,len(num)):
            diff = target - num[i]
            if diff in store.values():
                diff_index = [key for (key,value) in store.items() if value == diff][0]
                return (diff_index + 1, i+1)
            else:
                store[i] = num[i]
   
    # Problem 2
    # @return a float
    def findKth(self, A, B, k):
        """
        Find the kth smallest of two sorted arrays, lenA < lenB
        """
        lenA = len(A)
        lenB = len(B)
        if lenA == 0:
            return B[k-1]
        if k > (lenA + lenB):
            raise ValueError("K is too large")
        if lenA > lenB:
            return self.findKth(B, A, k)
        if k == 1:
            return min(A[0], B[0])

        r = k/2
        takeA = min(r, lenA)
        takeB = k - takeA
        if A[takeA-1] > B[takeB-1]:
            return self.findKth(A, B[takeB:], takeA)
        else:
            return self.findKth(A[takeA:], B, takeB)

    def findMedianSortedArrays(self, A, B):
        """
        Find the median of the two sorted arrays
        """
        lenA = len(A)
        lenB = len(B)
        if (lenA + lenB) % 2 == 1:
            k = (lenA + lenB)/2
            return self.findKth(A, B, k+1)
        else:
            k = (lenA + lenB)/2
            return (self.findKth(A,B,k) + self.findKth(A,B,k+1))/float(2)

# Problem 3

    def lengthOfLongestSubstring(self, s):
        """
        Longest substring without repeating characters
        Idea: use the hashmap to store the characters, and each character is 
        the key, and the associated position is the corresponding value. 
        Use two pointers, one points to the last position, and the other 
        pointer iterates along the string. When find a repeated string, move
        the last position pointer to the next char of the repeated char, and 
        all char appeared before the repeated char needs to be ignored.
        
        more example: http://fisherlei.blogspot.com/2012/12/leetcode-longest-substring-without.html
        """
        if len(s) <=1:
            return len(s)
        cache = {}
        #substr = ''
        lastpos = 0
        length = 0 
        for i in range(0, len(s)):
            if s[i] not in cache or cache[s[i]] < lastpos:
                cache[s[i]] = i
                if i == len(s)-1:
                    cache[s[i]] = i
                    length = max(length, i - lastpos + 1)
            else:
                length = max(length, i - lastpos)
                lastpos = cache[s[i]] + 1
                cache[s[i]] = i
        return length


    # problem 4
    """
    You are given two linked lists representing two non-negative numbers. 
    The digits are stored in reverse order and each of their nodes contain 
    a single digit. Add the two numbers and return it as a linked list.
    
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    """
    
    
    # problem 5
    """
    Given a string S, find the longest palindromic substring in S. 
    You may assume that the maximum length of S is 1000, 
    and there exists one unique longest palindromic substring.
    """
    def longestPalindrome(self, s):
        longest_str = ''
        longest = 0
        s_list_r= list(s)
        s_list_r.reverse()
        print s_list_r
        s_r = ''.join(s_list_r)
        for i in range(0,len(s)-1):
            for j in range(i+1, len(s)):
                if j == len(s)-1:
                    sub_str = s[i:]
                else:
                    sub_str = s[i:j]
                print sub_str
                if sub_str in s_r:
                    if longest < len(sub_str):
                        longest = len(sub_str)
                        longest_str = sub_str
        return longest_str

    # Probelm 20
    """
    Given a string containing just the characters 
    '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    The brackets must close in the correct order, "()" and "([])[]{}" are
    all valid but ")(]" and "([)]" are not.
    """
    def isValid(self, s):
        if len(s) % 2 == 1:
            return False
        stack = []
        for i in range(len(s)):
            if s[i] == "(" or s[i] == "[" or s[i] == "{":
                stack.append(s[i])
            if len(stack) != 0:
                if s[i] == ")" and stack[-1] == "(":
                    stack.pop()
                if s[i] == "]" and stack[-1] == "[":
                    stack.pop()
                if s[i] == "}" and stack[-1] == "{":
                    stack.pop()
            else:
                if s[i] in [")", "]", "}"]:
                    return False
        if len(stack) == 0:
            return True
        else:
            return False

    # Problem 38
    """
    The count-and-say sequence is the sequence of integers beginning as follows:
    1, 11, 21, 1211, 111221, ...
    
    1 is read off as "one 1" or 11.
    11 is read off as "two 1s" or 21.
    21 is read off as "one 2, then one 1" or 1211.
    Given an integer n, generate the nth sequence.
    
    Note: The sequence of integers will be represented as a string.
    """
    # @return a string
    def countAndSay(self, n):
        start = '1'
        item = start
        for i in range(1, n):
            temp = {}
            count = 0
            track = item[0]
            temp_str = ''
            #print item, track
            for letter in item:
                if letter == track:
                    count = count + 1
                else:
                    temp_str += str(count) + track
                    #print temp_str
                    track = letter
                    count = 1
            if count != 0:
                temp_str += str(count) + track
            item = temp_str
        
        return item



    # Problem 191
    """
    Write a function that takes an unsigned integer and returns the number of '1'
    bits it has (also known as the Hamming weight).
    
    For example, the 32-bit integer '11' has binary representation
    00000000000000000000000000001011, so the function should return 3.
    """
    # @param n, an integer
    # @return an integer
        
    def hammingWeight(self, n):
        count = 0
        while n != 0:
            count += n%2
            n = n/2
        return count

    # @param n, an integer
    # @return an integer

    def dec2bin(self, n):
        '''
        convert decimal number to binary, stored in the reverse way
        '''
        bin_str = ''
        while n != 0:
            r = n%2
            bin_str += str(r)
            n = n/2
        return bin_str
    def reverseBits(self, n):
        bin_str = self.dec2bin(n)
        num_zeros = 32 - len(bin_str)
        bin_str += "0"*num_zeros
        dec_sum = 0
        for i in range(len(bin_str)):
            power = 31 - i
            if int(bin_str[i]) != 0:
                dec_sum += pow(2,power)
        return dec_sum

def dryrun(n):
    """
    test
    """
    sol = Solution()
    #sol.countAndSay(n)
    #print sol.hammingWeight(n)
    print sol.dec2bin(n)
    print sol.reverseBits(n)





                               
    
