#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;

struct node {
	int data;
	node *left, *right;
public:
	node(int d) {data = d; left=right= NULL;}
};

void print_levelordered(node *root)
{
	queue<node *> q;

	node *temp = NULL;

	if(!root)
		return;

	cout<<"==== Level Ordered ===="<<endl;
	q.push(root);

	while(!q.empty()) {
		int count = q.size();
		while(count--) {
			temp = q.front();
			q.pop();

			cout<<temp->data<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		cout<<endl;
	}
	cout<<"#### Level Ordered ####"<<endl;
}

void print_spiral(node *root)
{
	stack<node *> s1;
	stack<node *> s2;

	if(!root)
		return;

	cout<<"======== SPIRAL =========="<<endl;
	s1.push(root);

	while(!s1.empty() || !s2.empty()) {

		while(!s1.empty()) {
			root = s1.top();
			s1.pop();

			cout<<root->data<<" ";
			if(root->right)
				s2.push(root->right);
			if(root->left)
				s2.push(root->left);
		}
		cout<<endl;
		while(!s2.empty()) {
			root = s2.top();
			s2.pop();

			cout<<root->data<<" ";

			if(root->left)
				s1.push(root->left);
			if(root->right)
				s1.push(root->right);
		}
		cout<<endl;

	}
	cout<<"######## SPIRAL ###########"<<endl;
}

void printInorder(node *root)
{
	stack<node *> s;
	node *current = root;
	node *temp = NULL;

	cout<<"=== Inorder ==="<<endl;
	while(current || !s.empty()) {

		// left sub tree
		while(current) {
			s.push(current);
			current = current->left;
		}

		// visit root
		if(!s.empty()) {
			temp = s.top();
			s.pop();
			cout<<temp->data<<" ";
			current = temp->right;
		}
	}
	cout<<endl;

}

//Morris traversal
void printInOrderWOStack(node *root)
{
	node *current = root;

	cout<<"=== Inorder WO stack/recursion ==="<<endl;

	while(current) {
		if(!current->left) {
			cout<<current->data<<" ";
			current = current->right;
		}
		else {
			// find inOrder predecessor
			node *pre = current->left;
			while(pre->right && pre->right != current)
				pre= pre->right;
			if(!pre->right) {
				pre->right = current;
				current = current->left;
			}
			else {
				//Repair
				pre->right = NULL;
				cout<<current->data<<" ";
				current = current->right;
			}
		}
	}
	cout<<endl;
}

int size(node *root)
{
	if(!root)
		return 0;
	return size(root->left) + 1 + size(root->right);
}

bool isIdentical(node *r1, node *r2)
{
	if(!r1 && !r2)
		return true;
	if(!r1 || !r2)
		return false;

	return ((r1->data == r2->data) && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right));
}

int height(node *root)
{
	if(!root)
		return 0;

	return max(height(root->left), height(root->right)) + 1;
}

void delete_tree(node **root)
{
	if(!*root)
		return;

	delete_tree(&(*root)->left);
	delete_tree(&(*root)->right);

	delete *root;
	*root = NULL;
}

void mirror(node *root)
{
	if(!root)
		return;

	mirror(root->left);
	mirror(root->right);

	swap(root->left,root->right);
}

void print_pathRecur(node *root, string path)
{
	if(!root)
		return;
	ostringstream ss;
	ss<<root->data;
	path += ss.str();
	path += " ";
	if(!root->left && !root->right)
		cout<<path<<endl;
	print_pathRecur(root->left, path);
	print_pathRecur(root->right, path);
}

void print_paths(node *root)
{
	string path;
	std::cout<<"=================="<<endl;
	print_pathRecur(root, path);
	std::cout<<"=================="<<endl;
}

int getCountLeaves(node *root)
{
	if(!root)
		return 0;
	if(!root->left && !root->right)
		return 1;
	return getCountLeaves(root->left) + getCountLeaves(root->right);
}

