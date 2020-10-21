class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return None
        ll = []
        temp = head
        while temp.next:
            ll.append(temp)
            temp = temp.next
        ll.append(temp)
        n = len(ll)
        head_index = n-k % n
        ll = ll[head_index:]+ll[:head_index]
        ll[-1].next = None
        for i in range(n-1):
            if ll[i+1] == head:
                ll[i].next = head
        return ll[0]
