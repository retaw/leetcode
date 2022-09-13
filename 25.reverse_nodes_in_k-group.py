from typing import List,Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if k <= 1 or not head:
            return head

        #把lastTail后面的s个点逆序, 返回逆序部分的最后一个
        def reverse(lastTail: Optional[ListNode], curK: int) -> Optional[ListNode]:
            tail = lastTail.next
            if curK < 2 or not tail:
                return tail

            head = lastTail

            c = 1
            n = tail.next
            while n:
                tail.next = n.next
                n.next    = head.next
                head.next = n
                n = tail.next

                c += 1
                if c == curK:
                    return tail

            if c < curK:
                return reverse(lastTail, c)
            return tail

        extraHead = ListNode(None, head)
        lastTail = extraHead
        while lastTail.next:
            lastTail = reverse(lastTail, k)
        
        return extraHead.next

if __name__ == "__main__":
    def makeList(l: List):
        if l == None or len(l) == 0:
            return None

        ret = ListNode(None, None)
        tail = ret
        for v in l:
            tail.next = ListNode(v)
            tail = tail.next
        return ret.next

    def convertList(ln):
        n = ln
        ret = []
        while n is not None:
            ret.append(n.val)
            n = n.next
        return ret

    def printList(ln):
        print(convertList(ln))

    l = [1 ,2]
    k = 2
    l = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    l = [1, 2, 3, 4, 5]
    k = 3
    s = Solution()
    bl = s.reverseKGroup(makeList(l), k)
    printList(bl)

