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

class binaryTree : 
    def __init__(self):
        self.size = 0;
	self.topNode = None;
    def insert(self, value) :
        if self.size == 0 :
	    self.topNode = node(value)
	    '''
	    impliment as you wish!
	    '''
        else : 
            currentNode = self.getNindex((self.size - 1)/2);
	    if self.size % 2 == 0 : 
	        currentNode.right = node(value, currentNode);
            else :
	        currentNode.left = node(value, currentNode);
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
        if currentNode == 0 : 
	    currentNode  = self.topNode;
	
	if currentNode.left != None : 
	    self.printAll(currentNode.left);
	
        print currentNode.data;

	if currentNode.right != None :
	    self.printAll(currentNode.right);
	return self;

    def swapNode(self, a, b):
        nodeA = self.getNindex(a);
	nodeB = self.getNindex(b);
	temp = nodeA.data;
	nodeA.data = nodeB.data;
	nodeB.data = temp;

    def delNode(self,n) : 
        if n == 0 : 
	    self.topNode = None;
	elif n%2 == 0 : 

	    nodeN = self.getNindex(n).parent;
	    nodeN.right = None;

	else :
	    nodeN = self.getNindex(n).parent;
	    nodeN.left = None;
        self.size = self.size - 1;
	return self;
            



bt = binaryTree();
bt.insert(0).insert(1).insert(2).insert(3).insert(4).insert(5).insert(6)

bt.delNode(5).printAll()
print "\n\n\n"
bt.insert(1).printAll()

