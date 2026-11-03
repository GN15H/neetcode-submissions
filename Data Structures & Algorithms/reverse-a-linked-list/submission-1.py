# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return None
        new_node: Optional[ListNode] = None 
        node = head
        while node.next != None:
            tmp_node = ListNode(node.val, new_node)
            new_node = tmp_node
            node = node.next
        new_node = ListNode(node.val, new_node)
        
        return new_node


                