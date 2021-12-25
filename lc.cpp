#include "lc.h"

using namespace std;
using namespace lc;
ListNode* lc::CreateList(const std::string& inputStr)
{
	auto vec = CreateVector<int>(inputStr);
	size_t count = vec.size();
	ListNode* head, * curr;
	if (count == 0)return nullptr;
	head = new ListNode(vec[0]);
	curr = head;
	for (size_t i = 1; i < count; i++) {
		ListNode* temp = new ListNode(vec[i]);
		curr->next = temp;
		curr = temp;
	}
	return head;
}

void lc::DestroyList(ListNode* head)
{
	ListNode* curr = head;
	ListNode* temp = nullptr;
	while (curr != nullptr) {
		temp = curr;
		curr = curr->next;
		delete temp;
	}
}

//Level Order Traversal => tree
TreeNode* lc::CreateTree(const std::string& input)
{
	vector<int> vec = CreateVector<int>(input);
	size_t count = vec.size();
	vector<TreeNode*>treeArr(count);
	for (size_t i = 0; i < count; i++)
	{
		if (TREE_NODE_BOUNDNARY == vec[i]) {
			treeArr[i] = nullptr;
		}
		else {
			treeArr[i] = new TreeNode(vec[i]);	//Assign
		}
	}
	size_t curr = 1;
	for (size_t i = 0; i < count; i++)
	{
		if (!treeArr[i]) {
			continue;
		}
		if (curr < count) {
			treeArr[i]->left = treeArr[curr++];
		}
		if (curr < count) {
			treeArr[i]->right = treeArr[curr++];
		}
	}
	TreeNode* root = treeArr[0];
	return root;
}

void lc::DestroyTree(TreeNode* root)
{
	if (nullptr == root) {
		return;
	}
	delete root;
}

void lc::PrintTreeImpl(TreeNode* n, bool left, std::string const& indent)
{
	if (n->right) PrintTreeImpl(n->right, false, indent + (left ? "|     " : "      "));
	std::cout << indent;
	std::cout << (left ? '\\' : '/');
	std::cout << "-----";
	std::cout << n->val << std::endl;
	if (n->left) PrintTreeImpl(n->left, true, indent + (left ? "      " : "|     ")); 
}

void lc::PrintTree(TreeNode* root)
{
	if (root->right) PrintTreeImpl(root->right, false, " ");
	std::cout << root->val << '\n';
	if (root->left) PrintTreeImpl(root->left, true, " ");
}
