class Segment_tree:
    """Solution to Range sum problems"""
    def __init__(self,lst,size):
        self.tree = [0 for i in range(4*len(lst))]
        self.lazy = [0 for i in range(4*(len(lst)))]
        self.array = lst
    
    def build_tree(self,left,right,pos):
        if left == right:
            self.tree[pos] = self.array[left]
            return
        mid = left+(right-left)//2
        self.build_tree(left,mid,pos*2)
        self.build_tree(mid+1,right,pos*2+1)
        self.tree[pos] = self.tree[pos*2]+self.tree(pos*2+1)

    def push_down(self,left,right,pos):
        mid = left+(right-left)//2
        val = self.lazy[pos]
        self.tree[pos*2] += (mid-left+1)*val
        self.tree[pos*2+1] += (right-mid)*val
        self.lazy[pos*2] += val
        self.lazy[pos*2+1] += val
        self.lazy[pos] = 0
    
    def range_query(self,left,right,pos,ql,qr):
        if ql<=left and right<=qr:
            return self.tree[pos]
        self.push_down(left,right,pos)
        result = 0
        mid = left+(right-left)//2
        if ql<=mid:
            result += self.range_query(left,mid,pos*2,ql,qr)
        if mid<qr:
            result += self.range_query(mid+1,right,pos*2+1,ql,qr)
        return result
    
    def range_modify(self,left,right,pos,ql,qr,val):
        """[l,r]increasing value of 'val'"""
        if ql<=left and right<=qr:
            self.tree[pos] += (right-left+1)*val
            self.lazy[pos] += val
            return
        self.push_down(left,right,pos)
        mid = left+(right-left)//2
        if ql<=mid:
            self.range_modify(left,mid,pos*2,ql,qr,val)
        if mid<qr:
            self.range_modify(mid+1,right,pos*2+1,ql,qr,val)
        self.tree[pos] = self.tree[pos*2]+self.tree(pos*2+1)

print("seg")
