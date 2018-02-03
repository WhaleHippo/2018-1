class node :
    def __init__(self, data, parent = None, left = None, right = None):
        if isinstance(data, node):
	    self.data = data.data;
	    self.parent = data.parent;
	    self.left = data.left;
	    self.right = data.right;
	else :
            self.data = data;
	    self.parent = parent;
            self.left = left;
            self.right = right;
    '''
    def __str__(self):
        return str(self.data);
    '''

class maxHeap : 
    def __init__(self):
        self.size = 0;
	self.topNode = None;

    def insert(self, value) :
        if self.size == 0 :
	    self.topNode = node(value)
	    self.topNode.parent = node(999999999)
        else : 
            currentNode = self.getNindex((self.size - 1)/2);
	    if self.size % 2 == 0 : 
	        currentNode.right = node(value, currentNode);
            else :
	        currentNode.left = node(value, currentNode);
	    n = self.size;
	    currentNode = self.getNindex(n)
	    while currentNode.data > currentNode.parent.data :
	        self.swapNode(n,(n - 1)/2);
	        n = (n - 1)/2
	        currentNode = self.getNindex(n)
	self.size = self.size + 1;
	return self;
    
    def getNindex(self, n) :
        if n == 0:
	    return self.topNode;
	else :
	    parentNode = self.getNindex((n-1)/2);
	    if n%2 == 1:
	        return parentNode.left;
	    else :
	        return parentNode.right;

    def printAll(self, currentNode = 0) :
        for i in range(self.size):
            print self.getNindex(i).data;
	return self;

    def swapNode(self, a, b):
        nodeA = self.getNindex(a);
	nodeB = self.getNindex(b);
	temp = nodeA.data;
	nodeA.data = nodeB.data;
	nodeB.data = temp;

    def delNode(self) : 
        if self.size == 0 :
            delData = "heap is empty!"
            return delData;
        elif self.size == 1 : 
	    delData = self.topNode.data;
	    self.topNode = None;
	else :
	    #swap 1st(=topNode) and last node
	    delData = self.topNode.data;
	    self.swapNode(0, self.size-1);
	    parentNode = self.getNindex(self.size-1).parent;
	    if (self.size-1)%2 == 1:
	        parentNode.left = None;
	    else :
	        parentNode.right = None;
	    
	    #Rebalancing
	    currentNode = self.topNode;
	    currentNode = 0;
	    #문제 찾았는데 결국은 none halder문제임 ㅅㅂ
	    while True:
	        if (currentNode.left.data < currentNode.data) and (currentNode.right.data < currentNode.data) :
	            break;
	        else : 
	            if currentNode.left.data < currentNode.right.data : 
	                currentNode = currentNode.right;
	                self.swapNode(currentNode,currentNode*2 + 2)
	                currentNode = currentNode*2 + 2;
	                
	    
	    
        self.size = self.size - 1;
	return delData;
	
mh = maxHeap();
mh.insert(1).insert(2).insert(1).insert(2).insert(1).insert(2).insert(1).insert(2).insert(1).insert(2)
mh.delNode()
mh.delNode()
mh.delNode()
mh.delNode()
mh.delNode()
mh.delNode()
mh.delNode()
mh.delNode()
