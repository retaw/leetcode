from typing import List,Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if lists is None or len(lists) == 0:
            return None

        if len(lists) == 1:
            return lists[0]

        head = ListNode()
        def merge(l0, l1):
            t = head
            while l0 is not None and l1 is not None:
                if l0.val < l1.val:
                    t.next = l0
                    l0 = l0.next
                else:
                    t.next = l1
                    l1 = l1.next
                t = t.next

            if l0 is not None:
                t.next = l0
            else:
                t.next = l1

            return head.next
            

        a = lists
        b = []
        size = len(a)
        while size > 1:
            for i in range(0, size, 2):
                if i + 1 >= size:
                    b.append(a[i])
                else:
                    b.append(merge(a[i], a[i + 1]))
            a = b
            b = []
            size = len(a)

        return a[0]

class Solution_recursion:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if lists is None or len(lists) == 0:
            return None

        return self.halfMerge(lists, 0, len(lists))


    def halfMerge(self, lists: List[Optional[ListNode]], rf, rt) -> Optional[ListNode]:
    #    print("RR", convertMultiLists(lists), rf, rt)
        size =  rt - rf
        if size <= 0:
            return None

        if size == 1:
            return lists[rf]

        if size == 2:
            head = ListNode(None, None)
            t = head
            l0 = lists[rf]
            l1 = lists[rf + 1]

            while l0 is not None and l1 is not None:
                if l0.val < l1.val:
                    t.next = l0
                    l0 = l0.next
                else:
                    t.next = l1
                    l1 = l1.next
                t = t.next

            if l0 is not None:
                t.next = l0
            else:
                t.next = l1

            return head.next

        #len(lists) > 2
        return self.halfMerge([self.halfMerge(lists, rf, rf + size // 2), self.halfMerge(lists, rf + size // 2, rt)], 0, 2)



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
    
    def makeMultiLists(ls):
        ret = []
        for l in ls:
            ret.append(makeList(l))
        return ret
    
    def convertList(ln):
        n = ln
        ret = []
        while n is not None:
            ret.append(n.val)
            n = n.next
        return ret
    
    def convertMultiLists(ls):
        ret = []
        for ln in ls:
            ret.append(convertList(ln))
        return ret
    
    def printList(ln):
        print(convertList(ln))

    ll = [[0, 2, 4], [1, 2, 5], [7]]
    ll = [[0, 2], [1, 3]]
    ll = [ [1] ]
    ll = [ [1], [2], [3] ]
    ll = [[]]
    ll = [[1,4,5], [1,3,4], [2,6]]
    ls = makeMultiLists(ll)
    for l in ls:
        printList(l)
    s = Solution()
    bl = s.mergeKLists(ls)
    printList(bl)

                