bool isSumProperty(node *root)
{
	if(!root ||(!root->left && !root->right))
		return true;
	else {
		int ldata = 0;
		int rdata = 0;

		if(root->left)
			ldata = root->left->data;
		if(root->right)
			rdata = root->right->data;

		return ((root->data == ldata + rdata) && isSumProperty(root->left) && isSumProperty(root->right));
	}
}

void incrementSPT(node *root, int val)
{
	if(!root)
		return;
	if(root->left) {
		root->left->data += val;
		incrementSPT(root->left, val);
	}
	else if(root->right) {
		root->right->data += val;
		incrementSPT(root->right, val);
	}
}

void convertSumPropertyTree(node *root)
{
	if(!root || (!root->left && !root->right))
		return;
	else {
		int ldata = 0, rdata=0, diff;
		convertSumPropertyTree(root->left);
		convertSumPropertyTree(root->right);

		if(root->left)
			ldata = root->left->data;
		if(root->right)
			rdata = root->right->data;

		diff = ldata + rdata - root->data;
		if(diff>0)
			root->data += diff;

		if(diff<0)
			incrementSPT(root, -diff);
	}
}

int diameterUtil(node *root, int &height)
{
	if(!root) {
		height = 0;
		return 0;
	}

	int lh, rh;
	int ld = diameterUtil(root->left, lh);
	int rd = diameterUtil(root->right, rh);

	height = 1 + max(lh, rh);

	return max(1+lh+rh, max(ld,rd));

}

int diameter(node *root)
{
	int h = 0;
	return diameterUtil(root, h);
}

bool isHBalancedUtil(node *root, int &h)
{
	if(!root) {
		h = 0;
		return true;
	}

	int lh, rh;

	if(!isHBalancedUtil(root->left, lh))
		return false;
	if(!isHBalancedUtil(root->right, rh))
		return false;
	h= max(lh,rh) +1;

	if(lh>=rh)
		return lh-rh <=1;
	else
		return rh-lh <=1;
}

bool isheightbalanced(node *root)
{
	int height = 0;

	return isHBalancedUtil(root, height);
}

bool hasPathSum(node *root, int sum)
{
	if(!root)
		return sum == 0;
	else {
		sum -= root->data;
		if(sum == 0 && !root->left && !root->right)
			return true;


		return hasPathSum(root->left,sum) || hasPathSum(root->right, sum);
	}
}

node *buildTree(int in[], int pre[], int &preId, int start , int end, int sz)
{
	if(start > end)
		return NULL;
	node *temp = new node(pre[preId]);
	preId++;

	if(preId<sz) {
		int i = start;
		while(in[i]!= temp->data)
			i++;
		temp->left = buildTree(in, pre, preId, start, i-1, sz);
		if(preId<sz)
			temp->right = buildTree(in, pre, preId, i+1, end, sz);
	}
	return temp;
}

node *doubleTree(node* root)
{
	if(!root)
		return NULL;

	root->left = doubleTree(root->left);
	node *child = new node(root->data);
	child->left = root->left;
	root->left = child;
	root->right = doubleTree(root->right);

	return root;
}

bool isFoldableUtil(node *r1, node *r2)
{
	if(!r1 && !r2)
		return true;
	if(!r1 || !r2)
		return false;
	return isFoldableUtil(r1->left, r2->right) && isFoldableUtil(r1->right, r2->left);
}

bool isFoldable(node *root)
{
	if(!root)
		return true;
	return isFoldableUtil(root->left, root->right);
}

void printkDistanceNodes(node *root, int k)
{
	if(!root)
		return;
	if(k==0)
		cout<<root->data<<" ";
	else {
		printkDistanceNodes(root->left, k-1);
		printkDistanceNodes(root->right, k-1);
	}
}

struct tnode {
	int data;
	tnode *left, *right, *next;
public:
	tnode(int d) {data = d; left=right= next = NULL;}
};

tnode * getLeftmostChild(tnode *p)
{
	while(p) {
		if(p->left)
			return p->left;
		else if(p->right)
			return p->right;
		else
			p=p->next;
	}
	return NULL;
}

