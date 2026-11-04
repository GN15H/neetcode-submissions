# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        node = head
        sz = 0
        while node != None:
            sz+=1
            node = node.next
        if sz == n: 
            return head.next
        print('el size',sz)
        node = head
        for i in range(sz-n-1):
            node = node.next
        node.next = node.next.next
        return head