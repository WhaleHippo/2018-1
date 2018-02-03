class node :
	def __init__(self, data = None, pre = None, next = None):
		self.data = data;
		self.pre = pre;
		self.next = next;

class linkedList :
	def __init__(self) :
		self.start = node();
		self.end = node();
		self.start.pre = self.start;
		self.start.next = self.end;
		self.end.pre = self.start;
		self.size = 0;

	
	def getNindex(self, n) :
		if n >= self.size : 
			return self.end.pre;
		else : 
			currentnode = self.start;

		for i in range(n+1) : 
			currentnode = currentnode.next;
		
		return currentnode;
		
	def insert(self, value, n = -1) : 
		if self.size == 0 : 
			newNode = node(value, self.start, self.end);
			self.start.next = newNode;
			self.end.pre = newNode;
		else : 
			if n == -1 : #insert last place
				newNode = node(value, self.end.pre, self.end); 
				self.end.pre.next = newNode;
				self.end.pre = newNode;

			else :
				nextNode = self.getNindex(n);
				if n >= self.size : 
				    nextNode = self.end;
				preNode = nextNode.pre;
				newNode = node(value, preNode, nextNode);
				preNode.next = newNode;
				nextNode.pre = newNode;
	
		self.size = self.size + 1;
	def delete(self, n = -1) : 
		if n == -1 : 
			delNode = self.end.pre;
			self.end.pre.pre.next = self.end;
			self.end.pre = self.end.pre.pre
		else : 
			delNode = self.getNindex(n);
			delNode.pre.next = delNode.next;
			delNode.next.pre = delNode.pre;

	def printall(self, direction = True) :
		if direction : 
			currentnode = self.start.next;
			
			while currentnode != self.end : 
				print currentnode.data, 
				currentnode = currentnode.next;
		else :
			currentnode = self.end.pre;
			
			while currentnode != self.start : 
				print currentnode.data, 
				currentnode = currentnode.pre;
		
		print ""
	def swap(self, a, b) : 
		nodeA = self.getNindex(a);
		nodeB = self.getNindex(b);

		temp = nodeA.data;
		nodeA.data = nodeB.data;
		nodeB.data = temp;


ll = linkedList();
ll.insert(1);
ll.insert(2);
ll.insert(3);
ll.insert(4);
ll.insert(5);
ll.printall(True)
ll.printall(False)

print ""
ll.swap(0,66666)
ll.printall(True)
ll.printall(False)