void connectNext(tnode *root)
{
	if(!root)
		return;

	root->next = NULL;
	while(root) {
		tnode *q = root;
		while(q) {
			if(q->left) {
				q->left->next = (q->right)? q->right:getLeftmostChild(q->next);
			}
			if(q->right) {
				q->right->next = getLeftmostChild(q->next);
			}
			q=q->next;
		}
		if(root->left)
			root=root->left;
		else if(root->right)
			root=root->right;
		else
			root= getLeftmostChild(root->next);
	}
}

void print_tnode_tree(tnode *root)
{
	if(!root)
		return;
	cout<<"=================================="<<endl;
	while(root) {
		tnode *q = root;
		while(q) {
			cout<<q->data<<" ";
			q=q->next;
		}
		cout<<endl;
		root = getLeftmostChild(root);
	}
	cout<<"=================================="<<endl;
}

node *buildLNTree(int pre[], char preLN[], int &preId, int n)
{
	if(preId == n)
		return NULL;

	node *root = new node(pre[preId]);
	int i = preId;
	preId++;

	if(preLN[i] == 'N') {
		root->left = buildLNTree(pre, preLN, preId, n);
		root->right = buildLNTree(pre, preLN, preId, n);
	}
	return root;
}

void printLeaves(node *root)
{
	if(root) {
		printLeaves(root->left);
		if(!root->left && !root->right)
			cout<<root->data<<" ";
		printLeaves(root->right);
	}
}

void printLeftBoundary(node *root)
{
	if(root) {
		if(root->left) {
			cout<<root->data<<" ";
			printLeftBoundary(root->left);
		}
		else if(root->right) {
			cout<<root->data<<" ";
			printLeftBoundary(root->right);
		}
		//else do nothing for leaf nodes
	}
}

void printRightBoundary(node *root)
{
	if(root) {
		if(root->right) {
			printRightBoundary(root->right);
			cout<<root->data<<" ";
		}
		else if(root->left) {
			printLeftBoundary(root->left);
			cout<<root->data<<" ";
		}
		//else do nothing for leaf nodes
	}
}

void printBoundary(node *root)
{
	if(root) {
		cout<<"=== Boundary ===="<<endl;
		cout<<root->data<<" ";
		printLeftBoundary(root->left);
		printLeaves(root->left);
		printLeaves(root->right);
		printRightBoundary(root->right);
		cout<<"### Boundary ####"<<endl;
	}
}

/* Contruct Full binary tree from pre and post order traversal */

node * constructFullTreeUtil(int pre[], int post[], int &preId, int l, int h, int sz)
{

	if(preId >= sz || !sz || l > h)
		return NULL;

	/* next elem in pre[] is the roor node */
	node *root = new node(pre[preId]);
	preId++;

	if(l==h)
		return root;

	int i;
	// Find next pre element in post[]
	for(i=l;i<h;i++)
		if(pre[preId]==post[i])
			break;

	if(i<=h) {
		// left subtree post[l...i]
		root->left = constructFullTreeUtil(pre, post ,preId, l, i, sz);

		// right subtree post[i+1 ... h]
		root->right = constructFullTreeUtil(pre, post ,preId, i+1, h-1, sz);
	}

	return root;
}

node *constructFullTree(int pre[] , int post[], int sz)
{
	int preId = 0;

	return constructFullTreeUtil(pre, post, preId, 0, sz-1, sz);
}

void preOrderIterative(node *root)
{
	stack<node *> s;

	cout<<"+++ PreOrder +++"<<endl;

	while(root || !s.empty()) {
		while(root) {
			cout<<root->data<<" ";
			s.push(root);
			root = root->left;
		}

		if(!s.empty()) {
			root = s.top();
			s.pop();
			root = root->right;
		}
	}

	cout<<"++++++++++++"<<endl;
}

void postOrderIter2Stack(node *root)
{
	stack<node *> s1;
	stack<node *> s2;

	if(!root)
		return;

	s1.push(root);

	while(!s1.empty()) {
		root = s1.top();
		s1.pop();
		s2.push(root);

		if(root->left)
			s1.push(root->left);
		if(root->right)
			s1.push(root->right);
	}
	cout<<"==== Post Order 2 stack ====="<<endl;

	while(!s2.empty()) {
		cout<<s2.top()->data<<" ";
		s2.pop();
	}
	cout<<"###############"<<endl;
}

