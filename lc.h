#ifndef LC
#define LC

#ifdef __GNUC__
#include <bits/stdc++.h>
#endif
#ifdef _MSC_VER
#include <__msvc_all_public_headers.hpp>
#endif
#include "pprint.h"
namespace lc
{

	struct ListNode
	{
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(nullptr) {}
	};

	const int32_t TREE_NODE_BOUNDNARY = INT_MIN + 1; // replace null
	struct TreeNode
	{
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
		~TreeNode() {
			if (left)	delete left;
			if (right)	delete right;
		}
	};

	template<typename T>
	std::vector<T> CreateVector(const std::string inputStr)
	{
		std::vector<T> ret;
		const std::string pattern = R"(([+|-]?\w*\.?[\w+|#|\.]),?)";
		std::smatch match;

		std::string log = inputStr;
		while (regex_search(log, match, (std::regex)pattern)) {
			std::stringstream ss;
			std::string treeNull = match.str(1) == "null" ? std::to_string(TREE_NODE_BOUNDNARY) : match.str(1);
			ss << treeNull;
			T temp;
			ss >> temp;
			ret.push_back(temp);
			log = match.suffix();
		}

		if (ret.empty()) {
			std::cout << "CreateVector failed." << std::endl;
		}

		return ret;
	}

	template<typename T>
	std::vector<std::vector<T>> CreateMatrix(const std::string inputStr)
	{
		std::vector<std::vector<T>> ret;
		const std::string pattern = R"((\[[^\[\]]*\]))";
		std::smatch match;

		std::string log = inputStr;
		while (regex_search(log, match, (std::regex)pattern)) {
			std::string vec = match.str(1);
			ret.push_back(CreateVector<T>(vec));
			log = match.suffix();
		}

		if (ret.empty()) {
			std::cout << "CreateVector failed." << std::endl;
		}
		return ret;
	}
	
	ListNode* CreateList(const std::string& inputStr);
	
	void DestroyList(ListNode* head);
	
	TreeNode* CreateTree(const std::string& input);
	
	void DestroyTree(TreeNode* root);

	void PrintTreeImpl(TreeNode* n, bool left, std::string const& indent);

	void PrintTree(TreeNode* root);
}
#endif 