void postOrderIter1Stack(node *root)
{
	stack<node *> s;

	cout<<"==== Post Order 1 stack ====="<<endl;

	while(root || !s.empty()) {

		while(root) {
			if(root->right)
				s.push(root->right);
			s.push(root);
			root = root->left;
		}

		if(!s.empty()) {
			root = s.top();
			s.pop();

			// Traverse right sub tree first
			// if left subtree traversal is done
			if(!s.empty() && root->right == s.top()) {
				s.pop();
				s.push(root);
				root = root->right;
			}
			else {
				cout<<root->data<<" ";
				root = NULL;
			}
		}
	}
	cout<<"###############"<<endl;
}

struct lnode {
	int data;
	lnode *next;
	lnode(int d) {data = d; next = NULL;}
};

node *buildCompleteBinTree(lnode *head)
{
	queue<node *> q;

	if(!head)
		return NULL;

	node * root = new node(head->data);
	head = head->next;
	q.push(root);

	while(head) {
		node *p = q.front();
		q.pop();

		p->left = new node(head->data);
		head = head->next;
		q.push(p->left);

		if(head) {
			p->right = new node(head->data);
			head = head->next;
			q.push(p->right);
		}
	}

	return root;
}

node *bin2dllUtil(node *root)
{
	if(!root)
		return root;
	if(root->left) {
		node * left = bin2dllUtil(root->left);

		// find inorder predecessor of root
		while(left->right)
			left = left->right;
		left->right = root;
		root->left = left;
	}
	if(root->right) {
		node *right = bin2dllUtil(root->right);

		// find inorder successor of root
		while(right->left)
			right = right->left;
		root->right = right;
		right->left = root;
	}
	return root;
}

node *bin2dll(node *root)
{
	if(root) {
		root = bin2dllUtil(root);
		while(root->left)
			root = root->left;
	}
	return root;
}

void fixPrevPtr(node *root, node **pre)
{
	if(root) {
		fixPrevPtr(root->left, pre);
		root->left = *pre;
		*pre = root;
		fixPrevPtr(root->right,pre);
	}
}

node * fixNextPtr(node *root)
{
	if(!root)
		return root;
	while(root->right)
		root = root->right;

	node *next = NULL;
	while(root->left) {
		next = root;
		root = root->left;
		root->right = next;
	}
	return root;
}

node * bin2dll2(node *root)
{
	node *pre = NULL;
	fixPrevPtr(root, &pre);
	return fixNextPtr(root);
}

void printDll(node *root)
{
	cout<<"==== Dll==="<<endl;
	while(root) {
		cout<<root->data<<" ";
		root= root->right;
	}
	cout<<"##########"<<endl;
}

void printAncestors(node *root, int key)
{
	stack<node *> s;

	cout<<"==== printAncestors : key :"<<key<<"=== "<<endl;
	while(root || !s.empty()) {

		// proceed in left subtree
		while(root && root->data != key) {
			s.push(root);
			root= root->left;
		}

		if(root && root->data == key)
			break;
		// if rightmost node then pop all nodes which has this node in its right subtree
		if(s.top()->right == NULL) {
			root = s.top();
			s.pop();

			while(!s.empty() && s.top()->right == root) {
				root = s.top();
				s.pop();
			}
		}

		// process in right subtree keeping the parent in the stack
		root = s.empty()? NULL: s.top()->right;
	}


	while(!s.empty()) {
		cout<<s.top()->data<<" ";
		s.pop();
	}
	cout<<"############"<<endl;
}

void leftViewUtil(node *root, int level, int *max_level)
{
	if(!root)
		return;

	if(*max_level < level) {
		*max_level = level;
		cout<<root->data<<" ";
	}

	leftViewUtil(root->left, level+1, max_level);
	leftViewUtil(root->right, level+1, max_level);
}

void leftView(node *root)
{
	int max_level = 0;

	cout<<"=== Left View ==="<<endl;
	leftViewUtil(root, 1, &max_level);
	cout<<"#################"<<endl;
}

struct map_node {
	node *t;
	int hd;
	map_node(node *root, int d) {t=root; hd = d;}
};

void printBottomView(node *root)
{
	if(!root)
		return;
	queue<map_node *> q;
	map<int , int> m;
	map_node *temp;

	q.push(new map_node(root, 0));

	while(!q.empty()) {
		temp = q.front();
		q.pop();

		root = temp->t;
		m[temp->hd] = root->data;

		if(root->left)
			q.push(new map_node(root->left, temp->hd-1));
		if(root->right)
			q.push(new map_node(root->right, temp->hd+1));
		delete temp;
	}

	cout<<"=== BottomView ===="<<endl;
	for(map<int,int>::iterator i = m.begin(); i!= m.end();i++) {
		cout<<i->second<<" ";
	}
	cout<<"##################"<<endl;
}

void convertLR(node *root)
{
	if(!root)
		return;

	convertLR(root->left);
	convertLR(root->right);

	if(root->left)
		root->left->right = root->right;
	else
		root->left = root->right;

	root->right = NULL;
}

void downrightTraversal(node *root)
{
	if(root) {
		cout<<root->data<<" ";
		downrightTraversal(root->right);
		downrightTraversal(root->left);
	}
}

node *removeHalfNodes(node *root)
{
	node *temp;
	if(!root)
		return root;
	if(!root->left && !root->right)
		return root;

	root->left = removeHalfNodes(root->left);
	root->right = removeHalfNodes(root->right);

	if(!root->left) {
		temp = root->right;
		delete root;
		return temp;
	}

	if(!root->right) {
		temp = root->left;
		delete root;
		return temp;
	}
	return root;
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);
    root1->right->right = new node(6);


    print_levelordered(root1);
    printInorder(root1);

    printInOrderWOStack(root1);
    printInorder(root1);

    cout<<"Size = "<<size(root1)<<endl;
    cout<<"height = "<<height(root1)<<endl;

    node *root2 = new node(1);
	root2->left = new node(2);
	root2->right = new node(3);
	root2->left->left = new node(4);
	root2->left->right = new node(5);
	root2->right->right = new node(6);

	cout<<"Identical T1 T2 = "<<isIdentical(root1,root2)<<endl;
    node *root3 = new node(1);
	root3->left = new node(2);
	root3->right = new node(3);
	root3->left->left = new node(4);
	root3->left->right = new node(5);
	root3->right->right = new node(7);

	cout<<"Identical T1 T3 = "<<isIdentical(root1,root3)<<endl;

	print_levelordered(root3);
	delete_tree(&root3->left);
	print_levelordered(root3);

	print_levelordered(root1);
	mirror(root1);
	print_levelordered(root1);


	print_paths(root1);

	cout<<"Leaves : "<<getCountLeaves(root1)<<endl;
	print_levelordered(root1);
	print_spiral(root1);

	cout<<"SumPoroperty = "<<isSumProperty(root1)<<endl;

	node *root4 = new node(10);
	root4->left = new node(8);
	root4->right = new node(2);
	root4->left->left = new node(3);
	root4->left->right = new node(5);
	root4->right->left = new node(2);

	cout<<"SumPoroperty = "<<isSumProperty(root4)<<endl;
	print_levelordered(root1);
	convertSumPropertyTree(root1);
	print_levelordered(root1);

	print_levelordered(root4);
	convertSumPropertyTree(root4);
	print_levelordered(root4);

	node *root5 = new node(50);
	root5->left = new node(7);
	root5->right = new node(2);
	root5->left->left = new node(3);
	root5->left->right = new node(5);
	root5->right->left = new node(1);
	root5->right->right = new node(30);

	print_levelordered(root5);
	cout<<"SumPoroperty = "<<isSumProperty(root5)<<endl;
	convertSumPropertyTree(root5);
	print_levelordered(root5);

	cout<<"Diameter = "<<diameter(root1)<<endl;
	cout<<"isheightbalanced = "<<isheightbalanced(root1)<<endl;
	print_levelordered(root3);
	cout<<"isheightbalanced = "<<isheightbalanced(root3)<<endl;

	print_levelordered(root2);
	int sum[] = {7,8,9,10};
	cout<<"sum = "<<sum[0]<<" hasPathSum = "<<hasPathSum(root2, sum[0])<<endl;
	cout<<"sum = "<<sum[1]<<" hasPathSum = "<<hasPathSum(root2, sum[1])<<endl;
	cout<<"sum = "<<sum[2]<<" hasPathSum = "<<hasPathSum(root2, sum[2])<<endl;
	cout<<"sum = "<<sum[3]<<" hasPathSum = "<<hasPathSum(root2, sum[3])<<endl;

	int in[] = {4,2,5,1,6,3};
	int pre[] = {1,2,4,5,3,6};
	int i=0;
	int n = sizeof(in)/sizeof(in[0]);
	node *root6 = buildTree(in, pre, i, 0, n-1, n);
	print_levelordered(root6);

	doubleTree(root6);
	print_levelordered(root6);

	print_levelordered(root1);
	cout<<"isFoldable = "<<isFoldable(root1)<<endl;

	node *root7 = new node(10);
	root7->left = new node(7);
	root7->right = new node(15);
	root7->left->right = new node(9);
	root7->right->left = new node(11);

	print_levelordered(root7);
	cout<<"isFoldable = "<<isFoldable(root7)<<endl;

	print_levelordered(root2);
	for(i = 0; i < 3;i++) {
		cout<<"k = "<<i<<endl;
		printkDistanceNodes(root2,i);
		cout<<endl;
	}

	tnode *root8 = new tnode(10);
	root8->left = new tnode(7);
	root8->right = new tnode(15);
	root8->left->right = new tnode(9);
	root8->right->left = new tnode(11);

	connectNext(root8);
	print_tnode_tree(root8);

	int test_pre[] = {10,30,20,5,15};
	char test_preLN[] = {'N', 'N', 'L', 'L', 'L'};
	int test_preId= 0;

	node *res = buildLNTree(test_pre, test_preLN, test_preId, sizeof(test_pre)/sizeof(test_pre[0]));
	print_levelordered(res);
	printBoundary(res);


	print_levelordered(root2);
	printBoundary(root2);

	int fpre[] = {1,2,4,8,9,5,3,6,7};
	int fpost[] = {8,9,4,5,2,6,7,3,1};

	node *root9 = constructFullTree(fpre,fpost, sizeof(fpre)/sizeof(fpre[0]));
	print_levelordered(root9);
	preOrderIterative(root9);

	postOrderIter2Stack(root9);

	postOrderIter1Stack(root9);

	lnode *head = new lnode(10);
	head->next = new lnode(12);
	head->next->next = new lnode(15);
	head->next->next->next = new lnode(25);
	head->next->next ->next->next = new lnode(30);
	head->next->next ->next->next->next = new lnode(36);

	node *root10 = buildCompleteBinTree(head);
	print_levelordered(root10);


	root10 = bin2dll(root10);
	printDll(root10);

	root10 = buildCompleteBinTree(head);
	print_levelordered(root10);
	root10 = bin2dll2(root10);
	printDll(root10);

	node *root11 = new node(1);
	root11->left = new node(2);
	root11->right = new node(3);
	root11->left->right = new node(4);
	root11->left->right->right = new node(5);
	root11->left->right->right->left = new node(6);
	root11->right->right = new node(7);

	printAncestors(root11, 6);
	printAncestors(root11, 7);

	leftView(root11);

	printBottomView(root11);

	print_levelordered(root11);

	convertLR(root11);

	cout<<"===== down Right traversal ==="<<endl;
	downrightTraversal(root11);
	cout<<"##############"<<endl;

	node *root12 = new node(1);
	root12->left = new node(2);
	root12->right = new node(3);
	root12->left->right = new node(4);
	root12->left->right->right = new node(5);
	root12->left->right->right->left = new node(6);
	root12->right->right = new node(7);

	print_levelordered(root12);
	root12 = removeHalfNodes(root12);
	print_levelordered(root12);

    return 0;
}
